package Organisms.Animals;

import Game.World;
import com.sun.source.tree.ReturnTree;

import java.awt.*;
import java.io.Serializable;

public class Antelope extends Animal implements Serializable {
    public Antelope(World world, int x, int y) {
        super("A", "Antelope", new Color(87, 49, 11), 4, 4, 2, world,x,y);
    }
    @Override
    public Antelope getChild(int x, int y)
    {
        return new Antelope(world,x,y);
    }
    @Override
    public boolean IsEscaping()
    {
        return world.getRandomNumber(2) == 0;
    }
}
