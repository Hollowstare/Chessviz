#include "header.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int beginY = 0, endY = 0;
int beginX = 0, endX = 0;

bool CheckTypePiece(char coordinates[], char pole[][9])
{
    if (strlen(coordinates) > 6 || strlen(coordinates) < 5) {
        return false;
    }

    if (strlen(coordinates) == 5) {
        if (coordinates[2] == '-' && coordinates[2] == 'x') {
            return false;
        }
        if (checkMove(coordinates, pole)) {
            movePawn(coordinates, pole);
        }
    } else if (strlen(coordinates) == 6) {
        if (coordinates[3] == '-' && coordinates[3] == 'x') {
            return false;
        } else {
            return false;
        }
        switch (coordinates[0]) {
        case 'Q':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'q':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'N':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'n':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'K':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'k':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'R':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'r':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'B':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        case 'b':
            if (checkMove(coordinates, pole)) {
                moveOtherFigures(coordinates, pole);
            }
            break;
        }
    } else {
        cout << "Incorrect entry, the pawn's move is written according to the "
                "pattern:"
             << endl
             << "| field where the pawn is | - | field where the pawn moves |"
             << endl;
    }
    cout << endl;
    return true;
}
void movePawn(char coordinates[], char pole[][9])
{
    if (pole[beginY - 1][beginX] == 'p') {
        pole[beginY - 1][beginX] = ' ';
        pole[endY - 1][endX] = 'p';
    } else if (pole[beginY - 1][beginX] == 'P') {
        pole[beginY - 1][beginX] = ' ';
        pole[endY - 1][endX] = 'P';
    }
}

void moveOtherFigures(char coordinates[], char pole[][9])
{
    if (pole[beginY - 1][beginX] == coordinates[0]) {
        pole[beginY - 1][beginX] = ' ';
        pole[endY - 1][endX] = coordinates[0];
    }
}

bool checkMove(char coordinates[], char pole[][9])
{
    string transformChar = " ";
    int i = 0;
    if (strlen(coordinates) == 6) {
        i = 1;
    }
    for (; i < 5; i += 3) {
        switch (coordinates[i]) {
        case 'a':
            if (i == 0 || i == 1) {
                beginX = 1;
            } else {
                endX = 1;
            }
            break;
        case 'b':
            if (i == 0 || i == 1) {
                beginX = 2;
            } else {
                endX = 2;
            }
            break;
        case 'c':
            if (i == 0 || i == 1) {
                beginX = 3;
            } else {
                endX = 3;
            }
            break;
        case 'd':
            if (i == 0 || i == 1) {
                beginX = 4;
            } else {
                endX = 4;
            }
            break;
        case 'e':
            if (i == 0 || i == 1) {
                beginX = 5;
            } else {
                endX = 5;
            }
            break;
        case 'f':
            if (i == 0 || i == 1) {
                beginX = 6;
            } else {
                endX = 6;
            }
            break;
        case 'g':
            if (i == 0 || i == 1) {
                beginX = 7;
            } else {
                endX = 7;
            }
            break;
        case 'h':
            if (i == 0 || i == 1) {
                beginX = 8;
            } else {
                endX = 8;
            }
            break;
        }
    }

    if (strlen(coordinates) == 5) {
        transformChar[0] = coordinates[1];
        beginY = atoi(transformChar.c_str());
        transformChar[0] = coordinates[4];
        endY = atoi(transformChar.c_str());
    } else {
        transformChar[0] = coordinates[2];
        beginY = atoi(transformChar.c_str());
        transformChar[0] = coordinates[5];
        endY = atoi(transformChar.c_str());
    }

    if (CheckBoard(beginX, endY, beginY, endX) == false) {
        cout << "Incorrect entry, the figure cannot be located and go beyond "
                "the chessboard"
             << endl;
        return false;
    }

    if (CheckMove(coordinates, pole, endY, endX, beginY, beginX) == false) {
        if (pole[beginY - 1][beginX] == ' ') {
            cout << "Incorrect entry, you can't do move, cause start "
                    "chessboard square is empty."
                 << endl;
            return false;
        }
        if (strlen(coordinates) == 5) {
            if (coordinates[2] == 'x') {
                cout << "Incorrect entry, the figure cannot take to an empty "
                        "chessboard square"
                     << endl;
            } else {
                cout << "Incorrect entry, the figure cannot make a quiet move "
                        "to the occupied chessboard square"
                     << endl;
            }
        } else {
            if (coordinates[3] == 'x') {
                cout << "Incorrect entry, the figure cannot take to an empty "
                        "chessboard square"
                     << endl;
            } else {
                cout << "Incorrect entry, the figure cannot make a quiet move "
                        "to the occupied chessboard square"
                     << endl;
            }
        }

        return false;
    }

    if (CheckType(beginY, beginX, pole, coordinates) == false) {
        cout << "Incorrect entry, the type of piece does not match "
                "the type of piece standing on the starting chessboard "
                "square"
             << endl;
        return false;
    }

    return true;
}

bool CheckBoard(int a, int b, int c, int d)
{
    if (a <= 0 || a >= 9 || b <= 0 || b >= 9 || c <= 0 || c >= 9 || d <= 0
        || d >= 9) {
        return false;
    }
    return true;
}

bool CheckMove(
        char coordinates[],
        char pole[][9],
        int endY,
        int endX,
        int beginY,
        int beginX)
{
    if (pole[beginY - 1][beginX] != ' ') {
        if (strlen(coordinates) == 5) {
            if (coordinates[2] == '-') {
                if (pole[endY - 1][endX] == ' ') {
                } else {
                    return false;
                }
            } else if (coordinates[2] == 'x') {
                if (pole[endY - 1][endX] != ' ') {
                } else {
                    return false;
                }
            }
        } else {
            if (coordinates[3] == '-') {
                if (pole[endY - 1][endX] == ' ') {
                } else {
                    return false;
                }
            } else if (coordinates[3] == 'x') {
                if (pole[endY - 1][endX] != ' ') {
                } else {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

bool CheckType(int beginY, int beginX, char pole[][9], char coordinates[])
{
    if (strlen(coordinates) == 5) {
        if (pole[beginY - 1][beginX] == 'p'
            || pole[beginY - 1][beginX] == 'P') {
        } else {
            return false;
        }
    } else {
        if (pole[beginY - 1][beginX] == coordinates[0]) {
        } else {
            return false;
        }
    }
    return true;
}
