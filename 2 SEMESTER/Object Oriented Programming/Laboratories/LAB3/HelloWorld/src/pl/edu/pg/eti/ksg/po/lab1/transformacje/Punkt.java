package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import java.util.Scanner;

public class Punkt
{
    /*
     * Słowo kluczowe final oznacza, że po pierwszym przypisaniu
     * zawartość pól x oraz y nie może zostać zmieniona
     * w tym miejscu jest to odpowiednik słowa kluczowego const
     * z języka C++.
     */
    protected final double x,y;
    public Punkt(double x, double y) {
       this.x=x;
       this.y=y;
    }
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Punkt) {
            Punkt second = (Punkt)obj;
            if(this.x==second.x && this.y==second.y) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int hashCode() {
       return 113*(int)x*(int)y+23;
    }
    @Override
    public String toString() {
        return "Object that represents point: x(" + x + ") y(" + y + ')';
    }

    /**
     * Początek układu współrzędnych.
     * W tym miejscu słowo kluczowe final oznacza, że statyczne
     * pole klasy Punkt nie może zostać zmienione.
     * Dotyczy to jednak samej referencji, a nie obiektu, na który
     * wskazuje.
     */
    public static final Punkt O = new Punkt(0, 0);
    /**
     * Punkt (1,0) w układzie współrzędnych
     */
    public static final Punkt E_X = new Punkt(1, 0);

    /**
     * Punkt (0,1) w układzie współrzędnych
     */
    public static final Punkt E_Y = new Punkt(0, 1);

    public static void main(String[] args)
    {
        Punkt p1 = new Punkt(1.23,2.4);
        Punkt p2 = new Punkt( 1.23, 2.4);
        Punkt p3 = new Punkt( 1.23, 255);
        System.out.println(E_X.toString());
    }
}


