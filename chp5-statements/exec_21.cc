#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string cur_str, pre_str = "\0";
    bool flag = false;
    while (cin >> cur_str) {
        if (isupper(cur_str[0]) && cur_str == pre_str) {
            cout << cur_str << " occurs twice." << endl;
            flag = true;
            break;
        }
        pre_str = cur_str;
    }
    if (!flag) {
        cout << "No word was repeated." << endl;
    }
    return 0;
}