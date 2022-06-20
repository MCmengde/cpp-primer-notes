#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
    vector<int> v;

    int i;
    while (cin >> i) {
        v.push_back(i);
    }

    // print the sum of each pair of adjacent elements.
    for (vector<int>::size_type i = 0; i < v.size() - 1; i += 2) {
        cout << v[i] + v[i + 1] << " ";
    }
    cout << endl;

    // print the sum fo first and last ...
    for (vector<int>::size_type i = 0, j = v.size() - 1; i < j; ++i, --j) {
        cout << v[i] + v[j] << " ";
    }
    cout << endl;

    return 0;
}