#include <iostream>
#include "OperatorStack.h"
#include "StackInt.h"
using namespace std;

class PostfixProcessor
{
    public:
        PostfixProcessor();
        void Converter();
        void Calculator();
        ~PostfixProcessor();
    protected:
        void OperatorDetected(char input);
        int Dodawanie();
        int Odejmowanie();
        bool Dzielenie();
        int Mnozenie();
        int Maximum(int ile);
        int Minimum(int ile);
        int Warunek();
    private:
        char* postfix;
        int size;
        int memory;
        OperatorStack stos;
        StackInt StosInt;
};
