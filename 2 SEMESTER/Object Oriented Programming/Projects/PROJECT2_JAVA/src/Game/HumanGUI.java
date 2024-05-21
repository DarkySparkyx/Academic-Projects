package Game;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;

public class HumanGUI extends JPanel implements KeyListener {
    World world;
    JButton nextRound;
    JButton activateSkill;
    HumanGUI(World world)
    {
        this.world=world;
        this.setPreferredSize(new Dimension(300,600));
        this.setBackground(Color.LIGHT_GRAY);

        nextRound = new JButton("Next Round");
        if(world.howMuchOrganismsToEvalute!=-25)
        {
            nextRound.setEnabled(false);
        }
        nextRound.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                nextRound.setEnabled(false);
                world.NextRoundUntilHumanActionRequired();
            }
        });

        activateSkill = new JButton("Activate Skill");
        if(world.human.cooldown>0)
        {
            activateSkill.setEnabled(false);
        }
        activateSkill.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                activateSkill.setEnabled(false);
                world.human.roundsLeft=5;
                world.human.setSpeed(2);
                world.human.cooldown=5;
                world.human.isSkillActive=true;
                world.screen.repaint();
            }
        });

        this.add(activateSkill);
        this.add(nextRound);
    }

    public void paint(Graphics g)
    {
        if(world.human.cooldown==0)
        {
            this.activateSkill.setEnabled(true);
        }
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(Color.black);
        g2d.setFont(new Font("Arial",Font.BOLD,20));
        g2d.drawString("HUMAN INFORMATION:", 60, 60);

        g2d.setFont(new Font("Arial",Font.PLAIN,15));
        String str;
        if(world.human.isSkillActive)
        {
            str="Status superumiejętnośći: AKTYWNA";
            g2d.drawString(str, 10, 100);
            g2d.drawString("Pozostało rund: " + world.human.roundsLeft,10,120);
            g2d.drawString("Szybkosc: " + world.human.getSpeed(),10,140);
        }
        else
        {
            str="Status superumiejętnośći: NIEAKTYWNA";
            g2d.drawString(str, 10, 100);
            g2d.drawString("Cooldown: " + world.human.cooldown,10,120);
        }

    }
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e)
    {
        System.out.println("Key pressed: " + e.getKeyCode());
        if(nextRound.isEnabled())
        {
            if(e.getKeyCode()==27)
            {
                    try {
                        world.saveAndExit();
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
            }
        }
        if(!nextRound.isEnabled()) {
            switch (e.getKeyCode()) {
                case 37:
                    world.HumanX = -1;
                    break;
                case 38:
                    world.HumanY = -1;
                    break;
                case 39:
                    world.HumanX = 1;
                    break;
                case 40:
                    world.HumanY = 1;
                    break;
                default:
                    break;
            }
            if (world.isPositionWithinBoard(world.human.getX() + world.HumanX, world.human.getY() + world.HumanY) && (world.HumanX != 0 || world.HumanY != 0))
            {
                world.NextRoundAfterHumanAction();
                nextRound.setEnabled(true);
            }
            else
            {
                world.HumanX=0;
                world.HumanY=0;
            }
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
