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
