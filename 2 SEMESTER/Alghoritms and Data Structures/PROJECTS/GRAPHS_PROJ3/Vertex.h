#include <iostream>

enum STRONA
{
    NEUTRAL,
    LEWA,
    PRAWA,
};

class Vertex
{
    int degree;
    int* neighbours;
    int color;
    bool visited;
    STRONA side;

    public:
    explicit Vertex(int degree);
    int getDegree() const;
    int getNeighbour(int val) const;
    int getColor() const;
    STRONA getSide() const;
    void setColor(int val);
    void setSide(STRONA val);
    bool wasVisited() const;
    void setVisited(bool val);
    ~Vertex();
};
