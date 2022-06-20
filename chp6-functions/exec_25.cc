#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return -1;
    }
    string arg1 = argv[1];
    string arg2 = argv[2];
    cout << arg1 + arg2 << endl;
    return 0;
}