#pragma once
#include <iostream>

using namespace std;

int Parent(int i)
{
    return i/2;
}

int LeftChild(int i)
{
    return i*2;
}

int RightChild(int i)
{
    return i*2+1;
}

int Heapify(int* Heap,int size, int i)
{
    int L=LeftChild(i);
    int R=RightChild(i);
    int maxi=i;

    if(i*2>size)
    {
        return 0;
    }
    if(Heap[L-1]>Heap[i-1])
    {
        maxi=L;
    }
    if(Heap[R-1]>Heap[maxi-1])
    {
        maxi=R;
    }
    if(maxi!=i)
    {
        swap(Heap[maxi-1],Heap[i-1]);
        Heapify(Heap,size,maxi);
    }
    return 9;
}
