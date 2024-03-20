package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.BagnoGorskie;

public class BagiennyBiegacz extends Czlowiek{
    public BagiennyBiegacz(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 6, 12, 20);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 5;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a) {
            super.mow("Jestem na Atrakcji...");
            super.regeneruj(a.getCzasZwiedzania());
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        if(w instanceof BagnoGorskie)
        {
            aktualizujZmeczenie(czas/2);
            mow("Hmm, bagno. Tutaj mniej się męczę: "+w.getNazwa());
        }
        else
        {
            aktualizujZmeczenie(czas);
            mow("Hmm, wędrówka: "+w.getNazwa());
        }


    }

    }
