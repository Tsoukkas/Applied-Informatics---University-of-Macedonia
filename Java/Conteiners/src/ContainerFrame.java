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
	private JTextField codeField = new JTextField("Enter Code");
	private JTextField destinationField = new JTextField("Enter Destination");
	private JTextField weightField = new JTextField("Enter Weight");
	private JTextField powerField = new JTextField("Enter Power");
	private JButton createBulkButton = new JButton("Create Bulk");
	private JButton createRefrButton = new JButton("Create Refridgerator");
	//grafiko iliko listas
	private JList list = new JList();
	//mondelo listas
	private DefaultListModel model = new DefaultListModel();
	//den xriazete na to dimiurgiso afu otan kaleso to alo o diktis tha dixxni eki
	private ArrayList<Ship> ships ;
	
	public ContainerFrame(ArrayList<Ship> someShips) {
		
		ships = someShips;
		
		for(Ship ship: ships) {
			model.addElement(ship.getName());
		}
		
		/*
		model.addElement(.getName());
		model.addElement("SomethingElse");
		model.addElement("SomethingMore");
		//ta sindeo
		list.setModel(model);
		*/
		
		this.setVisible(true);
		this.setSize(400,400);
		this.setTitle("CreateContainers");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		createBulkButton.addActionListener(listener);
		createRefrButton.addActionListener(listener);
		
		
		//edo vazume ta panta sto panel
		panel.add(codeField);
		panel.add(destinationField);
		panel.add(weightField);
		panel.add(powerField);
		panel.add(createBulkButton);
		panel.add(createRefrButton);
		panel.add(list);
		
		
	}

	class ButtonListener implements ActionListener {
	
	   @Override
	   public void actionPerformed(ActionEvent arg0) {
		
		  String code = codeField.getText();
		  String destination = destinationField.getText();
		  //to (String) simeni oti pari tha to metatrepsi kai tha dosi String
		  String selectedShipName = (String)list.getSelectedValue();
		  Ship selectedShip = null;
		  //gia na paro to plio diatrexo ola ta plia
		  //an ekana tin to string tha mporusa anti na vgazo mono ta onomata
		  //vska na dino tha mporusa na edina olo to plio kai na m emfanize stin 
		  //lista oti ethela
		  for(Ship ship: ships) {
		       if(ship.getName().equals(selectedShipName)) {
		    	   selectedShip = ship;
		       }
		  }
		  Container container = null;
		  //kalo tin equals gia na dq an aftos p prokalese to simvan ine afto to pliktro
	      if(arg0.getSource().equals(createBulkButton)){
	    	  //create bulk container
	    	  //kanume String epd i getText epistrefi String
	        String weightText = weightField.getText();
	        //kani tin metatropi tu alfarithmitiku se metavliti double
	        double weight = Double.parseDouble(weightText);
	       container = new Bulk(code, destination , weight);
	       
	       
	      }
	      else {
	    	//create refridgerator container
	    	  String powerText =powerField.getText();
	    	  double power = Double.parseDouble(powerText);
	    	  container = new Refrigerator(code,destination,power);
	    	  
	    	 
	      }
	      selectedShip.addContainer(container);
	      System.out.println("Ship: "+ selectedShipName);
	      System.out.println("Total Charge: "+ selectedShip.calcTotalCharge());
	}
	
	
}
}
