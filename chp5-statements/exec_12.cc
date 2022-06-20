#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0,
        tabCnt = 0, newlineCnt = 0, fiCnt = 0, ffCnt = 0, flCnt = 0;
    char c, pre = '\0';
    while (cin >> std::noskipws >> c) {
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
                if (pre == 'f') ++fiCnt;
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
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            case 'f':
                if (pre == 'f') ++ffCnt;
                break;
            case 'l':
                if (pre == 'f') ++flCnt;
            default:
                break;
        }
        pre = c;
    }

    cout << "Number of a:\t\t" << aCnt << "\n";
    cout << "Number of e:\t\t" << eCnt << "\n";
    cout << "Number of i:\t\t" << iCnt << "\n";
    cout << "Number of o:\t\t" << oCnt << "\n";
    cout << "Number of u:\t\t" << uCnt << "\n";
    cout << "Number of space:\t" << spaceCnt << "\n";
    cout << "Number of tab:\t\t" << tabCnt << "\n";
    cout << "Number of newline:\t" << newlineCnt << "\n";
    cout << "Number of ff:\t\t" << ffCnt << "\n";
    cout << "Number of fl:\t\t" << flCnt << "\n";
    cout << "Number of fi:\t\t" << fiCnt << endl;

    return 0;
}