package Organisms.Plants;

import Game.World;

import java.awt.*;

public class Grass extends Plant
{
    public Grass(World world,int x, int y)
    {
        super("G", "Grass", Color.green, 0, 0, 1, world,x,y);
    }
}
