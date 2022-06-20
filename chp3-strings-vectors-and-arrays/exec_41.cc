#include<vector>
#include<iostream>
#include<iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
    int arr[] = {1, 2, 3};

    vector<int> v(begin(arr), end(arr));

    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}