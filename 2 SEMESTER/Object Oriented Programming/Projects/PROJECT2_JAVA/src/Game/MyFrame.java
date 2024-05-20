package Game;
import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame
{
    MyFrame(MyPanel board)
    {
        this.setTitle("Game Life by Michal Jasiak");
        this.add(board);
        this.pack();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}
