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

bool Hex::canRedWinInOneMoveWithPerfect()
{
    int liczbaOpcji=0;
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
                    liczbaOpcji++;
                }
                board[i][j]=EMPTY;
            }
        }
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(liczbaOpcji>0)
        {
            return true;
        }
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(liczbaOpcji>1)
        {
            return true;
        }
    }
    return false;
}

bool Hex::canBlueWinInOneMoveWithPerfect()
{
    int liczbaOpcji=0;
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
                    liczbaOpcji++;
                }
                board[i][j]=EMPTY;
            }
        }
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(liczbaOpcji>0)
        {
            return true;
        }
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(liczbaOpcji>1)
        {
            return true;
        }
    }
    return false;
}

bool Hex::canRedWinInTwoMovesWithPerfect()
{
    int liczbaOpcji=0;
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
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<boardSize;j++)
        {
            board[i][j]=RED;
            if(canRedWinInOneMoveWithPerfect())
            {
                liczbaOpcji++;
            }
            board[i][j]=EMPTY;
        }
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(liczbaOpcji>1)
        {
            return true;
        }
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(liczbaOpcji>2)
        {
            return true;
        }
    }
    return false;
}

bool Hex::canBlueWinInTwoMovesWithPerfect()
{
    int liczbaOpcji=0;
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
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<boardSize;j++)
        {
            board[i][j]=BLUE;
            if(canBlueWinInOneMoveWithPerfect())
            {
                liczbaOpcji++;
            }
            board[i][j]=EMPTY;
        }
    }
    if(redPawnNumber-1==bluePawnNumber)
    {
        if(liczbaOpcji>1)
        {
            return true;
        }
    }
    if(redPawnNumber==bluePawnNumber)
    {
        if(liczbaOpcji>2)
        {
            return true;
        }
    }
    return false;
}
