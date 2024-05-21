package Organisms.Plants;

import Game.World;
import Organisms.Animals.Animal;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;
import java.util.Optional;

public class PineBorscht extends Plant implements Serializable {
    public PineBorscht(World world, int x, int y)
    {
        super("P", "Pine Borscht", Color.red, 11, 0, 1, world,x,y);
    }
    @Override
    public PineBorscht getChild(int x, int y)
    {
        return new PineBorscht(world,x,y);
    }
    @Override
    public void Action()
    {
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                Optional<Organism> optional = world.FindOrganismByPosition(getX()+i,getY()+j);
                if(optional.isPresent())
                {
                    if(optional.get() instanceof Animal)
                    {
                        world.addToLog(this + " zabija: " + optional.get());
                        optional.get().kill();
                    }
                }
            }
        }
        super.Action();
    }
}
