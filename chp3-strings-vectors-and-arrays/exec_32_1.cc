#include<cstdlib>

int main() {
    int arr1[10], arr2[10];
    for (size_t i = 0; i < 10; ++i) {
        arr1[i] = i;
    }

    for (size_t i = 0; i < 10; ++i) {
        arr2[i] = arr1[i];
    }

    return 0;
}