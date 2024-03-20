package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji3D{

    public final Transformacja3D[] tab;

    public ZlozenieTransformacji3D(Transformacja3D[] t) {
        this.tab=t;
    }


    public Punkt3D Transformuj(Punkt3D a) {
        System.out.println("Punkt początkowy to: " + a.toString());
        for(int i=0;i<tab.length;i++)
        {
            int j = i+1;
            System.out.println("Transformacja numer " + j + " : " + tab[i].toString());
            a = tab[i].Transformuj(a);
            System.out.println("Efekt tej transformacji: " + a.toString());
        }
        return a;
    }


    public ZlozenieTransformacji3D getTransformacjaOdwrotna() {
        Transformacja3D[] odwrotne = new Transformacja3D[tab.length];
        for(int i=0;i<tab.length;i++)
        {
            odwrotne[tab.length-1-i]=tab[i].getTransformacjaOdwrotna();
        }
        return new ZlozenieTransformacji3D(odwrotne);
    }
}
