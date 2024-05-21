package Game;

import Organisms.Animals.*;
import Organisms.Plants.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Adder extends JPanel implements ActionListener, KeyListener
{
    MyPanel panel;
    JButton submit;
    JComboBox<String> comboBox;
    public Adder (MyPanel panel)
    {
        this.panel = panel;
        this.setBackground(Color.pink);
        this.setPreferredSize(new Dimension(250,100));
        this.setLayout(new BorderLayout());
        String[] options = {"Antylopa", "Lis", "Owca", "Żółw", "Wilk", "Jagoda", "Mlecz", "Trawa", "Guarana", "Barszcz"};
        comboBox = new JComboBox<>(options);
        submit = new JButton("Submit");
        this.add(submit, BorderLayout.SOUTH);
        submit.addActionListener(this);

        // Dodawanie listy rozwijanej do ramki
        add(comboBox, BorderLayout.EAST);


    }

    public void paint(Graphics g)
    {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.drawString("DODAWANIE ORGANIZMU: ",10,10);
        g2d.drawString("X: " + panel.choiceX,10,30);
        g2d.drawString("Y: " + panel.choiceY,10,50);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==submit)
        {
            switch(comboBox.getSelectedIndex())
            {
                case 0:
                    panel.world.addOrganism(new Antelope(panel.world,panel.choiceX+1,panel.choiceY+1));
                    break;
                case 1:
                    panel.world.addOrganism(new Fox(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 2:
                    panel.world.addOrganism(new Sheep(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 3:
                    panel.world.addOrganism(new Turtle(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 4:
                    panel.world.addOrganism(new Wolf(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 5:
                    panel.world.addOrganism(new Berry(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 6:
                    panel.world.addOrganism(new Dandelion(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 7:
                    panel.world.addOrganism(new Grass(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 8:
                    panel.world.addOrganism(new Guarana(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                case 9:
                    panel.world.addOrganism(new PineBorscht(panel.world, panel.choiceX + 1, panel.choiceY + 1));
                    break;
                default:
                    System.out.println("Nieznany indeks");
                    break;
            }
            panel.world.screen.repaint();
            this.setVisible(false);
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
