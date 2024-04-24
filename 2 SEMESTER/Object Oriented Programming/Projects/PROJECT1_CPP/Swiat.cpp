#include <algorithm>
#include <string>
#include "Swiat.h"
#include <conio.h>
#include <fstream>

#include "Wilk.h"
#include "Lis.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Czlowiek.h"

#include "Trawa.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "WilczeJagody.h"

using namespace std;

Swiat::Swiat()
{
    cout << "SYMULATOR ZYCIA 2024 by MICHAl JASIAK" << endl;
    cout << "Podaj wymiary planszy, na ktorej chcesz przeprowadzić symulacje" << endl;
    cout << " X: ";
    cin >> this->x;
    while(x<5 || x>30)
    {
        cout << "Zly wymiar" << endl;
        cin >> this->x;
    }

    cout << " Y: ";
    cin >> this->y;
    while(y<5)
    {
        cout << "Zly wymiar" << endl;
        cin >> this->y;
    }
    tura=1;
    for(int i=0; i<2; i++)
    {
        DodajOrganizm(new Owca(0,0,this));
        DodajOrganizm(new Wilk(0,0,this));
        DodajOrganizm(new Lis(0,0,this));
        DodajOrganizm(new Antylopa(0,0,this));
        DodajOrganizm(new Zolw(0,0,this));
        DodajOrganizm(new Trawa(0,0,this));
        DodajOrganizm(new BarszczSosnowskiego(0,0,this));
        DodajOrganizm(new Mlecz(0,0,this));
        DodajOrganizm(new Guarana(0,0,this));
        DodajOrganizm(new WilczeJagody(0,0,this));
    }
    DodajOrganizm(new Czlowiek(0,0,this));
    Sprzatacz();

    rysujSwiat();
    getchar();
    getchar();
}

Swiat::Swiat(FILE* plik)
{
    int ile=0;
    fscanf(plik,"%d",&x);
    fseek(plik, 1, SEEK_CUR);
    fscanf(plik,"%d",&y);
    fseek(plik, 1, SEEK_CUR);
    fscanf(plik,"%d",&tura);
    fseek(plik, 1, SEEK_CUR);
    fscanf(plik,"%d",&ile);
    fseek(plik, 1, SEEK_CUR);

    cout << "x to" << x << endl;
    cout << "y to" << y << endl;
    cout << "tura to" << tura << endl;
    cout << "ile to:" << ile << endl;

    char znak;
    int newX,newY,wiek,alive;
    int czyUmiejetnoscAktywna,cooldown,czasTrwaniaUmiejetnosci;
    Organizm* temp;
    Czlowiek* tmp;

    for(int i=0; i<ile; i++)
    {
        fscanf(plik," %c %d %d %d %d)",&znak,&newX,&newY,&wiek,&alive);
        cout << znak << " " << newX << " " << newY << " " << wiek << " " << alive << endl;
        switch(znak)
        {
        case 'W':
            temp=new Wilk(newX, newY, this);
            std::cout << "Dodano Wilka na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'L':
            temp=new Lis(newX, newY, this);
            std::cout << "Dodano Lisa na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'O':
            temp=new Owca(newX, newY, this);
            std::cout << "Dodano Owce na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'C':
            temp=new Czlowiek(newX, newY, this);
            tmp = (Czlowiek*) temp;
            fscanf(plik," %d %d %d",&czyUmiejetnoscAktywna,&cooldown,&czasTrwaniaUmiejetnosci);
            tmp->setCzyUmiejetnoscJestAktywna(czyUmiejetnoscAktywna!=0);
            tmp->setCooldown(cooldown);
            tmp->setCzasTrwaniaUmiejetnosci(czasTrwaniaUmiejetnosci);
            std::cout << "Dodano Czlowieka na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'A':
            temp=new Antylopa(newX, newY, this);
            std::cout << "Dodano Antylope na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'Z':
            temp=new Zolw(newX, newY, this);
            std::cout << "Dodano Zolwia na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'T':
            temp=new Trawa(newX, newY, this);
            std::cout << "Dodano Trawe na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'M':
            temp=new Mlecz(newX, newY, this);
            std::cout << "Dodano Mlecz na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'G':
            temp=new Guarana(x, y, this);
            std::cout << "Dodano Guarane na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'B':
            temp=new BarszczSosnowskiego(newX, newY, this);
            std::cout << "Dodano Barszcz Sosnowskiego na polu (" << x << ", " << y << ")" << std::endl;
            break;
        case 'J':
            temp=new WilczeJagody(newX, newY, this);
            std::cout << "Dodano Wilcze Jagody na polu (" << x << ", " << y << ")" << std::endl;
            break;
        }
        DodajOrganizm(temp);
        temp->SetWiek(wiek);
        temp->SetAlive(alive!=0);
        fseek(plik, 1, SEEK_CUR);
    }
    Sprzatacz();

    rysujSwiat();
    bool czyJuz=false;
    for(auto org : organizmy)
    {
        if(org->GetSymbol()=='C' || czyJuz)
        {
            czyJuz=true;
            org->akcja();
        }
    }
    tura++;
    WyswietlLog();
    Sprzatacz();
    logi="";
    getch();
}

void Swiat::DodajOrganizm(Organizm* org)
{
    organizmy.push_back(org);
}

void Swiat::rysujSwiat() const
{
    system("cls");
    cout << "  ";
    //WYSWIETL 1 LINIE
    for(int i=0; i<x; i++)
    {
        if(i<9)
        {
            cout << " " << i+1 << " ";
        }
        else
        {
            cout << i+1 << " ";
        }
    }
    cout << endl << " ";
    //WYSWIETL GÓRNĄ GRANICE
    for(int i=0; i<x; i++)
    {
        cout << "  V";
    }
    cout << endl;
    //WYSWIETL LEWY BRZEG
    for(int i=0; i<y; i++)
    {
        if(i+1<10)
            cout << i+1 << " >" << endl;
        else
            cout << i+1 << ">" << endl;
    }

    //WYSWIETL ORGANIZMY
    for(auto& org : organizmy)
    {
        if(org->alive)
            org->rysowanie();
    }
}

void Swiat::wykonajTure()
{
    rysujSwiat();
    auto endit=organizmy.end();
    for(auto it=organizmy.begin(); it!=endit; it++)
    {
        if((*it)->alive)
        {
            (*it)->akcja();
        }
    }

    Sprzatacz();
    WyswietlLog();
    getch();
    logi="";
    tura++;
}

int Swiat::getX() const
{
    return x;
}

int Swiat::getY() const
{
    return y;
}

bool Swiat::CzyPoleZajete(int newX,int newY)
{
    auto result = find_if(organizmy.begin(),organizmy.end(),[&](Organizm* org)
    {
        return (org->X==newX && org->Y==newY);
    });
    bool test = result!=organizmy.end();
    return  result!=organizmy.end();
}

list<Organizm*>::iterator Swiat::znajdzOrganizm(int x, int y)
{
    return find_if(organizmy.begin(),organizmy.end(),[&](Organizm* org)
    {
        return (org->X==x && org->Y==y);
    });
}

void Swiat::DodajDoLog(string tekst)
{
    logi=logi+'\n'+tekst;
}

void Swiat::WyswietlLog()
{
    gotoxy(0,y+3);
    cout << "TURA: " << tura << endl;
    cout << logi;
}

Organizm* Swiat::getOrganizm(list<Organizm*>::iterator it)
{
    if(it==organizmy.end())
        return nullptr;
    else
        return *it;
}

void Swiat::gotoxy(int x,int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Swiat::zapiszDoPliku()
{
    fstream plik;
    plik.open("zapis.csv",ios::out);
    if(plik.good())
    {
        plik << this->x << endl;
        plik << this->y << endl;
        plik << this->tura << endl;

        int ile=0;
        for(auto org : organizmy)
        {
            ile++;
        }
        plik << ile << endl;

        for(auto org : organizmy)
        {
            plik << org->DoPliku() << endl;
        }
    }
}

void Swiat::Sprzatacz()
{
    auto endit=organizmy.end();
    for(auto it=organizmy.begin(); it!=endit;)
    {
        if(!(*it)->alive)
        {
            delete (*it);
            it=organizmy.erase(it);
        }
        else
        {
            it++;
        }
    }
    organizmy.sort(Organizm::prio);
}

Swiat::~Swiat()
{
    for(auto org : organizmy)
    {
        delete org;
    }
    delete this;
}
