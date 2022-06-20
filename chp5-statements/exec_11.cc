#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, 
        uCnt = 0, spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char c;
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
            default:
                break;
        }
    }

    cout << "Number of a:\t\t" << aCnt << "\n";
    cout << "Number of e:\t\t" << eCnt << "\n";
    cout << "Number of i:\t\t" << iCnt << "\n";
    cout << "Number of o:\t\t" << oCnt << "\n";
    cout << "Number of u:\t\t" << uCnt << "\n";
    cout << "Number of space:\t" << spaceCnt << "\n";
    cout << "Number of tab:\t\t" << tabCnt << "\n";
    cout << "Number of newline:\t" << newlineCnt << endl;

    return 0;
}