#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    const vector<string> grades = {"F", "D", "C", "B", "A", "A++"};

    unsigned int g;
    string letter;
    while (cin >> g) {
        if (g < 60) {
            letter = grades[0];
        } else {
            letter = grades[(g - 50) / 10];
            if (g != 100) {
                if (g % 10 > 7) {
                    letter += "+";
                } else if (g % 10 < 3) {
                    letter += "-";
                }
            }
        }
        cout << letter << endl;
    }
    return 0;
}