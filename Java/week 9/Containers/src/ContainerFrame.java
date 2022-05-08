import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class ContainerFrame extends JFrame {
	
	private JPanel panel = new JPanel();
	private JTextField codeField = new JTextField("Enter code");
	private JTextField destinationField = new JTextField("Enter destination");
	private JTextField weightField = new JTextField("Enter weight");
	private JTextField powerField = new JTextField("Enter power");
	private JButton createBulkButton = new JButton("Create Bulk");
	private JButton createRefrButton = new JButton("Create Refr.");
	private JList list = new JList();
	
	private DefaultListModel model = new DefaultListModel();
	
	private ArrayList<Ship> ships = new ArrayList<>();
	
	public ContainerFrame(ArrayList<Ship> someShips) {
		
		ships = someShips;
		
		for(Ship ship: ships)
			model.addElement(ship.getName());
		
		list.setModel(model);
		
		panel.add(codeField);
		panel.add(destinationField);
		panel.add(weightField);
		panel.add(powerField);
		panel.add(createBulkButton);
		panel.add(createRefrButton);
		panel.add(list);
		
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		createBulkButton.addActionListener(listener);
		createRefrButton.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(500, 500);
		this.setTitle("Create Containers");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
		
		      String code = codeField.getText();
		      String destination = destinationField.getText();
		      
		      String selectedShipName = (String)list.getSelectedValue();
		      Ship selectedShip = null;
		      
		      for(Ship ship: ships)
		    	  if(ship.getName().equals(selectedShipName))
		    		  selectedShip = ship;
		      
		      Container container = null;
		      
		      if(arg0.getSource().equals(createBulkButton)) {
		    	  //CREATE BULK CONTAINER
		    	  String weightText = weightField.getText();
		    	  double weight = Double.parseDouble(weightText);
		    	  container = new Bulk(code, destination, weight);
		      }
		      else {
		    	  //CREATE REFRIDGERATOR CONTAINER
		    	  String powerText = powerField.getText();
		    	  double power = Double.parseDouble(powerText);
		    	  container = new Refridgerator(code, destination, power);
		      }
		      
		      selectedShip.addContainer(container);
		      System.out.println("Ship: " + selectedShipName);
		      System.out.println("Total Charge: " + selectedShip.calcTotalCharge());
			
		}
	}

}
