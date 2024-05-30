#include <iostream>
#include "Vertex.h"

class Graph
{
    int numberOfComponents;
    int numberOfVertexes;
    long long liczbaKrawedzi;
    long long liczbaKrawedziDopelnienia;
    Vertex** vertexes;
    int* degreeTable;
    int lastChecked;
    int maxDegree;

    public:
    Graph();
    void getSortedDegreeTable() const;
    int wereAllVisited();
    void visitVertex(int vertex);
    void calculateNumberOfComponents();
    void getLiczbaKrawedziDoplenienia() const;
    bool trySetSide(int i,STRONA str);
    int checkIfAllWereAsigned();
    void Bipartition();
    void naiveColoring();
    ~Graph();
};
