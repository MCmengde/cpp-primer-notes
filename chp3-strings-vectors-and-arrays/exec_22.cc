#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> text{
        "Read a set of integers into a vector.",
        "Print the sum of each pair of adjacent elements.",
        "Change your program so that it prints the sum of the "
        "first and last elements,",
        "followed by the sum of the second and second-to-last, and so on.",
        "",
        "Revise the loop that printed the first paragraph in text to instead "
        "change the elements in text that correspond to the first paragraph to "
        "all uppercase. After you've updated text, print its contents."};

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto &c : *it) {
            c = toupper(c);
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}
