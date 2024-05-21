package Organisms.Plants;

import Game.World;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;

public class Plant extends Organism implements Serializable
{
    Plant(String symbol, String name, Color color, int sila, int initative, int speed, World world,int x, int y)
    {
        super(symbol, name, color, sila, initative, speed, world,x,y);
    }
    @Override
    public void Action()
    {
        if(world.getRandomNumber(50)==0)
        {
            if(world.isAnyNearbyPlaceFree(this))
            {
                int newX=0;
                int newY=0;
                while(!world.isPositionWithinBoard(newX,newY) || world.IsPlaceTaken(newX,newY))
                {
                    newX=world.getNewPosition(this.x,1);
                    newY=world.getNewPosition(this.y,1);
                }
                world.addOrganism(this.getChild(newX,newY));
                world.addToLog(this + "rozmnaza sie.");
                world.addToLog("Nowy organizm typu: " + getName() + " pojawi sie na pozycji " + newX + " " + newY);
            }
            else
            {
                world.addToLog(this + " probowal sie rozmnozyc, ale nie bylo na to miejsca. ");
            }
        }
    }

    @Override
    public void Collision(Organism attacker)
    {
        if(attacker.getStrength()>=this.getStrength())
        {
            world.addToLog(attacker + " zjada " + this);
            attacker.setXY(getX(),getY());
            this.kill();
        }
        else
        {
            world.addToLog(attacker + " zjada " + this + " i ginie.");
            this.kill();
            attacker.kill();
        }
    }
}
