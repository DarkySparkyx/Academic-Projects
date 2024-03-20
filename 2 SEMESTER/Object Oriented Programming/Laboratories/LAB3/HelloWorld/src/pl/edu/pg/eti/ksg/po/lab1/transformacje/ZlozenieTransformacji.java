package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji implements Transformacja{
    private final Transformacja[] tab;

    public ZlozenieTransformacji(Transformacja a, Transformacja b)
    {
        tab = new Transformacja[2];
        tab[0] = a;
        tab[1] = b;
    }
    @Override
    public Punkt transformuj(Punkt a)
    {
        Punkt tmp1 = tab[0].transformuj(a);
        return tab[1].transformuj(tmp1);
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        return new ZlozenieTransformacji(tab[0].getTransformacjaOdwrotna(),tab[1].getTransformacjaOdwrotna());
    }
}
