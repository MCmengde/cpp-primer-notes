#include <iostream>

#include "../include/Sales_item.h"
int main() {
    Sales_item item, sum;
    // sum should be initialized before '+'.
    std::cin >> sum;
    while (std::cin >> item) {
        sum += item;
    }

    std::cout << sum << std::endl;
    return 0;
}