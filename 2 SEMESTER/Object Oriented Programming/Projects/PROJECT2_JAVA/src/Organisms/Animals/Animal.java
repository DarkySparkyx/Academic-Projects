package Organisms.Animals;

import Game.World;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;

public class Animal extends Organism implements Serializable {
    Animal(String symbol, String name, Color color, int sila, int initative, int speed, World world,int x, int y)
    {
        super(symbol, name, color, sila, initative, speed, world,x,y);
    }

    @Override
    public void Action()
    {
        int newX;
        int newY;
        while(true)
        {
            newX = world.getNewPosition(this.getX(),this.getSpeed());
            newY = world.getNewPosition(this.getY(),this.getSpeed());
            if(world.isPositionWithinBoard(newX,newY) && (newX!=x || newY!=y))
            {
                break;
            }
        }
        if(world.IsPlaceTaken(newX, newY))
        {
            Organism victim = world.FindOrganismByPosition(newX,newY).get();
            victim.Collision(this);
        }
        else
        {
            world.addToLog(this + "skacze na pole " + newX + " " + newY);
            this.x=newX;
            this.y=newY;
        }
    }

    @Override
    public void Collision(Organism org)
    {
        Animal attacker = (Animal)org;
        if(attacker.getSymbol().equals(this.getSymbol())) //Collision between Animals of the same kind
        {
            world.addToLog(this + " oraz " + attacker + "próbują się rozmnożyć...");
            this.Breeding();
        }
        else
        {
            if(attacker.getStrength()>=this.getStrength())
            {
                if(this.IsEscaping() && world.isAnyNearbyPlaceFree(this))
                {
                    int oldX = this.getX();
                    int oldY = this.getY();
                    world.addToLog(attacker + " próbował zaatakować " + this + " ale ofiara uciekła.");
                    this.Escape();
                    attacker.setXY(oldX,oldY);
                }
                else if(this.IsShielding(attacker))
                {
                    world.addToLog(attacker + " atakuje " + this + ", ale ofiara odpiera atak.");
                }
                else
                {
                    world.addToLog(attacker + " atakuje i wygrywa. " + this + " ginie.");
                    attacker.setXY(this.getX(),this.getY());
                    this.kill();
                }
            }
            else
            {
                if(attacker.IsEscaping())
                {
                    world.addToLog(attacker + " natrafia na silniejszego " + this + ". Udaje sie jednak uniknac walki i wraca na poprzednie pole.");
                }
                else if(attacker.hasForseenDanger())
                {
                    world.addToLog(attacker + " zweszyl zagrozenie w postaci: " + this + " i pozostaje na swoim miejscu.");
                }
                else
                {
                    world.addToLog(attacker + " trafia na silniejszego " + this + " i ginie.");
                    attacker.kill();
                }
            }
        }
    }

    public boolean hasForseenDanger()
    {
        return false;
    }

    public boolean IsShielding(Organism attacker)
    {
        return false;
    }

    public boolean IsEscaping()
    {
        return false;
    }

    public void Escape()
    {
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(!world.IsPlaceTaken(x+i,y+j) && world.isPositionWithinBoard(x+i,y+j))
                {
                    setXY(x+i,y+j);
                    return;
                }
            }
        }
    }

    @Override
    public void Breeding()
    {
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(world.isPositionWithinBoard(this.getX()+i,this.getY()+j) && !world.IsPlaceTaken(this.getX()+i,this.getY()+j))
                {
                    world.addToLog("Dziecko pojawi sie na pozycji " + (this.getX()+i) + " " + (this.getY()+j));
                    world.addOrganism(this.getChild(this.getX()+i,this.getY()+j));
                    return;
                }
            }
        }
        System.out.println("Brak miejsca na dziecko");
    }
}
