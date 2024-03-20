package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Punkt3D extends Punkt
{
    private final double z;
    public Punkt3D(double x, double y, double z) {
        super(x, y);
        this.z=z;
    }

    public double GetZ()
    {
        return z;
    }

    @Override
    public String toString() {
        return "Object that represents point: x(" + x + ") y(" + y + ") z( " + z + ')';
    }
}
