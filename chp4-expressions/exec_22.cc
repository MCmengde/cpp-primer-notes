#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
    unsigned grade;
    cin >> grade;
    string rst;

    // version 1
    rst = (grade > 90) ? "high pass"
                        : (grade > 75) ? "pass"
                        : (grade > 60) ? "low pass"
                        : "fail";
    
    cout << " version 1:" << rst << endl;

    // version 2
    if (grade > 90) {
        rst = "high pass";
    } else if (grade > 75) {
        rst = "pass";
    } else if (grade > 60) {
        rst = "low pass";
    } else {
        rst = "fail";
    }

    cout << " version 2:" << rst << endl;
    return 0;
}