#ifndef CLASSES_SALES_DATA_H
#define CLASSES_SALES_DATA_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;

struct Sales_data;

istream &read(istream &, Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);

class Sales_data {
    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);

   private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    double avg_price() const { return units_sold ? revenue / units_sold : 0; }

   public:
    Sales_data(const string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {
        cout << "Sales_data(const string &s, unsigned n, double p)" << endl;
    }

    Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data()" << endl; }

    explicit Sales_data(const string &s) : Sales_data(s, 0, 0) {
        cout << "Sales_data(const string &s)" << endl;
    }

    Sales_data(istream &is) : Sales_data() { read(is, *this);
        cout << "Sales_data(istream &is)" << endl;
    }

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

#endif