package Game;

import Organisms.Organism;

import javax.swing.*;
import java.awt.*;
import java.util.Optional;

public class MyPanel extends JPanel
{
    int height, width;
    World world;
    MyPanel(int height, int width,World world)
    {
        this.world=world;
        this.height = height;
        this.width = width;
        this.setPreferredSize(new Dimension(800,800));
    }

    public void paint(Graphics g)
    {
        Graphics2D g2d = (Graphics2D) g;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                Optional<Organism> foundOrganism = world.FindOrganismByPosition(j,i);
                if(foundOrganism.isPresent())
                {
                    g2d.setColor(foundOrganism.get().getColor());
                    g2d.fillRect(10+30*j,10+30*i,30,30);
                    g2d.setColor(Color.black);
                    g2d.drawString(foundOrganism.get().getSymbol(),10+30*j+10,10+30*i+20);
                }
                else
                {
                    g2d.setColor(Color.white);
                    g2d.fillRect(10+30*j,10+30*i,30,30);
                    g2d.setColor(Color.black);
                    g2d.drawRect(10+30*j,10+30*i,30,30);
                }
            }
        }
    }
}
