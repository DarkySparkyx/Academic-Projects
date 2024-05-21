package Organisms.Animals;

import Game.World;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;
import java.util.Optional;

public class Fox extends Animal implements Serializable {
    public Fox(World world, int x, int y) {
        super("F", "Fox", Color.ORANGE, 3, 7, 1, world,x,y);
    }
    @Override
    public Fox getChild(int x, int y)
    {
        return new Fox(world,x,y);
    }

    @Override
    public boolean hasForseenDanger()
    {
        return true;
    }
}
