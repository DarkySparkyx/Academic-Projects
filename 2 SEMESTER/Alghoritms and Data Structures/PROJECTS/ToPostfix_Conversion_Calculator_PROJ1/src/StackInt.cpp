#include <iostream>
#include "StackInt.h"

using namespace std;

StackInt::StackInt()
{
    top = nullptr;
}

bool StackInt::IsEmpty()
{
    return top->GetNext()==nullptr;
}

void StackInt::push(int data)
{
    NodeInt* tmp = new NodeInt(data,top);
    top = tmp;
}

int StackInt::pop()
{
        NodeInt* tmp = top;
        int result = top->GetData();
        top=top->GetNext();
        delete tmp;
        return result;
}

int StackInt::peek()
{
    return top->GetData();
}

void StackInt::ShowContent() {
    NodeInt* tmp = top;
    while (tmp != nullptr) {
        printf("%d ",tmp->GetData());
        tmp = tmp->GetNext();
    }
    printf("\n");
}
