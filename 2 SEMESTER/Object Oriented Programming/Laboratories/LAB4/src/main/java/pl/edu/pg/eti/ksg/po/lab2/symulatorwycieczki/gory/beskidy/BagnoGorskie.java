package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;

public class BagnoGorskie extends Wedrowka {
    /**
     * @param odleglosc - długość wędrówki w GOTach
     */
    public BagnoGorskie(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public String getNazwa() {
        return "Bagno Gorskie";
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        return 0.25*predkosc;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 4;
    }
}
