#include<vector>
#include<iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


int main() {
    vector<unsigned> scores(11, 0);
    
    int score;
    auto it = scores.begin();
    while (cin >> score) {
        ++(*(it + score / 10));
    }

    for (auto s : scores) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}