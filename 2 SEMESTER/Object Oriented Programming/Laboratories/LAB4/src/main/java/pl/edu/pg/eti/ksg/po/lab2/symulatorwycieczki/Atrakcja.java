package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki;

public abstract class Atrakcja implements ElementWycieczki {
    double czasZwiedzania;
    String nazwa;

    public Atrakcja(String nazwa, double czasZwiedzania)
    {
        this.nazwa=nazwa;
        this.czasZwiedzania=czasZwiedzania;
    }
    public double getCzasZwiedzania() {
        return czasZwiedzania;
    }

    @Override
    public String getNazwa()
    {
        return nazwa;
    }
}
