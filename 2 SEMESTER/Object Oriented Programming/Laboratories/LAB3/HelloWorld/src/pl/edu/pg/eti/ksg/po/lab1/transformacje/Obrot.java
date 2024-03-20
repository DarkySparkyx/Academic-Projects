package pl.edu.pg.eti.ksg.po.lab1.transformacje;
public class Obrot implements Transformacja
{
    private final double kat;

    public Obrot(double kat)
    {
        this.kat=kat;
    }

    @Override
    public String toString() {
        return "Obrot w okol punktu 0,0 o kąt " + kat + " stopni";
    }

    @Override
    public Punkt transformuj(Punkt a)
    {
        return new Punkt((a.getX()*Math.cos(Math.toRadians(kat))-a.getY()*Math.sin(Math.toRadians(kat))),a.getX()*Math.sin(Math.toRadians(kat))+a.getY()*Math.cos(Math.toRadians(kat)));

    }
    @Override
    public Transformacja getTransformacjaOdwrotna()
    {
        return new Obrot(-kat);
    }

}
