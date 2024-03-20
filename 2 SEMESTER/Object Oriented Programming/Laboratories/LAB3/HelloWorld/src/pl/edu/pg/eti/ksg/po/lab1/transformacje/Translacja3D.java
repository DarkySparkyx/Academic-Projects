package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Translacja3D implements Transformacja3D {

    private final double x,y,z;

    public Translacja3D(double x, double y, double z)
    {
        this.x=x;
        this.y=y;
        this.z=z;
    }
    @Override
    public Punkt3D Transformuj(Punkt3D a) {
        return new Punkt3D(a.getX()+x,a.getY()+y,a.GetZ()+z);
    }

    @Override
    public Transformacja3D getTransformacjaOdwrotna() {
        return new Translacja3D(-x,-y,-z);
    }

    @Override
    public String toString()
    {
        return "Translacja o wektor [ " + x + " , " + y + " , " + z + " ] ";
    }
}
