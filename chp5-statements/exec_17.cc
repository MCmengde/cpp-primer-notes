#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

bool prefix(vector<int> &v1, vector<int> &v2) {
    auto v1b = v1.begin(), v2b = v2.begin();
    auto v1e = v1.end(), v2e = v2.end();
    while (v1b != v1e && v2b != v2e) {
        if (*v1b++ != *v2b++) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    cout << prefix(v1, v2) << endl;
    return 0;
}