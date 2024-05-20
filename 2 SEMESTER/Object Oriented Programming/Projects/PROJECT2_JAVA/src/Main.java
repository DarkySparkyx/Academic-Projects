import Game.*;

import javax.swing.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
       World gra = new World();
        Scanner test = new Scanner(System.in);
        test.nextLine();
        gra.nextRound();
        test.nextLine();
        gra.nextRound();
        test.nextLine();
    }
}