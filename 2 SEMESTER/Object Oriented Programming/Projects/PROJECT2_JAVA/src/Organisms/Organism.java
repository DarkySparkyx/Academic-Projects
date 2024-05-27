package Organisms;

import Game.World;

import java.awt.*;
import java.io.Serializable;

public class Organism implements Serializable {

    String symbol;
    String name;
    Color color;
    int strength;
    int initative;
    protected int speed;
    protected World world;
    protected int x;
    protected int y;
    protected boolean alive;

    protected Organism(String symbol, String name, Color color, int strength, int initative, int speed, World world,int x,int y)
    {
        if(x==0 && y==0)
        {
            int newX=world.getRandomNumber(world.getWidth())+1;
            int newY=world.getRandomNumber(world.getHeight())+1;
            while(world.IsPlaceTaken(newX,newY) || newX==0 || newY==0)
            {
                newX=world.getRandomNumber(world.getWidth())+1;
                newY=world.getRandomNumber(world.getHeight())+1;
            }
            this.x=newX;
            this.y=newY;
        }
        else
        {
            this.x=x;
            this.y=y;
        }
        this.symbol=symbol;
        this.name=name;
        this.color=color;
        this.strength =strength;
        this.initative =initative;
        this.speed =speed;
        this.world=world;
        alive=true;
    }

    public int getX()
    {
        return x;
    }
    public int getY()
    {
        return y;
    }
    public int getSpeed() {return speed;}
    public Color getColor()
    {
        return color;
    }
    public String getName()
    {
        return name;
    }

    public String getSymbol() {
        return symbol;
    }

    public void Action() {
    }
    public void Collision(Organism attacker) {
    }
    public void Breeding() {
    }
    public Organism getChild(int x, int y) {return null;}

    public int getStrength()
    {
        return strength;
    }
    public boolean isAlive()
    {
        return alive;
    }
    public void setXY(int x, int y)
    {
        this.x=x;
        this.y=y;
    }
    public void kill()
    {
        this.setXY(0,0);
        this.alive=false;
    }
    public void setSpeed(int val)
    {
        speed=val;
    }

    public int getInitative()
    {
        return initative;
    }

    @Override
    public String toString()
    {
        return this.name+"("+this.getX()+","+this.getY()+")";
    }

    public void setStrength(int val)
    {
        strength=val;
    }

    public void setWorldRefference(World w)
    {
        world=w;
    }
}
