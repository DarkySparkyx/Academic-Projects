package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public interface Transformacja3D {
    public Punkt3D Transformuj(Punkt3D a);
    public Transformacja3D getTransformacjaOdwrotna();
}
