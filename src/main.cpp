#include "Header.h"
#include <Math.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char turn[6];
    int h = 0;
    int move1 = 0, move2 = 0;

    char pole[9][9]
            = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
               {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Chessplace(pole);

    while (1) {
        moveP(turn, h, move1, move2, pole);
        Chessplace(pole);
    }

    return 0;
}
