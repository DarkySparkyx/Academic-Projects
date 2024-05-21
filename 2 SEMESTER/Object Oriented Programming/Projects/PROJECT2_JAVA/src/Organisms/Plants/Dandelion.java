package Organisms.Plants;

import Game.World;

import java.awt.*;
import java.io.Serializable;

public class Dandelion extends Plant implements Serializable {
    public Dandelion(World world, int x, int y)
    {
        super("D", "Dandelion", Color.yellow, 0, 0, 1, world,x,y);
    }
    @Override
    public Dandelion getChild(int x, int y)
    {
        return new Dandelion(world,x,y);
    }
    @Override
    public void Action()
    {
        for(int i=0;i<3;i++)
        {
            super.Action();
        }
    }
}
