
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0);

    cout << "Student: Melnychuk Mariia" << endl;
    cout << "Current date and time: " << ctime(&now);

    return 0;
}
