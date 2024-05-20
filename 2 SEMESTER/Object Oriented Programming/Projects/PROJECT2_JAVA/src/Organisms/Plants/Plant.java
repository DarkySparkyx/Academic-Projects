package Organisms.Plants;

import Game.World;
import Organisms.Organism;

import java.awt.*;

public class Plant extends Organism
{
    Plant(String symbol, String name, Color color, int sila, int initative, int speed, World world,int x, int y)
    {
        super(symbol, name, color, sila, initative, speed, world,x,y);
    }
    @Override
    public void Action()
    {

    }
}
