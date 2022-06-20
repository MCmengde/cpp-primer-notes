#include<cstring>
#include<iostream>

using std::strcat;
using std::strcpy;
using std::cout;
using std::endl;

int main() {
    char c1[] = "test1";
    char c2[] = "test2";

    char c3[11];
    strcpy(c3, c1);
    strcat(c3, c2);

    cout << c3 << endl;

    return 0;
}