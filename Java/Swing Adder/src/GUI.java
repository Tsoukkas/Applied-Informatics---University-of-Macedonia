import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
	 private JLabel label = new JLabel("First Number");
     private JLabel label1 = new JLabel("Second Number");
     private JLabel label2 = new JLabel("Result");
     private JPanel panel = new JPanel();
     private JTextField text = new JTextField(15);
     private JTextField text1 = new JTextField(15);
     private JTextField text2 = new JTextField("Result");
     private JButton button = new JButton("ADD");
     private JButton button1 = new JButton("CLEAR");
     
     public GUI() {
    	 panel.add(text);
    	 panel.add(text1);
    	 panel.add(text2);
    	 panel.add(button);
    	 panel.add(button1);
    	 panel.add(label);
    	 panel.add(label1);
    	 panel.add(label2);
    	 
    	 
    	 button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int a = Integer.parseInt(text.getText());
				int b = Integer.parseInt(text1.getText());
				
				int c = a+b;
				
				text2.setText(String.valueOf(c));
				
			}
    		 
    	 });
    	 
    	 
    	 button1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
			     text.setText("");
			     text1.setText("");
			     text2.setText("");
			}
    		 
    	 });
    	 
    	 
    	 this.setContentPane(panel);
    	 this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	 this.setVisible(true);
    	 this.setTitle("Swing Adder");
    	 this.setSize(250,250);
     }
}
