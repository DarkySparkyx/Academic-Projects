package Game;

import Organisms.Organism;

import javax.swing.*;
import java.awt.*;
import java.util.Optional;

public class MyPanel extends JPanel
{
    World world;
    int choiceX;
    int choiceY;
    Adder adder;
    MyPanel(World world)
    {
        int choiceX=0;
        int choiceY=0;
        this.world=world;
        this.setPreferredSize(new Dimension(600,600));
        this.setLayout(new FlowLayout(FlowLayout.LEFT));

        JPanel BoxContainer = new JPanel();
        BoxContainer.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.NORTHWEST; // Ustawienie zakotwiczenia do lewego górnego rogu
        gbc.insets = new Insets(0,0,0,0); // Ustawienie marginesów między komponentami
        // Tworzenie i dodawanie JLabel do siatki
        for (int i = 0; i < world.width; i++)
        {
            for (int j = 0; j < world.height; j++)
            {
                JLabel label = new PlaceHitBox(this,i,j);
                label.setPreferredSize(new Dimension(30, 30));
                BoxContainer.add(label, gbc);

                gbc.gridy++;
                if (gbc.gridy == world.height)
                {
                    gbc.gridy = 0;
                    gbc.gridx++;
                }
            }
        }
        this.add(BoxContainer);


        adder = new Adder(this);
        this.add(adder);
        adder.setVisible(false);
    }
    public void paint(Graphics g)
    {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        for(int i=1;i<=world.height;i++)
        {
            for(int j=1;j<=world.width;j++)
            {
                Optional<Organism> foundOrganism = world.FindOrganismByPosition(j,i);
                if(foundOrganism.isPresent())
                {
                    g2d.setColor(foundOrganism.get().getColor());
                    g2d.fillRect(5+(30*(j-1)),5+(30*(i-1)),30,30);
                    g2d.setColor(Color.black);
                    g2d.drawString(foundOrganism.get().getSymbol(),20+(30*(j-1)),30+(30*(i-1)));
                }
                else
                {
                    g2d.drawRect(5+(30*(j-1)),5+(30*(i-1)),30,30);
                }
            }
        }
    }
}
