#ifndef CLASSES_PERSON_H
#define CLASSES_PERSON_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::cin;

class Person {
    friend istream &read(istream &is, Person &p);

   private:
    string name;
    string address;

   public:
    Person(const string &name, const string &address) : name(name), address(address) {}
    Person() : Person("", "") {}
    Person(const string &name) : Person(name, "") {}
    explicit Person(istream& is) : Person() {cin >> name >> address;}

    string const &getName() const { return name; }
    string const &getAddress() const { return address; }
};

ostream &print(ostream &os, const Person &p) {
    os << p.getName() << " " << p.getAddress();
    return os;
}

istream &read(istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

#endif