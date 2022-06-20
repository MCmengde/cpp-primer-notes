#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int val1 = 1, val2 = 2;
    swap(&val1, &val2);
    cout << "val1: " << val1 
        << "\tval2: " << val2 << endl;
    return 0;
}