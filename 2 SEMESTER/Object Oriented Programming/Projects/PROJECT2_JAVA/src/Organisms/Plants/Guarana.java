package Organisms.Plants;

import Game.World;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;

public class Guarana extends Plant implements Serializable {
    public Guarana(World world, int x, int y)
    {
        super("R", "Guarana", Color.pink, 0, 0, 1, world,x,y);
    }
    @Override
    public Guarana getChild(int x, int y)
    {
        return new Guarana(world,x,y);
    }
    @Override
    public void Collision(Organism attacker)
    {
        attacker.setStrength(attacker.getStrength()+3);
        super.Collision(attacker);
    }
}
