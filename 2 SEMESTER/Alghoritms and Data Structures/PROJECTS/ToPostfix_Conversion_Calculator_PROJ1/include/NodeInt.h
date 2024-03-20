#include <iostream>

using namespace std;

class NodeInt
{
private:
    int data;
    NodeInt* next;
public:
    NodeInt();
    NodeInt(int data);
    NodeInt(int data,NodeInt* next);
    NodeInt* GetNext();
    int GetData();
};
