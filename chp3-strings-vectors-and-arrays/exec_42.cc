#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main() {
    vector<int> v{1, 2, 3};
    int arr[3];
    for (int i = 0; i < v.size(); ++i) {
        arr[i] = v[i];
    } 

    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}