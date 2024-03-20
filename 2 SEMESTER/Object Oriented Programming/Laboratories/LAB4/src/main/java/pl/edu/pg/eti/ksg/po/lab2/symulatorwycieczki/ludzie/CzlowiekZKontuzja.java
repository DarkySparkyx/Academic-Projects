package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class CzlowiekZKontuzja extends Czlowiek{
    public CzlowiekZKontuzja(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 3, 20, 12);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 1;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a) {
        super.regeneruj(a.getCzasZwiedzania());
        super.mow("Jestem na Atrakcji...");
    }
}
