import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TrafficLights implements ActionListener {
    JFrame j ;
    JRadioButtonMenuItem r1, r2, r3;
    JLabel l;

    TrafficLights() {
        j  = new JFrame("traffic light");
        r1 = new JRadioButtonMenuItem("Red");
        r2 = new JRadioButtonMenuItem("Yellow");
        r3 = new JRadioButtonMenuItem("Green");
        l = new JLabel("");

        JPanel p = new JPanel(new GridLayout(1,4));
        ButtonGroup bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        bg.add(r3);

        p.add(l);
        p.add(r1);
        p.add(r2);
        p.add(r3);

        j.add(p);

        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);

        j.setVisible(true);
        j.setSize(350, 200);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent ae) {


        if (r1.isSelected()) {
            l.setText("stop");
            l.setForeground(Color.RED);
        } else if (r2.isSelected()) {
            l.setText("ready");
            l.setForeground(Color.YELLOW);
        } else if (r3.isSelected()) {
            l.setText("go");
            l.setForeground(Color.GREEN);
        }


    }

    public static void main(String[] as) {
        new TrafficLights();
    }
}
