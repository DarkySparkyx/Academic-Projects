#include <iostream>
#include <math.h>
#include <queue>

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

int main()
{
    int x=0;
    cin >> x;
    int Heap[100000];
    for(int i=0;i<x;i++)
    {
        cin >> Heap[i];
    }

    for(int i=x;i>=1;i--)
    {
        Heapify(Heap,x,i);
    }

    for(;x>0;)
    {
        cout << Heap[0] << " ";
        Heap[0]=Heap[x-1];
        x--;
        Heapify(Heap,x,1);
    }

    return 0;
}
