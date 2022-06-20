#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    string str1{"12dskahakjdas"};
    decltype(str1.size()) i = 0;
    while (i < str1.size()) {
        str1[i] = 'X';
        ++i;
    }
    cout << str1 << endl;

    string str2{"dasfgasfsada"};
    for (decltype(str2.size()) i = 0; i < str2.size(); ++i) {
        str2[i] = 'X';
    }
    cout << str2 << endl;
    return 0;
}