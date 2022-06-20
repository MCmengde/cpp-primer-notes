#include<iostream>
#include<string>
#include<cstring>

using std::string;
using std::strcmp;
using std::cout;
using std::endl;

int main() {
    string s1{"test1"};
    string s2{"test2"};

    if (s1 < s2) {
        cout << "s1 is less than s2" << endl;
    }

    char sc1[] = "test1";
    char sc2[] = "test2";
    
    if (strcmp(sc1, sc2) < 0) {
        cout << "sc1 is less than sc2" << endl;
    }

    return 0;
}