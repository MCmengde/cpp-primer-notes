#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char c;
    while (cin >> c) {
        if (c == 'a' || c == 'A') {
            ++aCnt;
        } else if (c == 'o' || c == 'O') {
            ++oCnt;
        } else if (c == 'e' || c == 'E') {
            ++eCnt;
        } else if (c == 'i' || c == 'I') {
            ++iCnt;
        } else if (c == 'u' || c == 'U'){
            ++uCnt;
        }
    }

    cout << "Number of a:\t" << aCnt << "\n";
    cout << "Number of e:\t" << eCnt << "\n";
    cout << "Number of i:\t" << iCnt << "\n";
    cout << "Number of o:\t" << oCnt << "\n";
    cout << "Number of u:\t" << uCnt << endl;
    
    return 0;
}