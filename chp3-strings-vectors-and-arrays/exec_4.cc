#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << "The strings are equals." << endl;
    } else if (s1 < s2) {
        cout << "The second string is larger then the first one." << endl;
    } else {
        cout << "The first string is less then the second one." << endl;
    }

    if (s1.size() == s2.size()) {
        cout << "The strings have the same length." << endl;
    } else if (s1.size() > s2.size()) {
        cout << "The first string is longer than the second one." << endl;
    } else {
        cout << "The second string is longer than the first one." << endl;
    }

    return 0;
}