
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isEmpty(const string& line) {
    for (unsigned char c : line) {
        if (!isspace(c)) {
            return false;
        }
    }
    return true;
}

string trim(const string& line) {
    size_t start = line.find_first_not_of(" \t\r\n\v\f");

    if (start == string::npos) {
        return "";
    }

    size_t end = line.find_last_not_of(" \t\r\n\v\f");

    return line.substr(start, end - start + 1);
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        cerr << "Usage: " << argv[0]
             << " input.txt output.txt [--trim]" << endl;
        return 1;
    }

    bool useTrim = false;

    if (argc == 4) {
        if (string(argv[3]) != "--trim") {
            cerr << "Error: unknown option" << endl;
            return 1;
        }
        useTrim = true;
    }

    if (string(argv[1]) == string(argv[2])) {
        cerr << "Error: input and output must be different"
             << endl;
        return 1;
    }

    ifstream input(argv[1]);

    if (!input.is_open()) {
        cerr << "Error: cannot open input file" << endl;
        return 1;
    }

    ofstream output(argv[2]);

    if (!output.is_open()) {
        cerr << "Error: cannot create output file" << endl;
        return 1;
    }

    string line;
    int removed = 0;
    int saved = 0;

    while (getline(input, line)) {
        if (isEmpty(line)) {
            removed++;
            continue;
        }

        if (useTrim) {
            line = trim(line);
        }

        output << line << '\n';
        saved++;
    }

    if (input.bad() || !output) {
        cerr << "Error: file processing failed" << endl;
        return 1;
    }

    output.close();

    if (!output) {
        cerr << "Error: cannot finish writing file" << endl;
        return 1;
    }

    input.close();

    cout << "Processing completed!" << endl;
    cout << "Saved lines: " << saved << endl;
    cout << "Removed empty lines: " << removed << endl;

    return 0;
}
