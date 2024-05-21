package Organisms.Plants;

import Game.World;

import java.awt.*;
import java.io.Serializable;

public class Grass extends Plant implements Serializable {
    public Grass(World world,int x, int y)
    {
        super("G", "Grass", Color.green, 0, 0, 1, world,x,y);
    }
    @Override
    public Grass getChild(int x, int y)
    {
        return new Grass(world,x,y);
    }
}
