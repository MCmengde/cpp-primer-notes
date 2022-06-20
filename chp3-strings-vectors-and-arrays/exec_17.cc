#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> svec;
    string s;
    while (cin >> s) {
        svec.push_back(s);
    }

    for (auto &s : svec) {
        for (auto &c : s) {
            c = toupper(c);
        }
    }
    int counter = 0;
    for (auto s: svec) {
        cout << s << " ";
        ++counter;
        if (counter % 8 == 0) {
            cout << endl;
            counter = 0;
        }
    }
    return 0;
}