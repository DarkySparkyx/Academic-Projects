package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.ZalanyLas;

public class Hydrolog extends Czlowiek{
    public Hydrolog(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 4);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 5;
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        if(w instanceof ZalanyLas)
        {
            mow("Hmm, jestem na terenach podmokłych. Muszę przeprowadzić badania, więc bardziej się zmęczę: "+w.getNazwa());
            aktualizujZmeczenie(czas*2);
        }
        else
        {
            aktualizujZmeczenie(czas);
            mow("Hmm, wędrówka: "+w.getNazwa());
        }

    }
    @Override
    public void reagujNaAtrakcje(Atrakcja a) {
        super.regeneruj(a.getCzasZwiedzania());
        super.mow("Jestem na Atrakcji...");
    }
}
