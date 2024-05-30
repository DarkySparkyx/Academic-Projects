#include <iostream>
#include "Graph.h"
#include <algorithm>

using namespace std;

void setTableToZero(int* table,int size)
{
    for(int i=0; i<size; i++)
    {
        table[i]=0;
    }
}

Graph::Graph()
{
    numberOfComponents=0;
    numberOfVertexes=0;
    liczbaKrawedzi=0;
    lastChecked=0;
    maxDegree=0;
    liczbaKrawedziDopelnienia=0;
    scanf("%d",&numberOfVertexes);
    vertexes = new Vertex*[numberOfVertexes];
    degreeTable = new int[numberOfVertexes];

    setTableToZero(degreeTable,numberOfVertexes);
    int degree;
    for(int i=0; i<numberOfVertexes; i++)
    {
        cin >> degree;
        if(degree>maxDegree)
        {
            maxDegree=degree;
        }
        liczbaKrawedzi=liczbaKrawedzi+(long long)degree;
        degreeTable[degree]++;
        vertexes[i]=new Vertex(degree);
    }

    liczbaKrawedzi=liczbaKrawedzi/2;
    liczbaKrawedziDopelnienia=((long long)numberOfVertexes*((long long)numberOfVertexes-1)/2)-liczbaKrawedzi;
}

void Graph::getSortedDegreeTable() const
{
    for(int i=numberOfVertexes-1; i>=0; i--)
    {
        for(int j=0; j<degreeTable[i]; j++)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
}

int Graph::wereAllVisited()
{
    for(int i=lastChecked; i<numberOfVertexes; i++)
    {
        if(!vertexes[i]->wasVisited())
        {
            lastChecked=i;
            return i;
        }
    }
    return numberOfVertexes;
}

void Graph::visitVertex(int vertex)
{
    vertexes[vertex]->setVisited(true);
    for(int i=0; i<vertexes[vertex]->getDegree(); i++)
    {
        if(!vertexes[vertexes[vertex]->getNeighbour(i)]->wasVisited())
        {
            visitVertex(vertexes[vertex]->getNeighbour(i));
        }
    }
}

void Graph::calculateNumberOfComponents()
{
    numberOfComponents=0;
    int i;
    while(i=wereAllVisited(),i!=numberOfVertexes)
    {
        numberOfComponents++;
        visitVertex(i);
    }
    printf("%d\n",numberOfComponents);
}

void Graph::getLiczbaKrawedziDoplenienia() const
{
    cout << liczbaKrawedziDopelnienia << endl;
}

STRONA getPrzeciwna(STRONA str)
{
    if(str==LEWA)
    {
        return PRAWA;
    }
    return LEWA;
}
bool Graph::trySetSide(int i, STRONA str)
{
    vertexes[i]->setSide(str);
    for(int j=0; j<vertexes[i]->getDegree(); j++)
    {
        if(vertexes[vertexes[i]->getNeighbour(j)]->getSide()==NEUTRAL)
        {
            if(!trySetSide(vertexes[i]->getNeighbour(j),getPrzeciwna(str)))
            {
                return false;
            }
        }
        else if(vertexes[vertexes[i]->getNeighbour(j)]->getSide()==str)
        {
            return false;
        }
    }
    return true;
}

int Graph::checkIfAllWereAsigned()
{
    for(int i=lastChecked; i<numberOfVertexes; i++)
    {
        if(vertexes[i]->getSide()==NEUTRAL)
        {
            lastChecked=i;
            return i;
        }
    }
    return numberOfVertexes;
}

void Graph::Bipartition()
{
    lastChecked=0;
    int vertex;
    bool result=true;

    while(vertex=checkIfAllWereAsigned(),vertex!=numberOfVertexes)
    {
        result=trySetSide(vertex,LEWA);
        if(!result)
        {
            break;
        }
    }

    if(result)
    {
        printf("T\n");
    }
    else
    {
        printf("F\n");
    }
}

void setTableToTrue(bool* table,int size)
{
    for(int i=0;i<size;i++)
    {
        table[i]=true;
    }
}
void Graph::naiveColoring()
{
    maxDegree=maxDegree+1;
    bool* avaiableColors = new bool[maxDegree];
    for(int i=0;i<numberOfVertexes;i++)
    {
        setTableToTrue(avaiableColors,maxDegree);
        for(int j=0;j<vertexes[i]->getDegree();j++)
        {
            int neighbourId=vertexes[i]->getNeighbour(j);
            int neighbourColor=vertexes[neighbourId]->getColor();
            if(neighbourColor!=-1)
            {
                avaiableColors[neighbourColor]=false;
            }
        }
        for(int j=0;j<maxDegree;j++)
        {
            if(avaiableColors[j])
            {
                vertexes[i]->setColor(j);
                break;
            }
        }
    }
    for(int i=0;i<numberOfVertexes;i++)
    {
        printf("%d ",vertexes[i]->getColor()+1);
    }
    printf("\n");
    delete[] avaiableColors;
}

Graph::~Graph()
{
    for(int i=0;i<numberOfVertexes;i++)
    {
        delete vertexes[i];
    }
    delete[] vertexes;
    delete[] degreeTable;
}
