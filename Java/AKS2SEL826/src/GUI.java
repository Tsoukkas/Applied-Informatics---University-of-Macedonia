import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
	
   private JPanel panel = new JPanel();
   private JTextField m1 = new JTextField("Write Memo");
   private JButton b1 = new JButton("Save Memo");
   private JButton button = new JButton("Clear");
   private JButton print = new JButton("print");
   
   public GUI(ArrayList<String> m){
	   
	   panel.add(m1);
	   panel.add(b1);
	   panel.add(button);
	   panel.add(print);
	   
	   b1.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			String a = m1.getText();
			m.add(a);
		}
		   
	   });
	   
	   button.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			m.clear();
		}
		   
	   });
	   
	   print.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			System.out.println("--------");
			   for(String a:m) {
				   System.out.println(a);
			   }
		   }
		
		   
	   });
	   
	   this.setContentPane(panel);
	   this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	   this.setVisible(true);
	   this.setSize(300,300);
	   
   }
}
  
