#include <Math.h>
#include <iostream>
#include <string>

using namespace std;

void moveP(char turn[], int h, int move1, int move2, char pole[][9])
{
    bool flag = true;
    string s = " ";
    cin >> turn;
    cout << endl;
    switch (turn[0]) {
    case 'a':
        h = 1;
        break;
    case 'b':
        h = 2;
        break;
    case 'c':
        h = 3;
        break;
    case 'd':
        h = 4;
        break;
    case 'e':
        h = 5;
        break;
    case 'f':
        h = 6;
        break;
    case 'g':
        h = 7;
        break;
    case 'h':
        h = 8;
        break;
    }

    s[0] = turn[1];

    move1 = atoi(s.c_str());

    s[0] = turn[4];

    move2 = atoi(s.c_str());

    pole[move1 - 1][h] = ' ';
    if (flag) {
        pole[move2 - 1][h] = 'P';
        flag = false;
    } else {
        pole[move2 - 1][h] = 'p';
        flag = true;
    }
}
