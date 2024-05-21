package Organisms.Animals;

import Game.World;

import java.awt.*;
import java.io.Serializable;

public class Sheep extends Animal implements Serializable {
    public Sheep(World world, int x, int y) {
        super("S", "Sheep", Color.LIGHT_GRAY, 4, 4, 1, world,x,y);
    }
    @Override
    public Sheep getChild(int x, int y)
    {
        return new Sheep(world,x,y);
    }
}
