#include "header.h"
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char coordinates[6];
    char pole[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                       {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                       {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                       {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                       {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Chessplace(pole);
    cout << "White pieces go first (lower case)" << endl << endl;
    while (true) {
        cin >> coordinates;
        CheckTypePiece(coordinates, pole);
        Chessplace(pole);
    }
    return 0;
}
