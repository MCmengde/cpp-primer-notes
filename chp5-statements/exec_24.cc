#include<iostream>
#include<stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::exception;

int main() {
    int a, b, rst;
    cin >> a >> b;
    if (b == 0) {
        exception e;
        throw e;
    }
    cout << a / b << endl;
    return 0;
}