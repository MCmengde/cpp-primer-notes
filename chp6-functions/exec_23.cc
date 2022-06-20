#include <iostream>

using std::cout;
using std::endl;

void print(const int *p, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << *(p + i) << endl;
    }
}

int main() { int i = 0, j[2] = {0, 1}; 
    print(&i, 1);
    print(j, 2);
    return 0;
}