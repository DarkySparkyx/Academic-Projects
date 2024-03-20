import pl.edu.pg.eti.ksg.po.lab1.transformacje.*;

public class JavaLab1 {
    public static void main(String[] args)
    {
        Transformacja3D tr1 = new Translacja3D(1,2,3);
        Transformacja3D tr2 = new Obrot3D(180);
        Transformacja3D[] tab = new Transformacja3D[]{tr1,tr2};
        ZlozenieTransformacji3D zlozenie = new ZlozenieTransformacji3D(tab);

      Punkt3D p = new Punkt3D(2,3,4);
      p = zlozenie.Transformuj(p);

      zlozenie = zlozenie.getTransformacjaOdwrotna();

     System.out.println();
     System.out.println("TRANSFORMACJA ODWROTNA");
     System.out.println();

     p=zlozenie.Transformuj(p);



    }
}