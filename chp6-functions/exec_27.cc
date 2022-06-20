#include <initializer_list>
#include <iostream>

using std::initializer_list;
using std::cout;
using std::endl;

int sum(initializer_list<int> list) {
    int sum = 0;
    for (auto i : list) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << sum({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
    return 0;
}