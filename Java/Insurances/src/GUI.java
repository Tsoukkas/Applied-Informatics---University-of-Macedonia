import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
    private JPanel panel = new JPanel();
    private JTextField code = new JTextField("Enter code");
    private JButton button = new JButton("Print Selected Insurance");
    private JButton button1 = new JButton("Print All Insurance Costs");
    private ArrayList<Insurance> list = null;
    public GUI(ArrayList<Insurance> a) {
    	list = a;
    	panel.add(code);
    	panel.add(button);
    	panel.add(button1);
    	
    	button.addActionListener(new ActionListener() {

			@Override 
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				for(Insurance item:list) {
					int a =Integer.parseInt(code.getText());
					if(item.getNumber() == a) {
						item.printDetails();
					}
					else {
						System.out.println("There is no Insurance " + code.getText());
					}
				}
			}
    		
    	});
    	
    	
    	button1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				for(Insurance item:list) {
					System.out.println(item.getSurname() + " ," + item.getcost());
				}
			}
    		
    	});
    	
    	
    	
    	
    	
    	
    	this.setContentPane(panel);
    	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	this.setVisible(true);
    	this.setTitle("Insurances");
    	this.setSize(400,400);
    }
}
