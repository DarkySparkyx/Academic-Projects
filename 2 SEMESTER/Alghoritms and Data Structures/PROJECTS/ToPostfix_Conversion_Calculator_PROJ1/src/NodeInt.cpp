#include <iostream>
#include "NodeInt.h"

using namespace std;

NodeInt::NodeInt()
{
    data=INT_MIN;
    next=nullptr;
}
NodeInt::NodeInt(int data)
{
    this->data=data;
    next=nullptr;
}
NodeInt::NodeInt(int data, NodeInt* next) : data(data), next(next)
{

}
NodeInt* NodeInt::GetNext()
{
    return next;
}
int NodeInt::GetData()
{
    return data;
}
