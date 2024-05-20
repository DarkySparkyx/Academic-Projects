package Organisms;

import Game.World;
import Organisms.Animals.Animal;

import java.awt.*;

public class Organism
{
    String symbol;
    String name;
    Color color;
    int sila;
    int initative;
    int speed;
    protected World world;
    protected int x;
    protected int y;
    protected Organism(String symbol, String name, Color color, int sila, int initative, int speed, World world,int x,int y)
    {
        this.symbol=symbol;
        this.name=name;
        this.color=color;
        this.sila=sila;
        this.initative =initative;
        this.speed =speed;
        this.world=world;
        this.x=x;
        this.y=y;
    }
    public void Action()
    {

    }
    public int getX()
    {
        return x;
    }
    public int getY()
    {
        return y;
    }
    public Color getColor()
    {
        return color;
    }

    public String getSymbol() {
        return symbol;
    }

    public void collision(Organism attacker) {
    }
}
