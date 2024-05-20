package Organisms.Animals;

import Game.World;

import java.awt.*;

public class Wolf extends Animal{
    public Wolf(World world,int x, int y) {
        super("W", "Wolf", Color.GRAY, 9, 5, 1, world,x,y);
    }
}
