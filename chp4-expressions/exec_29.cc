#include<iostream>

using std::cout;
using std::endl;

int main() {
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;  // 10
    cout << sizeof(p) / sizeof(*p) << endl;  // 1
    return 0;
}