#include <iostream>

using std::cout;
using std::endl;

void reset(int &i) {
    i = 0;
}

int main() {
    int i = 32;
    reset(i);
    cout << "i: " << i << endl;
    return 0;
}