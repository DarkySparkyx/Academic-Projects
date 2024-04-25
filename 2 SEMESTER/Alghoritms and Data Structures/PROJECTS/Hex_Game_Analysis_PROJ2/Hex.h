#include <iostream>
#include <algorithm>

using namespace std;

enum Field
{
    EMPTY,
    RED,
    BLUE,
};
class Hex
{
public:
    Field board[11][11];
    int boardSize;
    int redPawnNumber;
    int bluePawnNumber;
    bool wasVisited[11][11];
    //METODY PRYWATNE
    bool CzyPionNaGranicy(int x, int y, Field badanyGracz);
public:
    Hex();
    int getBoardSize();
    int getPawnNumber();
    bool isBoardCorrect();
    bool isGameOverForRed();
    bool isGameOverForBlue();
    bool isGameOver(int x, int y, Field badanyGracz);
    bool czyPozycjaDobra(int x, int y);
    static bool CzyZnalezionoSubstring(string,string);
    void clearWasVisited();
    bool isBoardPossible();
    bool canRedWinInOneMoveWithNaive();
    bool canBlueWinInOneMoveWithNaive();
    bool canRedWinInTwoMovesWithNaive();
    bool canBlueWinInTwoMovesWithNaive();
    bool canRedWinInOneMoveWithPerfect();
    bool canBlueWinInOneMoveWithPerfect();
    bool canRedWinInTwoMovesWithPerfect();
    bool canBlueWinInTwoMovesWithPerfect();
};
