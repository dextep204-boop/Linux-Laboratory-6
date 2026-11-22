
#include <iostream>
#include <cctype>
#include "print_up.h"
using namespace std;

void print_up(string text) {
    for (unsigned char c : text) {
        cout << (char)toupper(c);
    }
    cout << endl;
}
