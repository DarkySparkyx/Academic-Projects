package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;

public class WietrznaGran extends Wedrowka {

    /**
     * @param odleglosc - długość wędrówki w GOTach
     */
    public WietrznaGran(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public String getNazwa()
    {
        return "Wietrzna grań. Wiatr nam nieco pomoże";
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        return predkosc*1.3;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 1;
    }
}
