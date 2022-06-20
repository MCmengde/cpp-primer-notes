#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    vector<int (*)(int, int)> v{add, subtract, multiply, divide};

    for (auto f : v) {
        cout << f(2, 2) << endl;
    }
}