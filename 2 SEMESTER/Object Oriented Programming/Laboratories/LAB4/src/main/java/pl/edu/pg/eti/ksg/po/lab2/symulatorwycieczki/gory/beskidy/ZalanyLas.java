package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;

public class ZalanyLas extends Wedrowka {

    /**
     * @param odleglosc - długość wędrówki w GOTach
     */
    public ZalanyLas(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public String getNazwa() {
        return "Zalany Las";
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        return predkosc*0.25;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 4;
    }
}
