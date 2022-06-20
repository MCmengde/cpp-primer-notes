#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string s, rst;

    while (cin >> s) {
        rst += s + " ";
    }
    cout << rst << endl;
    return 0;
}