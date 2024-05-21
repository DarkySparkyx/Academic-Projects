package Organisms.Plants;

import Game.World;

import java.awt.*;
import java.io.Serializable;

public class Berry extends Plant implements Serializable {
    public Berry(World world, int x, int y)
    {
        super("B", "Berry", new Color(142, 13, 255), 99, 0, 1, world,x,y);
    }
    @Override
    public Berry getChild(int x, int y)
    {
        return new Berry(world,x,y);
    }
}
