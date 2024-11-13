import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

class Calc implements ActionListener {
    JButton bmul, bdiv, badd, bsub;
    JLabel l1, l2;
    JTextField t1, t2;
    JFrame f;

    Calc() {
        f = new JFrame("Calculator");
        l1 = new JLabel("no 1");
        l2 = new JLabel("no 2");
        t1 = new JTextField(16);
        t2 = new JTextField(16);

        bmul = new JButton("multiply");
        bdiv = new JButton("divide");
        badd = new JButton("add");
        bsub = new JButton("subtract");

        JPanel p = new JPanel(new GridLayout(5, 2));

        // Adding components
        p.add(l1); p.add(t1);
        p.add(l2); p.add(t2);
        p.add(badd); p.add(bsub);
        p.add(bmul); p.add(bdiv);
        p.add(l4);

        f.add(p);
        f.setSize(300, 300);
        f.setVisible(true);

        // Add action listeners
        bmul.addActionListener(this);
        bdiv.addActionListener(this);
        badd.addActionListener(this);
        bsub.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();
        int n1 = Integer.parseInt(t1.getText());
        int n2 = Integer.parseInt(t2.getText());

        if (s.equals("add")) {
            l4.setText("Answer is " + (n1 + n2));
        } else if (s.equals("subtract")) {
            l4.setText("Answer is " + (n1 - n2));
        } else if (s.equals("multiply")) {
            l4.setText("Answer is " + (n1 * n2));
        } else if (s.equals("divide")) {
            if (n2 != 0) {
                l4.setText("Answer is " + (n1 / n2));
            } else {
                l4.setText("Cannot divide by zero");
            }
        }
    }

    public static void main(String[] args) {
        new Calc();
    }
}
