#include <iostream>
#include <vector>
#include <algorithm>

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

class Graph
{
    vector<int>* vertexes;
    int numberOfVertexes;
    int* degreeTable;
    bool* visited;
    int numberOfComponents;
    int lastChecked;

public:

    void setVisitedToZero()
    {
        for(int i=0; i<numberOfVertexes; i++)
        {
            visited[i]=false;
        }
    }

    Graph()
    {
        lastChecked=0;
        cin >> numberOfVertexes;
        vertexes = new vector<int>[numberOfVertexes];
        degreeTable = new int[numberOfVertexes];
        visited = new bool[numberOfVertexes];

        setVisitedToZero();
        for(int i=0; i<numberOfVertexes; i++)
        {
            int howManyNeighbours;
            cin >> howManyNeighbours;
            degreeTable[i]=howManyNeighbours;
            for(int j=0; j<howManyNeighbours; j++)
            {
                int neighbour;
                cin >> neighbour;
                vertexes[i].push_back(neighbour-1);
            }
        }

        calculateNumberOfComponents();
    }

    void sortDegreeTable()
    {
        sort(degreeTable,degreeTable+numberOfVertexes, greater<int>());
        for(int i=0; i<numberOfVertexes; i++)
        {
            cout << degreeTable[i] << " ";
        }
    }

    void visitVertex(int vertex)
    {
        if(!visited[vertex])
        {
            visited[vertex]=true;
            for(int i=0; i<vertexes[vertex].size(); i++)
            {
                visitVertex(vertexes[vertex][i]);
            }
        }

    }

    int checkIfAllWereVisited()
    {
        for(int i=lastChecked; i<numberOfVertexes; i++)
        {
            if(!visited[i])
            {
                return i;
            }
        }
        return -1;
    }

    void calculateNumberOfComponents()
    {
        numberOfComponents=0;
        int vertex;
        while(vertex=checkIfAllWereVisited(),vertex!=-1)
        {
            numberOfComponents++;
            visitVertex(vertex);
        }
    }

    void printGraph()
    {
        cout << numberOfVertexes << endl;

        for(int i=0; i<numberOfVertexes; i++)
        {
            cout << vertexes[i].size() << " ";
            for(int j=0; j<vertexes[i].size(); j++)
            {
                cout << vertexes[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getNumberOfComponents()
    {
        return numberOfComponents;
    }
};

int main()
{
    int k;
    cin >> k;
    for(int i=0; i<k; i++)
    {
        Graph graf;
        //CIAG STOPNIOWY
        graf.sortDegreeTable();
        cout << endl;

        //LICZBA SKLADOWYCH SPOJNOSCI
        cout << graf.getNumberOfComponents() << endl;

        //DWUDZIELNOSC
        cout << "?" << endl;

        //ACENTRYCZNOSC
        cout << "?" << endl;

        //PLANARNOSC
        cout << "?" << endl;

        //ZACHLANNY
        cout << "?" << endl;

        //LF
        cout << "?" << endl;

        //SLF
        cout << "?" << endl;

        //C4
        cout << "?" << endl;

        //LICZBA KRAWEDZI DOPELNIENIA
        cout << "?" << endl;

        //KONIEC ZESTAWU
        cout << endl;
    }

    return 0;
}
