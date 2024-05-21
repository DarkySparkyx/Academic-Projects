package Game;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class PlaceHitBox extends JLabel implements MouseListener {
    int x;
    int y;
    MyPanel panel;
    PlaceHitBox(MyPanel panel, int x, int y)
    {
        this.panel = panel;
        this.x = x;
        this.y = y;
        this.setBackground(Color.pink);
        this.setPreferredSize(new Dimension(30,30));
        this.addMouseListener(this);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        if(!panel.world.IsPlaceTaken(x+1,y+1))
        {
            System.out.println("Clicked on: " + this.x + ", " + this.y);
            panel.choiceX=this.x;
            panel.choiceY=this.y;
            panel.adder.setVisible(true);
            panel.repaint();
        }

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}
