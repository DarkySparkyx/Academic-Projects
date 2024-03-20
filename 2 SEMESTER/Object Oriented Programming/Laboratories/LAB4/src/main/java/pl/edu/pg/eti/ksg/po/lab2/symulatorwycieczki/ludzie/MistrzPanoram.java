package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Przepasc;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.WychodnieSkalne;

public class MistrzPanoram extends Czlowiek{
    public MistrzPanoram(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 5, 18, 18);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 3;
    }
    @Override
    public void reagujNaAtrakcje(Atrakcja a) {
        if(a instanceof WychodnieSkalne || a instanceof Przepasc)
        {
            super.mow("Piękny widok! Tutaj odpoczne znacznie bardziej");
            super.regeneruj(a.getCzasZwiedzania()*2);
        }
        super.mow("Jestem na Atrakcji...");
        super.regeneruj(a.getCzasZwiedzania());
    }
}