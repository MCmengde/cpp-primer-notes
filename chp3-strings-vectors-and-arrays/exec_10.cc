#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string s, result;
    cin >> s;

    for (auto &c : s) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    cout << result << endl;
    return 0;
}