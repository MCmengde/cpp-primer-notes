#include <iostream>

#include "Sales_data.h"

using namespace std;

int main() {
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        istream &is = cin;
        while (is) {
            Sales_data trans(is);
            if (!is) {
                break;
            }
            if (total.isbn() == trans.isbn()) {
                add(total, trans);
            } else {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}