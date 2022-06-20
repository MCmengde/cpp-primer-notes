#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    const vector<string> grades = {"F", "D", "C", "B", "A", "A++"};

    unsigned int g;
    string letter;
    while (cin >> g) {
        letter = (g < 60) ? grades[0] : grades[(g - 50) / 10];
        letter += (g < 60 || g == 100) ? "" :
                    (g % 10 > 7) ? "+" : 
                    (g % 10 < 3) ? "-" : "";
        cout << letter << endl;
    }
    return 0;
}