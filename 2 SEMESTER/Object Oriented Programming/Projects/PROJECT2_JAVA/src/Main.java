import Game.*;

import javax.swing.*;
import java.awt.*;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException
    {
        String data = JOptionPane.showInputDialog("Type 1 for new game. Type 2 to Load saved game");
        int choice = Integer.parseInt(data);
        if(choice == 1)
        {
            data = JOptionPane.showInputDialog("Width");
            int width = Integer.parseInt(data);
            int height = Integer.parseInt(JOptionPane.showInputDialog("Height"));
            World w = new World(width, height);
        }
        else
        {
            FileInputStream fileInputStream
                    = new FileInputStream("yourfile2.txt");
            ObjectInputStream objectInputStream
                    = new ObjectInputStream(fileInputStream);
            World gra = (World) objectInputStream.readObject();
            objectInputStream.close();
            World test = new World(gra);
        }

    }
}
