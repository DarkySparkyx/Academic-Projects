package Game;
import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame
{
    World world;
    public HumanGUI humanGUI;
    public LogsPanel logspanel;
    MyFrame(World world)
    {
        this.world=world;
        this.setTitle("Game Life by Michal Jasiak");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        this.setResizable(false);
        this.setBackground(Color.lightGray);
        this.setLayout(new FlowLayout());
        this.setFocusable(true);

        humanGUI = new HumanGUI(world);
        this.add(humanGUI);

        MyPanel board = new MyPanel(world);
        this.add(board);

        logspanel = new LogsPanel(world);
        this.add(logspanel);

        this.addKeyListener(humanGUI);
        this.pack();
        humanGUI.grabFocus();
    }

}
