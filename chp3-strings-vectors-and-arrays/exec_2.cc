#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string in;
    
    // Read the standard input a line at a time.
    // while (getline(cin, in)) {
    //     cout << in << endl;
    // } 

    // Read a word at a time.
    while (cin >> in) {
        cout << in << endl;
    }
    
    return 0;
}