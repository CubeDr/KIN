package a1910122322;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class MyFrame extends JFrame implements ActionListener{
    private Random rand;
    private JButton[] btns;
    // 멤버 필드로 선언
    private JTextField tf;

    MyFrame() {
        setSize(400, 600);
        setTitle("Random Color");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        rand=new Random();
        btns=new JButton[5];
        JPanel pn,pc,ps;
        pn=new JPanel();
        pc=new JPanel();
        ps=new JPanel();
        add(pn,BorderLayout.NORTH);
        add(pc,BorderLayout.CENTER);
        add(ps,BorderLayout.SOUTH);

        JButton b0;
        pn.add(b0=new JButton("Try"));
        b0.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setColors();
            }
        });
        pc.setLayout(new GridLayout(5,1));

        for(int i=0; i<5; i++) {
            btns[i] = new JButton(String.valueOf(i + 1));
            btns[i].addActionListener(this);
            pc.add(btns[i]);
        }
        setColors();

        ps.add(tf=new JTextField(10));
        tf.setEditable(false);
        setVisible(true);
    }
    private void setColors() {
        for (JButton b: btns)
            b.setBackground(new Color(rand.nextInt(0x1000000)));
    }

    public static void main(String[] args) {
        new MyFrame();
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();

        // 설정된 배경 색을 받아옴
        Color color = button.getBackground();
        // 배경 색의 RGB 값 추출
        int colorInt = color.getRGB() & 0x00ffffff;
        // 16진수로 변환
        String colorHex = "0x" + Integer.toHexString(colorInt);

        tf.setText(colorHex);
    }


}