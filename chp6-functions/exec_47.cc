#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using Iter = vector<int>::const_iterator;

void print(Iter begin, Iter end) {
    #ifndef NDEBUG
        cout << "Size of vector:" << (end - begin) << endl;
    #endif
    if (begin != end) {
        cout << *begin << " ";
        print(++begin, end);
    }
    else {
        cout << endl;
    }
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    print(v.begin(), v.end());
    return 0;
}