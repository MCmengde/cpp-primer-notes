#include<vector>
#include<string>
#include<iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void printInfosOfInts(vector<int> v) {
    cout << "************" << endl;
    cout << "size:" << v.size() << endl;
    cout << "elements:";
    for (auto i: v) {cout << i << " ";}
    cout << endl << "************" << endl; 
}

void printInfosOfStrings(vector<string> v) {
    cout << "************" << endl;
    cout << "size:" << v.size() << endl;
    cout << "elements:";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl << "************" << endl;
}

int main() {
    // Empty, no element.
    vector<int> v1;
    printInfosOfInts(v1);

    // 10 elements, initialized to be 0.
    vector<int> v2(10);
    printInfosOfInts(v2);

    // 10 elements, initialized to be 42.
    vector<int> v3(10, 42);
    printInfosOfInts(v3);

    // 1 element with the value of 10.
    vector<int> v4{10};
    printInfosOfInts(v4);

    // 2 elements, values are 10 and 42.
    vector<int> v5{10, 42};
    printInfosOfInts(v5);

    // 10 elements, values are empty string.
    vector<string> v6{10};
    printInfosOfStrings(v6);

    // 10 elements, values are "hi".
    vector<string> v7{10, "hi"};
    printInfosOfStrings(v7);
}
