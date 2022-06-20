#include<vector>
#include<cstdlib>

using std::vector;

int main() {
    vector<int> v1(10), v2(10);

    for (size_t i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    for (size_t i = 0; i < 10; ++i) {
        v2[i] = v1[i];
    }

    return 0;
}