#include <iostream>
#include <Windows.h>
using namespace std;

void Chessplace(char pole[][9]) {
	cout << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 8 || (j == 0)) {
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, 9);
			}
			if (j == 0) {
				cout << " ";
			}
			cout << pole[i][j] << " ";
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, 7);
		}
		cout << endl;
	}
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 7);
	cout << endl;
}
