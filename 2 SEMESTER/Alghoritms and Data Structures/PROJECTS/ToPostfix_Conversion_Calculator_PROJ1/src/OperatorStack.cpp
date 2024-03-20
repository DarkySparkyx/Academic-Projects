#include <iostream>
#include "OperatorStack.h"

using namespace std;

OperatorStack::OperatorStack()
{
    top = nullptr;
}

bool OperatorStack::IsEmpty()
{
    return top==nullptr;
}

OperatorStack::~OperatorStack()
{
    delete top;
}

void OperatorStack::TopDelete()
{
    Operator* tmp = top;
    top=top->GetNext();
    delete tmp;
}

void OperatorStack::push(char* n)
{
    top = new Operator(n,top);
}

void OperatorStack::push(char n)
{
    top = new Operator(n,top);
}


void OperatorStack::pop(char* postfix,int* size)
{
    if(!IsEmpty())
    {
        Operator* tmp = top;
        top = top->GetNext();
        char* name = tmp->GetName();
        int i;
        for(i=0; name[i]!='\0'; i++)
        {
            postfix[*size+i]=name[i];
        }
        *size += i ;
        delete tmp;
    }

}

Operator* OperatorStack::GetTop()
{
    return top;
}
