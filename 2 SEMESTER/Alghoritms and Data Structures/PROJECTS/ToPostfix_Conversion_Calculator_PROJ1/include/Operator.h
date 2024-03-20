#include <iostream>

using namespace std;

class Operator
{
private:
    int prio,code;
    char* name;
    Operator* next;
protected:
    int SetCode();
    int SetPrio();
public:
    Operator(char* n,Operator* next);
    Operator(char n,Operator* next);
    ~Operator();
    int GetPrio();
    int GetCode();
    char* GetName();
    void AddNumber(int liczba);
    Operator* GetNext();
};
