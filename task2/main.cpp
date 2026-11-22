
#include <iostream>
#include <string>
#include "print_up.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: ./program text" << endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print_up(argv[i]);
    }

    return 0;
}
