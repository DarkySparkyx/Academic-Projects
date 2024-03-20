package pl.edu.pg.eti.ksg.po.lab2;

import java.util.HashSet;
import java.util.Set;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.*;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.*;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.*;

/**
 *
 * @author TB
 */
public class JavaLab2 {
    public static void main(String[] args) {
        Wycieczka w = mojaWycieczka();
        
        PrzewodnikStudencki przewodnik = new PrzewodnikStudencki("Stefan", "Długonogi", Czlowiek.Plec.MEZCZYZNA);
        Set<Uczestnik> uczestnicy = new HashSet<>();
        uczestnicy.add(new Hydrolog("Alojzy", "Mechanik", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new MistrzPanoram("Piotr","Teledetekcyjny", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new BagiennyBiegacz("Ada", "Lovelace", Czlowiek.Plec.KOBIETA));

        Grupa g = new Grupa(przewodnik, uczestnicy);
        
        SymulatorWycieczki symulator = new SymulatorWycieczki(g, w);

        symulator.dodajSluchaczPosteow(symulator.klasaAnonimowa());

        symulator.symuluj();
    }
    
    public static Wycieczka mojaWycieczka() {
        Wycieczka ret = new Wycieczka("Studencka wycieczka");
        ret.dodajElementWycieczki(new WietrznaGran(1));
        ret.dodajElementWycieczki(new BagnoGorskie(2));
        ret.dodajElementWycieczki(new Przepasc());
        ret.dodajElementWycieczki(new WychodnieSkalne());
        ret.dodajElementWycieczki(new ObserwatoriumMeteorologiczne());
        ret.dodajElementWycieczki(new ZalanyLas(3));
        return ret;
    }
   
}
