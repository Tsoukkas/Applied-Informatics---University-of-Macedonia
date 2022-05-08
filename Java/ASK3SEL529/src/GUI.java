import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JTextField;

public class GUI extends JFrame {
    private JFrame Panel = new JFrame("Cars");
    private JTextField brand = new JTextField("What brand is it?");
    private JTextField cc = new JTextField("How many litres is the car?") ;
    private JTextField owner = new JTextField("Who is the owner?");
    private JButton Add = new JButton("Add");
    private JButton Print = new JButton("Print Details");
    private JList list = new JList();
    private DefaultListModel model = new DefaultListModel();
    private ArrayList<Vehicle> lista = new ArrayList<>();
    public GUI(ArrayList<Vehicle> ArrayList) {
    	this.lista = ArrayList;
    	
    	for(Vehicle v:lista) {
    		model.addElement(v.getBrand());
    	}
    	
    	this.list.setModel(model);
    	this.setContentPane(Panel);
    	this.setSize(500,500);
    	this.setVisible(true);
    	this.setTitle("Cars");
    	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	
    	Add.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(!(model.contains(brand.getText()))) {
					model.addElement(brand.getText());
                   int y = Integer.parseInt(cc.getText());
					Vehicle x = new Vehicle((String)brand.getText(),y,(String)owner.getText());
					lista.add(x);
				}
				
			}
    		
    	});
    	
       Print.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
		   for(Vehicle v:lista) {
			   v.printDetails();
		   }
		}
    	   
       });
    }
}
