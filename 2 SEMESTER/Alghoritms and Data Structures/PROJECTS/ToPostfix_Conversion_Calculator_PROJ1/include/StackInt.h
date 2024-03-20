#include <iostream>
#include "NodeInt.h"

using namespace std;

class StackInt
{
private:
    NodeInt* top;
public:
    StackInt();
    void push(int data);
    int pop();
    bool IsEmpty();
    void ShowContent();
    int peek();
};
