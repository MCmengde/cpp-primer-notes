#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string rst_str;
    int rst_cnt = 0;

    string current_str, pre_str = "";
    int current_cnt = 1;
    while (cin >> current_str) {
        if (current_str == pre_str) {
            ++current_cnt;
        } else {
            current_cnt = 1;
            pre_str = current_str;
        }
        if (rst_cnt <= current_cnt) {
            rst_cnt = current_cnt;
            rst_str = current_str;
        }
    }

    cout << rst_str << " duplicated :" << rst_cnt << endl;

    return 0;
}