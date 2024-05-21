package Game;

import javax.swing.*;
import java.awt.*;

public class LogsPanel extends JPanel {
    World world;
    LogsPanel(World world)
    {
        this.world=world;
        this.setPreferredSize(new Dimension(400,600));
        this.setBackground(Color.green);
    }

    public void paint(Graphics g)
    {
        super.paint(g);
        Graphics2D g2d=(Graphics2D)g;

        for(int i=0;i<world.getLogs().size();i++)
        {
            String cache = world.getLogs().get(i);
            g2d.drawString(cache,0,20*(i+1));
        }
    }
}
