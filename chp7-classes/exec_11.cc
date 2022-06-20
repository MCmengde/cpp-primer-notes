#include <vector>
#include "Sales_data.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<Sales_data> v{Sales_data(), Sales_data("Test1"), 
                        Sales_data("Test2", 12, 24), Sales_data(cin)};

    for (auto s : v) {
        print(cout, s) << endl;
    }

    return 0;
}