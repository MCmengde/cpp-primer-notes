#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
    for (size_t i = 1; i <= argc; ++i) {
        cout << argv[i] << endl;
    }
    return 0;
}