package Organisms.Animals;

import Game.World;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;

public class Turtle extends Animal implements Serializable {
    public Turtle(World world, int x, int y) {
        super("T", "Turtle", new Color(3,211,252), 2, 1, 1, world,x,y);
    }
    @Override
    public Turtle getChild(int x, int y)
    {
        return new Turtle(world,x,y);
    }
    @Override
    public boolean IsShielding(Organism attacker)
    {
        return attacker.getStrength()<5;
    }
    @Override
    public void Action()
    {
        if(world.getRandomNumber(4)==0)
        {
            super.Action();
        }
    }
}
