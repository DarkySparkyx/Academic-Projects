package Game;
import Organisms.Animals.Wolf;
import Organisms.Organism;
import Organisms.Plants.Grass;

import javax.swing.*;
import java.util.*;

public class World {
    int height;
    int width;
    int round;
    MyFrame screen;
    MyPanel board;
    List<Organism> Organisms;
    Random rand;
    public World()
    {
        rand = new Random();
        Organisms = new ArrayList<>();
        String data = JOptionPane.showInputDialog("Height of the game board:");
        height = Integer.parseInt(data);
        data = JOptionPane.showInputDialog("Width of the game board");
        width = Integer.parseInt(data);
        board = new MyPanel(height, width,this);
        screen = new MyFrame(board);
        System.out.println("Game size: " + height + " x " + width);


        Organisms.add(new Wolf(this,5,5));
        Organisms.add(new Wolf(this,3,3));
        board.repaint();
    }

    public void nextRound()
    {
        for(Organism org : Organisms)
        {
            org.Action();
        }
        board.repaint();
    }

    public Optional<Organism> FindOrganismByPosition(int x, int y)
    {
        return Organisms.stream().filter(organism -> {
            return organism.getX()==x && organism.getY()==y;
        }).findAny();
    }

    public boolean IsPlaceTaken(int x, int y)
    {
        Optional<Organism> foundOrganism = Organisms.stream().filter(organism -> {
        return organism.getX()==x && organism.getY()==y;}).findAny();

        return foundOrganism.isPresent();
    }

    public int getNewPosition(int xy)
    {
        return (xy+rand.nextInt(3)-1);
    }

    public boolean isPositionWithinBoard(int x, int y)
    {
        return (x>0 && x<=width && y>0 && y<=height);
    }

}
