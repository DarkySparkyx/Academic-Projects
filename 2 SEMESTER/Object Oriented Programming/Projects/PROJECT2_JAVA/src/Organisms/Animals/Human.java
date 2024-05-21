package Organisms.Animals;

import Game.World;
import Organisms.Organism;

import java.awt.*;
import java.io.Serializable;

public class Human extends Animal implements Serializable {
    public boolean isSkillActive;
    public int roundsLeft;
    public int cooldown;
    public Human(World world, int x, int y) {
        super("YOU", "Human", new Color(226, 36, 255), 5, 4, 1, world,x,y);
        isSkillActive=false;
        roundsLeft=0;
        cooldown=0;
    }
    @Override
    public Human getChild(int x, int y)
    {
        return new Human(world,x,y);
    }
    @Override
    public void Action()
    {
        if(!isSkillActive && cooldown>0)
        {
            cooldown--;
        }
        if(isSkillActive)
        {
            roundsLeft--;
        }
        int newX=this.getX()+ world.HumanX*getSpeed();
        int newY=this.getY()+ world.HumanY*getSpeed();
        if(world.IsPlaceTaken(newX,newY))
        {
            Organism victim = world.FindOrganismByPosition(newX,newY).get();
            victim.Collision(this);
        }
        else
        {
            world.addToLog(this + "skacze na pole " + newX + " " + newY);
            this.setXY(newX,newY);
        }
        world.HumanX=0;
        world.HumanY=0;


        if(isSkillActive && roundsLeft<3)
        {
            if(world.getRandomNumber(2)==0)
            {
                this.speed=2;
            }
            else
            {
                this.speed=1;
            }
        }
        if(isSkillActive && roundsLeft==0)
        {
            isSkillActive=false;
            this.speed=1;
        }
    }
}