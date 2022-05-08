package fevruarios2020;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
	private JPanel panel = new JPanel();
	private JTextField text = new JTextField("Enter code");
	private JButton button = new JButton("Press Selected Insurance");
	private JButton button1 = new JButton("Press All Insurance Costs");
    private ArrayList<Insurance> b = null;
	
	public GUI(ArrayList<Insurance> a) {
	
	this.b = a;	
	
	panel.add(text);
	panel.add(button);
	panel.add(button1);
		
	this.setContentPane(panel);
	
	button.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			int a = Integer.parseInt(text.getText());
			
			
				if(b.contains(a)) {
					String c = null;
					c = .print();
					System.out.println(c);
				}
				else {
					System.out.println("There is no insurance "+a);
				}
			}
			
		}
		
	});
	
	
	button1.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			for(Insurance a:b) {
				String c=null;
				c=a.print();
				System.out.println(c);
			}
		}
		
	});
	
	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	this.setVisible(true);
	this.setTitle("Insurances");
	this.setSize(500,500);
	}
}
