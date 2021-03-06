#include <iostream>
using std::cout;
using std::endl;

int main() {
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    // V1
    for (auto &p : ia) {
        for (int i : p) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    // V2
    for (auto i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // V3
    for (auto *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}