#include <iostream>
#include "Operator.h"

using namespace std;

class OperatorStack
{
private:
    Operator* top;
public:
    OperatorStack();
    ~OperatorStack();
    bool IsEmpty();
    void push(char* n);
    void push(char n);
    void pop(char*,int*);
    void TopDelete();
    Operator* GetTop();
};
