#include<iostream>
#include<iterator>
#include<vector>

using std::begin;
using std::end;
using std::cout;
using std::endl;
using std::vector;

bool compare_array(int* const ab1, int* const ae1, 
                    int* const ab2, int* const ae2) {
    if((ae1 - ab1) != (ae2 - ab2)) {
        // size different.
        return false;
    } 

    for (int *i = ab1, *j = ab2; i != ae1 && j != ae2; ++i, ++j) {
        if (*i != *j) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr1[] = {0, 1, 2};
    int arr2[] = {0, 1, 2};

    if (compare_array(begin(arr1), end(arr1), begin(arr2), end(arr2))) {
        cout << "arr1 == arr2" << endl;
    }

    vector<int> v1{0, 1, 2};
    vector<int> v2{0, 1, 2};

    if (v1 == v2) {
        cout << "v1 == v2" << endl;
    }

    return 0;
}