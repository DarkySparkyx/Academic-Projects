#include <iostream>
#include <string>
#include "Hex.h"
#include <fstream>
using namespace std;

int main()
{
    //fstream plik;
    //plik.open("result.txt",ios::out);
    string input;
    Hex* hex;
    while(getline(cin,input))
    {
        if(Hex::CzyZnalezionoSubstring(input,"---"))
        {
            hex = new Hex;
        }
        else if(input=="")
        {
            delete hex;
        }
        else
        {
            if(input=="BOARD_SIZE")
            {
                cout << hex->getBoardSize() << endl;
            }
            if(input=="PAWNS_NUMBER")
            {
                cout << hex->getPawnNumber() << endl;
            }
            if(input=="IS_BOARD_CORRECT")
            {
                if(hex->isBoardCorrect())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            if(input=="IS_GAME_OVER")
            {
                bool answerNo=true;
                if(hex->isBoardCorrect())
                {
                    for(int i=0; i<hex->getBoardSize(); i++)
                    {
                        if(hex->isGameOver(0,i,RED))
                        {
                            cout << "YES RED" << endl;
                            answerNo=false;
                            break;
                        }
                    }

                    for(int i=0; i<hex->getBoardSize(); i++)
                    {
                        if(hex->isGameOver(i,hex->getBoardSize()-1,BLUE))
                        {
                            cout << "YES BLUE" << endl;
                            answerNo=false;
                            break;
                        }
                    }
                }
                if(answerNo)
                {
                    cout << "NO" << endl;
                }
            }
        }

    }
    return 0;
}
