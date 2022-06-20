#include <iostream>

int main() {
    int begin = 0, end = 0;

    std::cin >> begin >> end;

    if (begin <= end) {
        int index = begin;
        while (index <= end) {
            std::cout << index++ << std::endl;
        }
    }

    return 0;
}