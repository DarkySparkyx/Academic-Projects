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
    Hex* hex=nullptr;
    while(getline(cin,input))
    {
        if(Hex::CzyZnalezionoSubstring(input,"---"))
        {
            if(hex!=nullptr)
                delete hex;
            hex = new Hex;
        }
        else
        {
            if(input=="BOARD_SIZE")
            {
                printf("%d\n",hex->getBoardSize());
            }
            else if(input=="PAWNS_NUMBER")
            {
                printf("%d\n",hex->getPawnNumber());
            }
            else if(input=="IS_BOARD_CORRECT")
            {
                if(hex->isBoardCorrect())
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else if(input=="IS_GAME_OVER")
            {
                if(hex->isBoardCorrect() && hex->isGameOverForRed())
                {
                    printf("YES RED\n");
                }
                else if(hex->isBoardCorrect() && hex->isGameOverForBlue())
                {
                    printf("YES BLUE\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else if(input=="IS_BOARD_POSSIBLE")
            {
                if(hex->isBoardPossible())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
                cout << endl;
            }
            else if(input=="CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT")
            {
                if(hex->canRedWinInOneMoveWithNaive())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if(input=="CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT")
            {
                if(hex->canBlueWinInOneMoveWithNaive())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if(input=="CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT")
            {
                if(hex->canRedWinInTwoMovesWithNaive())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if(input=="CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT")
            {
                if(hex->canBlueWinInTwoMovesWithNaive())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if(input=="CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT")
            {
                if(hex->whoIsNext()==RED)
                {
                    if(hex->QuickCheck() && hex->Player(RED))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    if(hex->QuickCheck() && hex->EnemyPlayer(RED))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
            else if(input=="CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT")
            {
                if(hex->whoIsNext()==BLUE)
                {
                    if(hex->QuickCheck() && hex->Player(BLUE))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    if(hex->QuickCheck() && hex->EnemyPlayer(BLUE))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
            else if(input=="CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT")
            {
                if(hex->whoIsNext()==RED)
                {
                    if(hex->QuickCheck() && hex->PlayerEnemyPlayer(RED))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    if(hex->QuickCheck() && hex->EnemyPlayerEnemyPlayer(RED))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
            else if(input=="CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT")
            {
                if(hex->whoIsNext()==BLUE)
                {
                    if(hex->QuickCheck() && hex->PlayerEnemyPlayer(BLUE))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    if(hex->QuickCheck() && hex->EnemyPlayerEnemyPlayer(BLUE))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }

        }

    }
    return 0;
}


