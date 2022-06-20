#include <iostream>

using std::cout;
using std::endl;

void f() { cout << "f()" << endl; }

void f(int i) { cout << "f(int i) " << i << endl; }

void f(int v1, int v2) {
    cout << "f(int v1, int v2) " << v1 << " " << v2 << endl;
}

void f(double v1, double v2 = 3.14) {
    cout << "f(double v1, double v2) " << v1 << " " << v2 << endl;
}

int main() {
    // ambiguous
    // f(2.56, 42);

    // best match: void f(int);
    f(42);

    // best match: void f(int, int);
    f(42, 0);

    // best match: void f(double, double = 3.14);
    f(2.56, 3.15);

    return 0;
}