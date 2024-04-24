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
    if(isBoardCorrect())
    {
        for(int i=0; i<boardSize; i++)
        {
            if(isGameOver(0,i,RED))
            {
                clearWasVisited();
                return true;
            }
        }
    }
    clearWasVisited();
    return false;
}

bool Hex::isGameOverForBlue()
{
    if(isBoardCorrect())
    {
        for(int i=0; i<getBoardSize(); i++)
        {
            if(isGameOver(i,boardSize-1,BLUE))
            {
                clearWasVisited();
                return true;
            }
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
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[j][i]==EMPTY)
            {
                board[j][i]=RED;
                if(isGameOverForRed())
                {
                    return true;
                }
                board[j][i]=EMPTY;
            }
        }
    }
    return false;
}

bool Hex::canBlueWinInOneMoveWithNaive()
{
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[j][i]==EMPTY)
            {
                board[j][i]=BLUE;
                if(isGameOverForBlue())
                {
                    return true;
                }
                board[j][i]=EMPTY;
            }
        }
    }
    return false;
}

bool Hex::canRedWinInTwoMovesWithNaive()
{
    Field pierwszy;
    Field drugi;

    if(redPawnNumber==bluePawnNumber)
    {
        pierwszy=RED;
        drugi=BLUE;
    }
    else
    {
        pierwszy=BLUE;
        drugi=RED;
    }

    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[j][i]==EMPTY)
            {

            }
        }
    }
    return false;
}

bool Hex::canBlueWinInTwoMovesWithNaive()
{
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(board[j][i]==EMPTY)
            {
                board[j][i]=BLUE;
                if(canBlueWinInOneMoveWithNaive())
                {
                    return true;
                }
                board[j][i]=EMPTY;
            }
        }
    }
    return false;
}
