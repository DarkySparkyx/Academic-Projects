package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Obrot3D implements Transformacja3D{
    private final double kat;

    public Obrot3D(double kat)
    {
        this.kat = kat;
    }
    @Override
    public Punkt3D Transformuj(Punkt3D a) {
        return new Punkt3D(a.getX(),(a.getY()*Math.cos(Math.toRadians(kat))-a.GetZ()*Math.sin(Math.toRadians(kat))),a.getY()*Math.sin(Math.toRadians(kat))+a.GetZ()*Math.cos(Math.toRadians(kat)));
    }

    @Override
    public Transformacja3D getTransformacjaOdwrotna() {

        return new Obrot3D(-kat);
    }

    @Override
    public String toString()
    {
        return "Obrót w okół osi X o kąt: " + kat;
    }
}
