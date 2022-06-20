#include<vector>
#include<iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> v;

    for (int i; cin >> i; v.push_back(i));

    for (auto it = v.cbegin(); it < v.cend() - 1; it += 2) {
        cout << *it + *(it + 1) << " ";
    }
    cout << endl;

    for (auto itl = v.cbegin(), itr = v.cend() - 1; itl <= itr; --itr, ++itl) {
        cout << *itl + *itr << " ";        
    }
    cout << endl;
    return 0;
}