#define CATCH_CONFIG_MAIN
#include "../src/header.h"
#include "../thirdparty/catch.hpp"
#include <string>
using namespace std;

char pole[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                   {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};


TEST_CASE("Incorrect quiet move", "Incorrect")
{
  int endY = 4, endX = 5;
  pole[3][5] = 'P';
  char coordinates[6] = "e2-e4";
  REQUIRE(CheckMove(coordinates, pole, endY, endX) == false);
}

TEST_CASE("Сorrect quiet move", "correct")
{
  int endY = 4, endX = 5;
  pole[3][5] = ' ';
  char coordinates[6] = "e2-e4";
  REQUIRE(CheckMove(coordinates, pole, endY, endX) == true);
}

TEST_CASE("correct attack move", "Correct")
{
  int endY = 4, endX = 5;
  pole[3][5] = 'P';
  char coordinates[6] = "e2xe4";
  REQUIRE(CheckMove(coordinates, pole, endY, endX) == true);
}

TEST_CASE("Incorrect attack move", "Incorrect")
{
  int endY = 4, endX = 5;
  pole[3][5] = ' ';
  char coordinates[6] = "e2xe4";
  REQUIRE(CheckMove(coordinates, pole, endY, endX) == false);
}

TEST_CASE("The move isn't off the board", "correct")
{
  REQUIRE(CheckBoard(2, 4, 5, 9) == false);
  REQUIRE(CheckBoard(1, 4, 5, 7) == true);
  REQUIRE(CheckBoard(4, 3, 6, 8) == true);
  REQUIRE(CheckBoard(9, 4, 2, 2) == false);
}

TEST_CASE("correct check type 'Q'", "correct")
{
  int beginY = 8, beginX = 4;
  pole[7][4] = 'Q';
  char coordinates[7] = "Qd8-d4";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct Check type 'q'", "correct") {
  int beginY = 1, beginX = 4;
  pole[0][4] = 'q';
  char coordinates[7] = "qd1-d4";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct check type 'K'", "correct")
{
  int beginY = 8, beginX = 5;
  pole[7][5] = 'K';
  char coordinates[7] = "Ke8-e3";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct Check type 'k'", "correct") {
  int beginY = 1, beginX = 5;
  pole[0][5] = 'k';
  char coordinates[7] = "ke1-e4";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct check type 'N'", "correct")
{
  int beginY = 8, beginX = 3;
  pole[7][3] = 'N';
  char coordinates[7] = "Nb8-f4";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct Check type 'n'", "correct") {
  int beginY = 1, beginX = 4;
  pole[0][4] = 'n';
  char coordinates[7] = "nb1-d4";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct check type 'r'", "correct")
{
  int beginY = 1, beginX = 1;
  pole[0][1] = 'r';
  char coordinates[7] = "ra1-a5";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct Check type 'R'", "correct") {
  int beginY = 8, beginX = 1;
  pole[7][1] = 'R';
  char coordinates[7] = "Ra8-a6";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct check type 'B'", "correct")
{
  int beginY = 1, beginX = 3;
  pole[0][3] = 'B';
  char coordinates[7] = "Bb1-d6";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}

TEST_CASE("correct Check type 'b'", "correct") {
  int beginY = 8, beginX = 3;
  pole[7][3] = 'b';
  char coordinates[7] = "bb8-a3";
  REQUIRE(CheckType(beginY, beginX, pole, coordinates) == true);
}
