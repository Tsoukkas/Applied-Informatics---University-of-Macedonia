import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
    private JPanel panel = new JPanel();
    private JButton button = new JButton("0");
    private JButton button1 = new JButton("1");
    private JButton button2 = new JButton("2");
    private JButton button3 = new JButton("3");
    private JButton button4 = new JButton("4");
    private JButton button5 = new JButton("5");
    private JButton button6 = new JButton("6");
    private JButton button7 = new JButton("7");
    private JButton button8 = new JButton("8");
    private JButton button9 = new JButton("9");
    private JButton button0 = new JButton("CLEAR");
    private JButton button11 = new JButton("ENTER");
    private JTextField field = new JTextField(30);
    
    public GUI() {
    	panel.add(button);
    	panel.add(button0);
    	panel.add(button1);
    	panel.add(button2);
    	panel.add(button3);
    	panel.add(button4);
    	panel.add(button5);
    	panel.add(button6);
    	panel.add(button7);
    	panel.add(button8);
    	panel.add(button9);
    	panel.add(button11);
    	panel.add(field);
    	
    	button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
			String a = field.getText() + field.setText(String.valueOf(0));
			}
    		
    	});
    	
    	button1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				field.setText(String.valueOf(1));
			}
    		
    	});
    	//clear
    	button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button2.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button3.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button4.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button5.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button6.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button7.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button8.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button9.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	button11.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
			}
    		
    	});
    	
    	this.setContentPane(panel);
    	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	this.setVisible(true);
    	this.setTitle("Swing lock");
    	this.setSize(300,300);
    	
    	
    }
}
