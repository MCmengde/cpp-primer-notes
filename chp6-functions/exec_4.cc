#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int fact(int val) {
    return val > 1 ? val * fact(val - 1) : 1;
}

int main() {
    const string prompt = "Please input a number within [1, 13):\n";
    const string out_of_range = "Out of range, Please try again!\n";
    for (int i; cout << prompt, cin >> i;) {
        if (i < 1 || i > 12) {
            cout << out_of_range;
            continue;
        }

        cout << fact(i) << endl;
    }
    return 0;
}