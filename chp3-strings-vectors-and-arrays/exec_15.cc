#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::vector;
using std::string;

int main() {
    vector<string> svec;
    string s;
    while (cin >> s) {
        svec.push_back(s);
    }

    return 0;
}