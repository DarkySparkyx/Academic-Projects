#include <iostream>

class FiguraPlaska
{
protected:
    virtual void Wypisz(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const FiguraPlaska&
                                    figura);
public:
    virtual double Pole() const = 0;
    virtual double Obwod() const = 0;
    virtual ~FiguraPlaska();
};

class Prostokat : public FiguraPlaska
{
private:
    double a,b;
protected:
    void Wypisz(std::ostream& out) const override;
public:
    Prostokat(double a, double b);
    double GetA() const;
    void SetA(double a);
    double GetB() const;
    void SetB(double b);
    double Obwod() const override;
    double Pole() const override;
    ~Prostokat() override;
};

class Trojkat : public FiguraPlaska
{
    int a,b,c;

protected:
    void Wypisz(std::ostream& out) const override;

public:
    Trojkat(double a,double b,double c);
    void setA(double a);
    void setB(double a);
    void setC(double a);
    double getA() const;
    double getB() const;
    double getC() const;

    double Obwod() const override;
    double Pole() const override;
    ~Trojkat() override;
};

class Kolo : public FiguraPlaska
{
    int r;

protected:
    void Wypisz(std::ostream& out) const override;

public:
    Kolo(double r);
    void setR(double r);
    double getR() const;
    double Obwod() const override;
    double Pole() const override;
    ~Kolo() override;
};

class Bryla
{
protected:
    virtual void Wypisz(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Bryla& bryl);
public:
    virtual double Pole_powierzchni() const = 0;
    virtual ~Bryla();
};

class Stozek : public Bryla
{
private:
    double h,r;
protected:
    void Wypisz(std::ostream& out) const override;
public:
    Stozek(double h,double r);
    void setR(double r);
    void setH(double h);
    double getR() const;
    double getH() const;
    double Tworzaca() const;
    double pole_podstawy() const;
    double Pole_powierzchni() const override;
    double Pole_powierzchni_bocznej() const;
    ~Stozek() override;

};
