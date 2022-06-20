#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char c;
    while (cin >> c) {
        switch (c) {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        default:
            break;
        }
    }

    cout << "Number of a:\t" << aCnt << "\n";
    cout << "Number of e:\t" << eCnt << "\n";
    cout << "Number of i:\t" << iCnt << "\n";
    cout << "Number of o:\t" << oCnt << "\n";
    cout << "Number of u:\t" << uCnt << endl;

    return 0;
}