#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int abs(int i) {
    return i < 0 ? -i : i;
}

int main() {
    const string prompt = "Please input a number:\n";
    for (int i; cout << prompt, cin >> i;) {
        cout << abs(i) << endl;
    }
    return 0;
}