#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.unit_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.unit_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.unit_sold += trans.unit_sold;
                total.revenue += trans.revenue;
            } else {
                cout << "total bookNo: " << total.bookNo << "\n"
                     << "total unit_sold: " << total.unit_sold << "\n"
                     << "total revenue: " << total.revenue << endl;
                total = trans;
            }
        }
        cout << "total bookNo: " << total.bookNo << "\n"
             << "total unit_sold: " << total.unit_sold << "\n"
             << "total revenue: " << total.revenue << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}