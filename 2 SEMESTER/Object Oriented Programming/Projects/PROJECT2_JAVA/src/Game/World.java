package Game;
import Organisms.Animals.*;
import Organisms.Organism;
import Organisms.Plants.*;


import javax.swing.*;
import java.io.*;
import java.util.*;

public class World implements Serializable {
    private static final long serialVersionUID = 1L;
    int height,width,round;
    public MyFrame screen;
    List<Organism> Organisms;
    Random rand;
    List<String> logs;
    public Human human;
    public int HumanX, HumanY,howMuchOrganismsToEvalute;

    public void saveAndExit() throws IOException {
        FileOutputStream fileOutputStream = new FileOutputStream("yourfile2.txt");
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
        objectOutputStream.writeObject(this);
        objectOutputStream.flush();
        objectOutputStream.close();
        System.exit(0);
    }
    public World(int x,int y) {
        HumanX = 0;
        HumanY = 0;
        round = 0;
        rand = new Random();
        logs = new ArrayList<>();
        width = x;
        height = y;
        howMuchOrganismsToEvalute = -25;

        human = new Human(this, rand.nextInt(width) + 1, rand.nextInt(height) + 1);
        Organisms = new ArrayList<>();
        Organisms.add(human);
        Organisms.add(new Sheep(this,0,0));
        Organisms.add(new Turtle(this, 0,0));
        Organisms.add(new Antelope(this, 0,0));
        Organisms.add(new Fox(this, 0,0));
        Organisms.add(new Wolf(this, 0,0));
        Organisms.add(new Grass(this, 0,0));
        Organisms.add(new Dandelion(this, 0,0));
        Organisms.add(new Berry(this, 0,0));
        Organisms.add(new PineBorscht(this, 0,0));
        Organisms.add(new Guarana(this, 0,0));
        screen = new MyFrame(this);
        garbageCollector();
        System.out.println("Koniec konstruktora");
    }
    public World(World w)
    {
        height = w.height;
        width = w.width;
        round = w.round;
        human = w.human;
        Organisms = w.Organisms;
        logs = w.logs;
        rand = w.rand;
        HumanX = w.HumanX;
        HumanY = w.HumanY;
        howMuchOrganismsToEvalute=w.howMuchOrganismsToEvalute;
        garbageCollector();
        for(Organism o : Organisms)
        {
            o.setWorldRefference(this);
        }
        screen = new MyFrame(this);
        howMuchOrganismsToEvalute=-25;
    }

    public void addToLog(String input) {
        logs.add(input);
    }

    public List<String> getLogs() {
        return logs;
    }

    public void NextRoundUntilHumanActionRequired()
    {
        logs.clear();
        garbageCollector();
        round++;
        addToLog("Round: " + round);
        System.out.println("Round: " + round);
        System.out.println("Human: " + human + " " + HumanX + " " + HumanY);
        howMuchOrganismsToEvalute = Organisms.size();
        for (int i = 0; i < howMuchOrganismsToEvalute; i++) {
            Organism org = Organisms.get(i);
            if (org instanceof Human && org.isAlive())
            {
                System.out.println("Break");
                screen.repaint();
                return;
            } else if (org.isAlive())
            {
                org.Action();
            }
        }
        screen.humanGUI.nextRound.setEnabled(true);
        screen.repaint();
    }

    public void NextRoundAfterHumanAction()
    {
        boolean wasHuman=false;
        for (int i = 0; i < howMuchOrganismsToEvalute; i++)
        {
            Organism org = Organisms.get(i);
            System.out.println(i + " " + org);
            if(Organisms.get(i) instanceof Human)
            {
                wasHuman=true;
            }
            if(wasHuman)
            {
                Organisms.get(i).Action();
            }
        }
        screen.repaint();
        screen.humanGUI.nextRound.setEnabled(true);
        garbageCollector();
        this.howMuchOrganismsToEvalute=-25;
        System.out.println("End of round");
    }

    public void addOrganism(Organism org)
    {
        Organisms.add(org);
    }

    public Optional<Organism> FindOrganismByPosition(int x, int y)
    {
        return Organisms.stream().filter(organism -> organism.getX()==x && organism.getY()==y).findAny();
    }

    public boolean IsPlaceTaken(int x, int y)
    {
        Optional<Organism> foundOrganism = Organisms.stream().filter(organism -> organism.getX()==x && organism.getY()==y).findAny();

        return foundOrganism.isPresent();
    }

    public int getNewPosition(int xy,int speed)
    {
        return (xy+(rand.nextInt(3)-1)*speed);
    }

    public boolean isPositionWithinBoard(int x, int y)
    {
        return (x>0 && x<=width && y>0 && y<=height);
    }

    private void garbageCollector()
    {
        Organisms.removeIf(org -> !org.isAlive());
        Organisms.sort((o1, o2) -> Integer.compare(o2.getInitative(),o1.getInitative()));

    }

    public int getRandomNumber(int bond)
    {
        return rand.nextInt(bond);
    }

    public boolean isAnyNearbyPlaceFree(Organism org)
    {
        int x = org.getX();
        int y = org.getY();
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(!IsPlaceTaken(x+i,y+j) && isPositionWithinBoard(x+i,y+j))
                {
                    return true;
                }
            }
        }
        return false;
    }

    public MyFrame getScreen()
    {
        return screen;
    }

    public int getWidth()
    {
        return width;
    }
    public int getHeight()
    {
        return height;
    }
}
