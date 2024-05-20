package Organisms.Animals;

import Game.World;
import Organisms.Organism;

import java.awt.*;

public class Animal extends Organism
{
    Animal(String symbol, String name, Color color, int sila, int initative, int speed, World world,int x, int y)
    {
        super(symbol, name, color, sila, initative, speed, world,x,y);
    }

    @Override
    public void Action()
    {
        int newX=0;
        int newY=0;
        while(!world.isPositionWithinBoard(newX,newY))
        {
            newX = world.getNewPosition(this.getX());
            newY = world.getNewPosition(this.getY());
        }

        if(world.IsPlaceTaken(newX, newY))
        {
            Organism victim = world.FindOrganismByPosition(newX,newY).get();
            victim.collision(this);
        }
        else
        {
            this.x=newX;
            this.y=newY;
        }
    }
}
