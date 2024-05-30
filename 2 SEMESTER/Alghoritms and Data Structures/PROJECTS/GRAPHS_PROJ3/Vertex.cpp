#include <iostream>
#include "Vertex.h"

using namespace std;
Vertex::Vertex(int degree)
{
    this->degree=degree;
    color=-1;
    side=NEUTRAL;
    visited=false;
    neighbours = new int[degree];
    int cache;
    for(int i=0; i<degree; i++)
    {
        scanf("%d",&cache);
        neighbours[i]=cache-1;
    }
}

int Vertex::getDegree() const
{
    return degree;
}

int Vertex::getNeighbour(int val) const
{
    return neighbours[val];
}

int Vertex::getColor() const
{
    return color;
}

STRONA Vertex::getSide() const
{
    return side;
}

void Vertex::setColor(int val)
{
    color=val;
}

void Vertex::setSide(STRONA val)
{
    side=val;
}

bool Vertex::wasVisited() const
{
    return visited;
}

void Vertex::setVisited(bool val)
{
    visited=val;
}

Vertex::~Vertex()
{
    delete[] neighbours;
}
