#include "Hex.h"
#include <string>

using namespace std;

bool Hex::CzyZnalezionoSubstring(string tekst,string szukany)
{
    size_t tmp=tekst.find(szukany,0);
    return tmp<tekst.length();
}

Hex::Hex()
{
    clearWasVisited();
    redPawnNumber=0;
    bluePawnNumber=0;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {
            board[i][j]=EMPTY;
        }
    }

    string linia;
    int inputLinesCount=0,XOffset=0,YOffset=-1,x,y;
    bool SecondHalfOfInput=false;

    while(getline(cin,linia),!CzyZnalezionoSubstring(linia,"---"))
    {
        inputLinesCount++;
        if(!SecondHalfOfInput)
        {
            YOffset++;
            if(linia[0]=='<')
            {
                SecondHalfOfInput=true;
            }
        }
        else
        {
            XOffset++;
        }
        x=XOffset;
        y=YOffset;
        for(int i=0; i<linia.length(); i++)
        {
            switch(linia[i])
            {
            case '>':
                x++;
                y--;
                break;
            case 'r':
                redPawnNumber++;
                board[x][y]=RED;
                break;
            case 'b':
                bluePawnNumber++;
                board[x][y]=BLUE;
                break;
            default:
                break;
            }
        }
    }
    boardSize=(inputLinesCount+1)/2;
}

int Hex::getBoardSize()
{
    return boardSize;
}

int Hex::getPawnNumber()
{
    return redPawnNumber + bluePawnNumber;
}

bool Hex::isBoardCorrect()
{
    if(redPawnNumber==bluePawnNumber)
    {
        return true;
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Hex::CzyPionNaGranicy(int x, int y, Field badanyGracz)
{
    if(badanyGracz==RED)
    {
        if(board[x][y]==RED && x==boardSize-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(board[x][y]==BLUE && y==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Hex::isGameOver(int x, int y,Field badanygracz)
{
    if(board[x][y]!=badanygracz)
    {
        return false;
    }
    wasVisited[x][y]=true;
    if(CzyPionNaGranicy(x,y,badanygracz))
    {
        return true;
    }
    else
    {
        if(czyPozycjaDobra(x,y-1) && !wasVisited[x][y-1] && isGameOver(x,y-1,badanygracz))
        {
            return true;
        }
        else if(czyPozycjaDobra(x+1,y) && !wasVisited[x+1][y] && isGameOver(x+1,y,badanygracz))
        {
            return true;
        }
        else if(czyPozycjaDobra(x+1,y+1) && !wasVisited[x+1][y+1] && isGameOver(x+1,y+1,badanygracz))
        {
            return true;
        }
        else if(czyPozycjaDobra(x,y+1) && !wasVisited[x][y+1] && isGameOver(x,y+1,badanygracz))
        {
            return true;
        }
        else if(czyPozycjaDobra(x-1,y) && !wasVisited[x-1][y] && isGameOver(x-1,y,badanygracz))
        {
            return true;
        }
        else if(czyPozycjaDobra(x-1,y-1) && !wasVisited[x-1][y-1] && isGameOver(x-1,y-1,badanygracz))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Hex::czyPozycjaDobra(int x, int y)
{
    if(x>=0 && y>=0 && x<boardSize && y<boardSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Hex::clearWasVisited()
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {
            wasVisited[i][j]=false;
        }
    }
}

bool Hex::isGameOverForRed()
{

    for(int i=0; i<boardSize; i++)
    {
        if(isGameOver(0,i,RED))
        {
            clearWasVisited();
            return true;
        }
    }

    clearWasVisited();
    return false;
}

bool Hex::isGameOverForBlue()
{

    for(int i=0; i<getBoardSize(); i++)
    {
        if(isGameOver(i,boardSize-1,BLUE))
        {
            clearWasVisited();
            return true;
        }
    }

    clearWasVisited();
    return false;
}

bool Hex::isBoardPossible()
{
    if(isBoardCorrect())
    {
        if(isGameOverForRed())
        {
            if(isGameOverForBlue() || redPawnNumber-1!=bluePawnNumber)
            {
                return false;
            }
            for(int i=0; i<boardSize; i++)
            {
                for(int j=0; j<boardSize; j++)
                {
                    if(board[j][i]==RED)
                    {
                        board[j][i]=EMPTY;
                        if(!isGameOverForRed())
                        {
                            board[j][i]=RED;
                            return true;
                        }
                        board[j][i]=RED;
                    }
                }
            }
            return false;
        }
        else if(isGameOverForBlue())
        {
            if(redPawnNumber!=bluePawnNumber)
            {
                return false;
            }
            for(int i=0; i<boardSize; i++)
            {
                for(int j=0; j<boardSize; j++)
                {
                    if(board[j][i]==BLUE)
                    {
                        board[j][i]=EMPTY;
                        if(!isGameOverForBlue())
                        {
                            board[j][i]=BLUE;
                            return true;
                        }
                        board[j][i]=BLUE;
                    }
                }
            }
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool Hex::canRedWinInOneMoveWithNaive()
{
    if(!isBoardPossible())
    {
        return false;
    }
    if(isGameOverForBlue() || isGameOverForRed())
    {
        return false;
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<1)
        {
            return false;
        }
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<2)
        {
            return false;
        }
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                board[i][j]=RED;
                if(isGameOverForRed())
                {
                    board[i][j]=EMPTY;
                    return true;
                }
                board[i][j]=EMPTY;
            }
        }
    }
    return false;
}

bool Hex::canBlueWinInOneMoveWithNaive()
{
    if(!isBoardPossible())
    {
        return false;
    }
    if(isGameOverForBlue() || isGameOverForRed())
    {
        return false;
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<1)
        {
            return false;
        }
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<2)
        {
            return false;
        }
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                board[i][j]=BLUE;
                if(isGameOverForBlue())
                {
                    board[i][j]=EMPTY;
                    return true;
                }
                board[i][j]=EMPTY;
            }
        }
    }
    return false;
}

bool Hex::canRedWinInTwoMovesWithNaive()
{
    if(!isBoardPossible())
    {
        return false;
    }
    if(isGameOverForBlue() || isGameOverForRed())
    {
        return false;
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<3)
        {
            return false;
        }
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<4)
        {
            return false;
        }
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                board[i][j]=RED;
                if(canRedWinInOneMoveWithNaive())
                {
                    board[i][j]=EMPTY;
                    return true;
                }
                board[i][j]=EMPTY;
            }
        }
    }
    return false;
}

bool Hex::canBlueWinInTwoMovesWithNaive()
{
    if(!isBoardPossible())
    {
        return false;
    }
    if(isGameOverForBlue() || isGameOverForRed())
    {
        return false;
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<3)
        {
            return false;
        }
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(boardSize*boardSize-getPawnNumber()<4)
        {
            return false;
        }
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                board[i][j]=BLUE;
                if(canBlueWinInOneMoveWithNaive())
                {
                    board[i][j]=EMPTY;
                    return true;
                }
                board[i][j]=EMPTY;
            }
        }
    }
    return false;
}

Field Hex::whoIsNext()
{
    if(redPawnNumber==bluePawnNumber)
    {
        return RED;
    }
    else
    {
        return BLUE;
    }
}

void Hex::increaseColorPawnNumber(Field badanyGracz)
{
    if(badanyGracz==RED)
    {
        redPawnNumber++;
    }
    else
    {
        bluePawnNumber++;
    }
}

void Hex::decreaseColorPawnNumber(Field badanyGracz)
{
    if(badanyGracz==RED)
    {
        redPawnNumber--;
    }
    else
    {
        bluePawnNumber--;
    }
}

bool Hex::isGameOverForPlayer(Field badanyGracz)
{
    if(badanyGracz==RED)
    {
        return isGameOverForRed();
    }
    else
    {
        return isGameOverForBlue();
    }
}

bool Hex::Player(Field badanyGracz)
{
    if(isGameOverForRed() || isGameOverForBlue())
    {
        return false;
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                increaseColorPawnNumber(badanyGracz);
                board[i][j]=badanyGracz;
                if(isGameOverForPlayer(badanyGracz))
                {
                    board[i][j]=EMPTY;
                    decreaseColorPawnNumber(badanyGracz);
                    return true;
                }
                board[i][j]=EMPTY;
                decreaseColorPawnNumber(badanyGracz);
            }
        }
    }
    return false;
}

Field Hex::getEnemy(Field badanyGracz)
{
    if(badanyGracz==RED)
    {
        return BLUE;
    }
    else
    {
        return RED;
    }
}

bool Hex::EnemyPlayer(Field badanyGracz)
{
    if(isGameOverForRed() || isGameOverForBlue())
    {
        return false;
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                increaseColorPawnNumber(badanyGracz);
                board[i][j]=badanyGracz;
                if(isGameOverForPlayer(badanyGracz))
                {
                    board[i][j]=getEnemy(badanyGracz);
                    decreaseColorPawnNumber(badanyGracz);
                    increaseColorPawnNumber(getEnemy(badanyGracz));
                    bool result=Player(badanyGracz);
                    decreaseColorPawnNumber(getEnemy(badanyGracz));
                    board[i][j]=EMPTY;
                    return result;
                }
                board[i][j]=EMPTY;
                decreaseColorPawnNumber(badanyGracz);
            }
        }
    }
    return false;
}

bool Hex::QuickCheck()
{
    if(!isBoardPossible())
    {
        return false;
    }
    if(isGameOverForRed())
    {
        return false;
    }
    if(isGameOverForBlue())
    {
        return false;
    }
    return true;
}

bool Hex::PlayerEnemyPlayer(Field badanyGracz)
{

    if(isGameOverForRed() || isGameOverForBlue())
    {
        return false;
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                increaseColorPawnNumber(badanyGracz);
                board[i][j]=badanyGracz;
                if(EnemyPlayer(badanyGracz))
                {
                    board[i][j]=EMPTY;
                    decreaseColorPawnNumber(badanyGracz);
                    return true;
                }
                board[i][j]=EMPTY;
                decreaseColorPawnNumber(badanyGracz);
            }
        }
    }
    return false;
}

bool Hex::EnemyPlayerEnemyPlayer(Field badanyGracz)
{
    if(isGameOverForRed() || isGameOverForBlue())
    {
        return false;
    }
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[i][j]==EMPTY)
            {
                increaseColorPawnNumber(getEnemy(badanyGracz));
                board[i][j]=getEnemy(badanyGracz);
                if(!PlayerEnemyPlayer(badanyGracz))
                {
                    board[i][j]=EMPTY;
                    decreaseColorPawnNumber(getEnemy(badanyGracz));
                    return false;
                }
                board[i][j]=EMPTY;
                decreaseColorPawnNumber(getEnemy(badanyGracz));
            }
        }
    }
    return true;
}

