#include <iostream>
#include <cstring>
#include "Operator.h"

using namespace std;

int Operator::SetPrio()
{
    int pri[11] = {1,1,2,2,-1,-1,4,4,-1,3,3};
    return pri[code];
}

void Operator::AddNumber(int liczba)
{
    char* tmp = name;
    name = new char[30];
    snprintf(name,13,"%s%d\0",tmp,liczba+1);
    delete tmp;
}
int Operator::SetCode()
{
    switch(name[0])
        {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        case 'M':
            if(name[1]=='A')
                return 6;
            else
                return 7;
        case ',':
            return 8;
        case 'N':
            return 9;
        case 'I':
            return 10;
        default:
            return -1;
        }
    }

Operator::Operator(char n,Operator* next)
{
    name = new char[2];
    name[0]=n;
    name[1]='\0';

    this->next=next;
    code=SetCode();
    prio=SetPrio();
}

Operator::Operator(char* n,Operator* next)
{
    int i=strlen(n);
    name = new char[i+1];
    for(int j=0; j<i; j++)
    {
        name[j]=n[j];
    }
    name[i]='\0';

    this->next=next;
    code=SetCode();
    prio=SetPrio();
}

int Operator::GetCode()
{
    return code;
}

int Operator::GetPrio()
{
    return prio;
}
char* Operator::GetName()
{
    return name;
}

Operator* Operator::GetNext()
{
    return next;
}

Operator::~Operator()
{
    delete[] name;
}
