#ifndef ADD_H
#define ADD_H
bool CheckTypePiece(char turn[], char pole[][9]);
void Chessplace(char pole[][9]);
void movePawn(char coordinates[], char pole[][9]);
bool checkMove(char coordinates[], char pole[][9]);
void moveOtherFigures(char coordinates[], char pole[][9]);
bool CheckBoard(int a, int b, int c, int d);
bool CheckMove(char coordinates[], char pole[][9]);
bool CheckType(int beginY, int beginX, char pole[][9], char coordinates[]);
bool CheckMove(
        char coordinates[],
        char pole[][9],
        int endY,
        int endX,
        int beginY,
        int beginX);
#endif
