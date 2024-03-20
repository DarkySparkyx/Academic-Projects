#include <iostream>
#include <cstdlib>
#include <time.h>
#include "conio2.h"

using namespace std;

#define SWR K,P
#define KZDEJMIJ cout << "You can now take your pawns out of the board. Press any key to continue..." << endl;
#define KO1 cout << "You can take of the pawn from position " << A << " using dice: " << K->a*K->M << endl;
#define KO2 cout << "You can take of the pawn from position " << B << " using dice: " << K->b*K->M << endl;
#define KO3 cout << "You can take of the pawn from position " << C <<  " using dice: " << K->a*K->M << endl;
#define KO4 cout << "Looks like you have some pawns out of the board..." << endl;
#define KO5 cout << "You need to use 1st dice to put the pawn back on the board" <<  endl;
#define KO6 cout << "You need to use 2nd dice to put the pawn back on the board" <<  endl;
#define FF cout << "You have to give up this dice" << endl;
#define K11 cout << "The game is about to START. Press any key to continue..." << endl; getch();
#define K12 cout << "Type 1 if you want to continue the game. Type 2 if you want to save and quit" << endl;
#define K13 cout << "WHITE is the winner!" << endl; getch();
#define K14 cout << "RED is the winner!" << endl; getch();
#define KLP fprintf(P, "\n");
#define KOR cout << "Choose the pawn you want to move by " << oIle*kolor->M << "positions. Here are your options:" << endl;

struct gracz
{
    int pionki[25]= {0};
    bool ruch=false;
    int wynik=0;
    int M=1;
    int a=0;
    int b=0;
    int mozliweRuchy[25]= {25};
    int LP=15;
};

//GRAFIKA
void wyswietlmenu()
{
    system("cls");
    gotoxy(10,1);
    cout << "WITAJ W GRZE";
    gotoxy(12,3);
    cout << "NEW GAME";
    gotoxy(9,4);
    cout << "LOAD SAVED GAME";
    gotoxy(10,5);
    cout << "EXIT THE GAME";
    gotoxy(10,6);
}

int menu()
{
    int i=3;
    char strzalka;
    do
    {
        wyswietlmenu();
        gotoxy(1,i);
        cout << "--->";
        gotoxy(28,i);
        cout << "<---";

        strzalka=getch();
        switch(strzalka)
        {
        case 13:
            return i;
            break;
        case 80:
            if(i<5)
                i++;
            break;
        case 72:
            if(i>3)
                i--;
            break;
        default:
            break;
        }
    }
    while(true);
}

void plansza()
{
    system("cls");
    gotoxy(1,1);
    for(int i=13; i<25; i++)
    {
        if(i==19)
            cout << "   ";
        cout << " " << i;
    }
    cout << endl;

    for(int i=0; i<14; i++)
    {
        if(i==0 || i==13)
            cout << "#########################################" << endl;
        else if(i<6)
            cout << "# v  v  v  v  v  v # # v  v  v  v  v  v #" << endl;
        else if(i==6 || i==7)
            cout << "#                  # #                  #" << endl;
        else
            cout << "# ^  ^  ^  ^  ^  ^ # # ^  ^  ^  ^  ^  ^ #" << endl;
    }

    for(int i=12; i>0; i--)
    {
        if(i==6)
            cout << "   ";
        if(i>9)
            cout << " " << i;
        else
            cout << "  " << i;
    }
    cout << endl;
}

void wstawp(char znak,int i,int ile)
{
    for(int j=0; j<ile; j++)
    {
        if(j>4)
        {
            gotoxy(42-3*i,9);
            cout << ile-5;
        }
        else
        {
            gotoxy(42-3*i,14-j);
            cout << znak;
        }
    }

}

void wstawd(char znak,int i,int ile)
{
    for(int j=0; j<ile; j++)
    {
        if(j>4)
        {
            gotoxy(39-3*i,9);
            cout << ile-5;
        }
        else
        {
            gotoxy(39-3*i,14-j);
            cout << znak;
        }

    }
}

void wstawt(char znak,int i,int ile)
{
    for(int j=0; j<ile; j++)
    {
        if(j>4)
        {
            gotoxy((i-12)*3,8);
            cout << ile-5;
        }
        else
        {
            gotoxy((i-12)*3,3+j);
            cout << znak;
        }
    }
}

void wstawc(char znak,int i,int ile)
{
    for(int j=0; j<ile; j++)
    {
        if(j>4)
        {
            gotoxy((i-11)*3,8);
            cout << ile-5;
        }
        else
        {
            gotoxy((i-11)*3,3+j);
            cout << znak;
        }

    }
}

void wstaw(char znak,int i,int ile)
{
    if(i<13)
    {
        if(i<7)
        {
            wstawp(znak,i,ile);
        }

        if(i>6)
        {
            wstawd(znak,i,ile);
        }
    }

    if(i>12)
    {
        if(i<19)
        {
            wstawt(znak,i,ile);
        }

        if(i>18)
        {
            wstawc(znak,i,ile);
        }
    }
}

void pionki(struct gracz *white,struct gracz *red)
{
    for(int i=1; i<25; i++)
    {
        if(white->pionki[i]>0)
        {
            wstaw('W',i,white->pionki[i]);
        }
        if(red->pionki[i]>0)
        {
            wstaw('R',i,red->pionki[i]);
        }
    }
}

void wylosowane(struct gracz *K)
{
    gotoxy(55,7);
    cout << "Rolled numbers: " << K->a*K->M << " and " << K->b*K->M;
    gotoxy(1,22);
}

void dodatkoweInfo(struct gracz *white,struct gracz *red)
{
    gotoxy(55,1);
    cout << "WHITE - " << white->LP << " : " << red->LP << " - RED";

    gotoxy(55,3);
    cout << "BEATEN PAWNS:  ";

    gotoxy(55,4);
    cout << "WHITE: " << white->pionki[0];

    gotoxy(55,5);
    cout << "RED: " << red->pionki[0];

    gotoxy(55,9);

    cout << "NOW PLAYING: ";
    if(white->ruch)
        cout << " WHITE" << endl;
    else
        cout << " RED" << endl;
}

void wyrysujPlansze(struct gracz *white,struct gracz *red)
{
    plansza();
    pionki(white,red);
    dodatkoweInfo(white,red);
    gotoxy(1,20);
}

//FUNKCJONALNOSCI
int newgameWarning()
{
    FILE *historia;
    historia=fopen("historia.txt","w+");
    fclose(historia);
    bool stop=false;
    int i=0;
    do
    {
        system("cls");
        gotoxy(10,1);
        cout << "This option will overwrite the last saved game. Do you want to continue?";
        gotoxy(10,3);
        cout << "YES";
        gotoxy(10,4);
        cout << "NO";
        gotoxy(15,i+3);
        cout << "<--";
        char strzalka;

        strzalka=getch();

        switch(strzalka)
        {
        case 13:
            stop=true;;
            break;
        case 80:
            if(i==0)
                i++;
            break;
        case 72:
            if(i==1)
                i--;
            break;
        default:
            break;
        }
    }
    while(!stop);
    return i;
}


int losowanie()
{
    int a;
    a=rand()%6+1;
    a=rand()%6+1;
    a=rand()%6+1;
    return a;
}

int rzucKoscmi(struct gracz *kolor, struct gracz *przeciwnik)
{
    cout << "Press any key to roll a dice..." << endl;
    getch();
    int a=losowanie();
    int b=losowanie();
    cout << "Your numbers are: " << a << " and " << b << endl;
    kolor->a=a;
    kolor->b=b;
}

bool czyBicieA(struct gracz *kolor, struct gracz *przeciwnik)
{
    bool a=false;
    int oIle=kolor->a;
    for(int i=1; i<25; i++)
    {
        if(kolor->pionki[i]>0)
        {
            if(i+oIle<25 && i+oIle>0)
            {
                if(przeciwnik->pionki[i+oIle]==1)
                {
                    a=true;
                }
            }
        }
    }
    return a;
}

bool czyBicieB(struct gracz *kolor, struct gracz *przeciwnik)
{
    bool b=false;
    int oIle=kolor->b;
    for(int i=1; i<25; i++)
    {
        if(kolor->pionki[i]>0)
        {
            if(i+oIle<25 && i+oIle>0)
            {
                if(przeciwnik->pionki[i+oIle]==1)
                {
                    b=true;
                }
            }
        }
    }
    return b;
}

void zwykleRuchy(struct gracz *kolor, struct gracz *przeciwnik,int oIle)
{
    for(int i=0; i<25; i++)
        kolor->mozliweRuchy[i]=0;

    for(int i=1; i<25; i++)
    {
        if(kolor->pionki[i]>0)
        {
            if(i+oIle<25 && i+oIle>0)
            {
                if(przeciwnik->pionki[i+oIle]<=1)
                {
                    kolor->mozliweRuchy[i]=1;
                    cout << i << endl;
                }

            }
        }
    }
}

int ruszaj(struct gracz *kolor, struct gracz *przeciwnik,int oIle)
{
    KOR
    zwykleRuchy(kolor,przeciwnik,oIle);
    int n;
    bool czydasie=false;
    for(int i=1; i<25; i++)
    {
        if(kolor->mozliweRuchy[i]!=0)
        {
            czydasie=true;
        }
    }

    if(!czydasie)
    {
        cout << "You need to give up this dice" << endl;
        getch();
    }
    else
    {
        while(true)
        {
            cin >> n;
            for(int i=1; i<25; i++)
            {
                if(n==i && kolor->mozliweRuchy[i]==1)
                {
                    kolor->pionki[n]--;
                    kolor->pionki[n+oIle]++;
                    if(przeciwnik->pionki[n+oIle]==1)
                    {
                        przeciwnik->pionki[n+oIle]=0;
                    }
                    return 0;
                }
            }
            cout << "Error. Choose correct pawn" << endl;
        }
    }
}

int ilewDomu(struct gracz *kolor)
{
    int i=0;
    int suma=0;
    if(kolor->M==1)
    {
        i=19;
    }
    else
    {
        i=1;
    }

    for(int j=0; j<6; j++)
    {
        suma=suma+kolor->pionki[i+j];
    }
    return suma;
}
void zbij(struct gracz *kolor, struct gracz *przeciwnik,int bijacy, int bity)
{
    kolor->pionki[bijacy]--;
    kolor->pionki[bity]++;
    przeciwnik->pionki[bity]--;
    przeciwnik->pionki[0]++;
}

void wKostke(struct gracz *kolor)
{
    cout << "Choose which dice you want to use first. Type 1 or 2" << endl;
    bool stop=false;
    int n;
    int cache;
    while(!stop)
    {
        cin >> n;
        switch(n)
        {
        case 1:
            stop=true;
            break;
        case 2:
            stop=true;
            cache=kolor->a;
            kolor->a=kolor->b;
            kolor->b=cache;
            break;
        default:
            cout << "Error.Type 1 or 2" << endl;
            break;
        }
    }
}
void zamien(struct gracz *kolor)
{
    int cache;
    cache=kolor->a;
    kolor->a=kolor->b;
    kolor->b=cache;
}


void zdejmijZBandy(struct gracz *K, struct gracz *przeciwnik)
{
    KO4;
    int A,B;

    if(K->M==-1)
    {
        A=25+K->a;
        B=25+K->b;
    }
    else
    {
        A=K->a;
        B=K->b;
    }

    bool a=przeciwnik->pionki[A]<2;
    bool b=przeciwnik->pionki[B]<2;
    bool possible=true;
    if(a&&b)
    {
        wKostke(K);
        if(K->M==-1)
        {
            A=25+K->a;
            B=25+K->b;
        }
        else
        {
            A=K->a;
            B=K->b;
        }
    }
    else if(a)
    {
        KO5;
        getch();
    }
    else if(b)
    {
        KO6;
        getch();
        zamien(K);
        if(K->M==-1)
        {
            A=25+K->a;
            B=25+K->b;
        }
        else
        {
            A=K->a;
            B=K->b;
        }
    }
    else
    {
        FF;
        getch();
        possible=false;
    }

    if(przeciwnik->pionki[A]==1&&possible)
    {
        zbij(K,przeciwnik,0,A);
    }
    else if(possible)
    {
        K->pionki[0]--;
        K->pionki[A]++;
    }
}

int ND(struct gracz *kolor)
{
    int result=0;
    if(kolor->M==1)
    {
        for(int j=1; j<=6; j++)
        {
            if(kolor->pionki[25-j]>0)
                result=j;
        }
    }
    else
    {
        for(int j=1; j<=6; j++)
        {
            if(kolor->pionki[j]>0)
                result=j;
        }
    }

    return result;
}
void naDwor1(struct gracz *K, struct gracz *przeciwnik)
{
    KZDEJMIJ
    getch();

    bool a,b,a2,b2;
    int A,B,C;
    if(K->M==1)
    {
        A=25-K->a;
        B=25-K->b;
        C=25-ND(K);
    }
    else
    {
        A=K->a*(-1);
        B=K->b*(-1);
        C=ND(K);
    }

    a=K->pionki[A]>0;
    b=K->pionki[B]>0;
    a2=ND(K)<K->a*K->M;
    b2=ND(K)<K->b*K->M;

    if(a)
    {
        KO1;
        getch();
        K->pionki[A]--;
        K->LP--;
    }
    else if(b)
    {
        KO2;
        getch();
        zamien(K);
        if(K->M==1)
        {
            A=25-K->a;
        }
        else
        {
            A=K->a*(-1);
        }
        K->pionki[A]--;
        K->LP--;
    }
    else if(a2)
    {
        KO3;
        getch();
        K->pionki[C]--;
        K->LP--;
    }
    else if(b2)
    {
        zamien(K);
        KO3;
        getch();
        K->pionki[C]--;
        K->LP--;
    }
    else
    {
        ruszaj(K,przeciwnik,K->a);
    }
}

void naDwor2(struct gracz *kolor, struct gracz *przeciwnik)
{
    int B,C;
    if(kolor->M==1)
    {
        B=25-kolor->b;
        C=25-ND(kolor);
    }
    else
    {
        B=kolor->b*(-1);
        C=ND(kolor);
    }

    bool b=false,b2=false;
    b=kolor->pionki[B]>0;
    b2=ND(kolor)<kolor->b*kolor->M;

    if(b)
    {
        cout << "You can take of the pawn from position " << B << " using dice: " << kolor->b << endl;
        getch();
        kolor->pionki[B]--;
        kolor->LP--;
    }
    else if(b2)
    {
        cout << "You can take of the pawn from position " << C << " using dice: " << kolor->b << endl;
        getch();
        zamien(kolor);
        kolor->pionki[C]--;
        kolor->LP--;
    }
    else
    {
        ruszaj(kolor,przeciwnik,kolor->b);
    }
}

int MBP(struct gracz *kolor, struct gracz *przeciwnik,int oIle)
{
    int result=0;
    for(int i=1; i<25; i++)
    {
        if(kolor->pionki[i]>0)
        {
            if(i+oIle<25 && i+oIle>0)
            {
                if(przeciwnik->pionki[i+oIle]==1)
                {
                    kolor->mozliweRuchy[i]=1;
                    if(i+oIle>result)
                        result=i+oIle;
                }
            }
        }
    }
    return result;
}

int MBM(struct gracz *kolor, struct gracz *przeciwnik,int oIle)
{
    int result=25;
    for(int i=24; i>=1; i--)
    {
        if(kolor->pionki[i]>0)
        {
            if(i+oIle<25 && i+oIle>0)
            {
                if(przeciwnik->pionki[i+oIle]==1)
                {
                    kolor->mozliweRuchy[i]=1;
                    if(i+oIle<result)
                        result=i+oIle;
                }
            }
        }
    }
    return result;
}
void bij(struct gracz *kolor, struct gracz *przeciwnik,int oIle)
{

    int x;
    if(kolor->M==1)
        x=MBP(kolor,przeciwnik,oIle);
    else
        x=MBM(kolor,przeciwnik,oIle);

    cout << "You have to beat opponent's pawn on place: " << x << " using pawn on place " << x-oIle << endl;
    getch();
    zbij(kolor,przeciwnik,x-oIle,x);
}

void zdejmijZBandy2(struct gracz *kolor, struct gracz *przeciwnik)
{
    cout << "You have some pawns out of board..." << endl;
    getch();

    int B;
    if(kolor->M==-1)
    {
        B=25-kolor->b;
    }
    else
    {
        B=kolor->b;
    }

    if(przeciwnik->pionki[B]<2)
    {
        cout << "You can move your pawn to position: " << B << endl;
        getch();
        if(przeciwnik->pionki[B]==1)
        {
            zbij(kolor,przeciwnik,0,B);
        }
        else
        {
            kolor->pionki[0]--;
            kolor->pionki[B]++;
        }
    }
    else
    {
        cout << "You have to give up this dice" << endl;
        getch();
    }

}
void Ruch2(struct gracz *kolor, struct gracz *przeciwnik,struct gracz *white, struct gracz *red)
{
    system("cls");
    wyrysujPlansze(white,red);
    wylosowane(kolor);
    if(ilewDomu(kolor)==kolor->LP)
    {
        naDwor2(kolor,przeciwnik);
    }
    else if(kolor->pionki[0]>0)
    {
        zdejmijZBandy2(kolor,przeciwnik);
    }
    else if(czyBicieB(kolor,przeciwnik))
    {
        bij(kolor,przeciwnik,kolor->b);
    }
    else
    {
        ruszaj(kolor,przeciwnik,kolor->b);
    }

    kolor->ruch=false;
    przeciwnik->ruch=true;
}


void pierwszyRuch(struct gracz *K, struct gracz *P,struct gracz *white, struct gracz *red)
{
    K->a=K->a*K->M;
    K->b=K->b*K->M;
    bool a=czyBicieA(K,P);
    bool b=czyBicieB(K,P);

    wylosowane(K);

    gotoxy(1,25);
    if(ilewDomu(K)==K->LP)
    {
        naDwor1(K,P);
    }
    else if(K->pionki[0]>0)
    {
        zdejmijZBandy(K,P);
    }
    else if(a & b)
    {
        if(K->M==1)
        {
            int x=MBP(K,P,K->a);
            int y=MBP(K,P,K->b);
            if(y>x)
            {
                zamien(K);
            }
            bij(K,P,K->a);
        }
        else
        {
            int x=MBM(K,P,K->a);
            int y=MBM(K,P,K->b);
            if(y<x)
            {
                zamien(K);
            }
            bij(K,P,K->a);
        }
    }
    else if(a)
    {
        bij(K,P,K->a);
    }
    else if(b)
    {
        zamien(K);
        bij(K,P,K->a);
    }
    else
    {
        wKostke(K);
        ruszaj(K,P,K->a);
    }
    Ruch2(K,P,white,red);
}

int czyKoniecGry(struct gracz *white, struct gracz *red)
{
    if(white->LP<=0)
    {
        return 1;
    }
    if(red->LP<=0)
    {
        return 2;
    }
    return 0;
}

void dublet(struct gracz *kolor, struct gracz *przeciwnik, struct gracz *white, struct gracz *red)
{
    kolor->b=kolor->b*kolor->M;
    kolor->a=kolor->a*kolor->M;
    for(int i=0; i<4; i++)
    {

        cout << "You have rolled the same numbers. Moves left: " << 4-i << endl;
        getch();
        system("cls");
        wylosowane(kolor);
        wyrysujPlansze(white,red);
        if(ilewDomu(kolor)==kolor->LP)
        {
            naDwor2(kolor,przeciwnik);
        }
        else if(kolor->pionki[0]>0)
        {
            zdejmijZBandy2(kolor,przeciwnik);
        }
        else if(czyBicieB(kolor,przeciwnik))
        {
            bij(kolor,przeciwnik,kolor->b);
        }
        else
        {
            ruszaj(kolor,przeciwnik,kolor->b);
        }
    }
    kolor->ruch=false;
    przeciwnik->ruch=true;
}

void save(struct gracz *W, struct gracz *R, FILE *P)
{
    P = fopen("savedGame.txt", "w+");

    for (int i = 0; i < 25; i++)
    {
        fprintf(P, "%d", W->pionki[i]);
        KLP
    }

    for (int i = 0; i < 25; i++)
    {
        fprintf(P, "%d", R->pionki[i]);
        KLP
    }

    fprintf(P, "%d", W->ruch);
    KLP
    fprintf(P, "%d", W->wynik);
    KLP
    fprintf(P, "%d", W->M);
    KLP
    fprintf(P, "%d", W->a);
    KLP
    fprintf(P, "%d", W->b);
    KLP
    fprintf(P, "%d", W->LP);
    KLP

    fprintf(P, "%d", R->ruch);
    KLP
    fprintf(P, "%d", R->wynik);
    KLP
    fprintf(P, "%d", R->M);
    KLP
    fprintf(P, "%d", R->a);
    KLP
    fprintf(P, "%d", R->b);
    KLP
    fprintf(P, "%d", R->LP);
    KLP

    fclose(P);
}
void HS(struct gracz *white, struct gracz *red,struct gracz *oldW, struct gracz *oldR)
{
    int r;
    FILE *historia;
    historia=fopen("historia.txt","a");
    for(int i=0;i<25;i++)
    {
        if(white->pionki[i]!=oldW->pionki[i])
        {
            if(white->pionki[i]>oldW->pionki[i])
            {
                r=white->pionki[i]-oldW->pionki[i];
                fprintf(historia,"W %d %d ",i,r);
            }
            else
            {
                r=white->pionki[i]-oldW->pionki[i];
                fprintf(historia,"W %d %d ",i,r);
            }
        }
    }
    for(int i=0;i<25;i++)
    {
        if(red->pionki[i]!=oldR->pionki[i])
        {
            r=red->pionki[i]-oldR->pionki[i];
            fprintf(historia,"R %d %d ",i,r);
        }
    }
    fprintf(historia,"\n");
    fclose(historia);
}
void losstart(struct gracz *white, struct gracz *red)
{
    int a=0;
    int b=0;
    while(a==b)
    {
        a=losowanie();
        b=losowanie();
    }
    cout << "WHITE HAS ROLLED... ";
    getch();
    cout << a << endl;

    cout << "RED HAS ROLLED...";
    getch();
    cout << b << endl;

    if(a>b)
    {
        cout << "WHITE STARTS";
        getch();
    }
    else
    {
       cout << "RED STARTS";
        white->ruch=false;
        red->ruch=true;
        getch();

    }
}
int newgame(struct gracz *white,struct gracz *red,FILE *plik)
{
    plik = fopen("savedGame.txt","w+");


    if(newgameWarning()==1)
        return 0;
    system("cls");

    white->pionki[1]=2;
    white->pionki[12]=5;
    white->pionki[17]=3;
    white->pionki[19]=5;

    white->M=1;
    white->ruch=true;
    white->LP=15;

    red->pionki[6]=5;
    red->pionki[8]=3;
    red->pionki[13]=5;
    red->pionki[24]=2;
    red->M=-1;
    red->ruch=false;
    red->LP=15;

    losstart(white,red);
    return 1;
}

int gra(struct gracz *white, struct gracz *red,FILE *plik)
{
    struct gracz *K;
    struct gracz *P;
    struct gracz oldW,oldR;
    system("cls");
    K11


    while(czyKoniecGry(white,red)==0)
    {
        oldW=*white;
        oldR=*red;

        wyrysujPlansze(white,red);
        if(white->ruch)
        {
            K=white;
            P=red;
        }
        else
        {
            K=red;
            P=white;
        }

        bool stop=false;
        K12
        int n;
        while(!stop)
        {
            cin >> n;
            switch(n)
            {
            case 1:
                rzucKoscmi(K,P);
                stop=true;
                break;
            case 2:
                save(white,red,plik);
                stop=true;
                exit(25);
                break;
            default:
                break;
            }
        }
        if(K->a==K->b)
        {
            dublet(K,P,white,red);
        }
        else
        {
            pierwszyRuch(K,P,white,red);
        }
        HS(white,red,&oldW,&oldR);
    }

    if(czyKoniecGry(white,red)==1)
    {
        system("cls");
        K13
        getch();
        return 0;
    }
    else
    {
        system("cls");
        K14
        return 0;
    }
}



int loadWarning()
{
    bool stop=false;
    int i=0;
    do
    {
        system("cls");
        gotoxy(10,1);
        cout << "This option will load saved game. Do you want to continue?";
        gotoxy(10,3);
        cout << "YES";
        gotoxy(10,4);
        cout << "NO";
        gotoxy(15,i+3);
        cout << "<--";
        char strzalka;

        strzalka=getch();

        switch(strzalka)
        {
        case 13:
            stop=true;;
            break;
        case 80:
            if(i==0)
                i++;
            break;
        case 72:
            if(i==1)
                i--;
            break;
        default:
            break;
        }
    }
    while(!stop);
    return i;
}

void podstaw(struct gracz *W,char BR[][4])
{
    W->ruch = atoi(BR[0]);
    W->wynik = atoi(BR[1]);
    W->M = atoi(BR[2]);
    W->a = atoi(BR[3]);
    W->b = atoi(BR[4]);
    W->LP = atoi(BR[5]);
}
int load(struct gracz *W, struct gracz *R, FILE *P)
{
    P = fopen("savedGame.txt", "r");

    if (loadWarning() == 1)
        return 0;

    char B[25][4];
    char CZ[25][4];
    char BR[7][4];
    char CZR[7][4];

    for (int i = 0; i < 25; i++)
    {
        fgets(B[i], 4, P);
        W->pionki[i] = atoi(B[i]);
    }
    for (int i = 0; i < 25; i++)
    {
        fgets(CZ[i], 4, P);
        R->pionki[i] = atoi(CZ[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        fgets(BR[i], 4, P);
    }
    for (int i = 0; i < 6; i++)
    {
        fgets(CZR[i], 4, P);
    }

    podstaw(W,BR);
    podstaw(R,CZR);
}
int start(struct gracz *white, struct gracz *red)
{
    while(true)
    {
        FILE *plik;
        bool start=false;
        while(!start)
        {
            switch(menu())
            {
            case 3:
                if(newgame(white,red,plik))
                    start=true;
                break;
            case 4:
                load(white,red,plik);
                start=true;
                break;
            case 5:
                return 0;
                break;
            }
        }
        gra(white,red,plik);
    }

    return 0;
}

int main()
{
    srand(time(NULL));
    struct gracz white;
    struct gracz red;
    start(&white,&red);


    gotoxy(20,40);
    cout << endl;
    return 0;
}
