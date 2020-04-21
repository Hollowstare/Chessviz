#include <Math.h>
#include <cstring>
#include <iostream>

using namespace std;

string transformChar = " ";
int beginY = 0, endY = 0;
bool check = true;
int beginX = 0, endX = 0;
char typeFigure;
void movePawn(char coordinates[], char pole[][9]);

bool checkMove(char coordinates[], char pole[][9]);



void CheckTypePiece(char coordinates[], char pole[][9])
{
	if (strlen(coordinates) == 5) {
		if (checkMove(coordinates, pole)) {
			movePawn(coordinates, pole);
		}
	}
	else {
		cout << "Incorrect entry, the pawn's move is written according to the pattern:" << endl
			<< "| field where the pawn is | - | field where the pawn moves |"
			<< endl;
	}
	cout << endl;
}
void movePawn(char coordinates[], char pole[][9])
{

	if (pole[beginY - 1][beginX] == 'p') {
		pole[beginY - 1][beginX] = ' ';
		pole[endY - 1][endX] = 'p';
	}
	else if(pole[beginY - 1][beginX] == 'P') {
		pole[beginY - 1][beginX] = ' ';
		pole[endY - 1][endX] = 'P';
	}

}


bool checkMove(char coordinates[], char pole[][9]) {

	for (int i = 0; i < 4; i += 3) {
		switch (coordinates[i]) {
		case 'a':
			if (i == 0) {
				beginX = 1;
			}
			else {
				endX = 1;
			}
			break;
		case 'b':
			if (i == 0) {
				beginX = 2;
			}
			else {
				endX = 2;
			}
			break;
		case 'c':
			if (i == 0) {
				beginX = 3;
			}
			else {
				endX = 3;
			}
			break;
		case 'd':
			if (i == 0) {
				beginX = 4;
			}
			else {
				endX = 4;
			}
			break;
		case 'e':
			if (i == 0) {
				beginX = 5;
			}
			else {
				endX = 5;
			}
			break;
		case 'f':
			if (i == 0) {
				beginX = 6;
			}
			else {
				endX = 6;
			}
			break;
		case 'g':
			if (i == 0) {
				beginX = 7;
			}
			else {
				endX = 7;
			}
			break;
		case 'h':
			if (i == 0) {
				beginX = 8;
			}
			else {
				endX = 8;
			}
			break;
		}
	}

	transformChar[0] = coordinates[1];
	beginY = atoi(transformChar.c_str());
	transformChar[0] = coordinates[4];
	endY = atoi(transformChar.c_str());

		if (beginX <= 0 || beginX >= 9 || endY <= 0 || endY >= 9) {
			cout << "Incorrect entry, the figure cannot be located and go beyond the chessboard" << endl;
			return false;
		}

		if (pole[beginY - 1][beginX] == 'p' || pole[beginY - 1][beginX] == 'P') {
		}
		else {
			cout << "Incorrect entry, the type of piece(pawn) does not match the type of piece standing on the starting chessboard square" << endl;
			return false;
		}

				if (coordinates[2] == '-') {
					if (pole[endY - 1][endX] == ' ') {

					}
					else {
						cout << "Incorrect entry, the figure cannot make a quiet move to the occupied chessboard square" << endl;
						return false;
					}
				}
				else if (coordinates[2] == 'x') {
					if (pole[endY - 1][endX] != ' ') {

					}
					else {
						cout << "Incorrect entry, the figure cannot take to an empty chessboard square"<< endl;
						return false;
					}
				}
	return true;
}
