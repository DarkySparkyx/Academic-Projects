#include <iostream>
#include <cstring>
#include "PostfixProcessor.h"

using namespace std;

int main()
{
    int x;
    cin >> x;
    for(int i=0; i<x; i++)
    {
        PostfixProcessor procek;
        procek.Converter();
        procek.Calculator();
    }

    return 0;
}
