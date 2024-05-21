package Organisms.Animals;

import Game.World;

import java.awt.*;
import java.io.Serializable;

public class Wolf extends Animal implements Serializable {
    public Wolf(World world,int x, int y) {
        super("W", "Wolf", Color.GRAY, 9, 5, 1, world,x,y);
    }
    @Override
    public Wolf getChild(int x, int y)
    {
        return new Wolf(world,x,y);
    }
}
