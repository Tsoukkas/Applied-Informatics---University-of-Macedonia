package themata2021;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
    
	private JTextField text= new JTextField(20);
    private JButton b = new JButton("Εμφάνιση Αυτονομίας");
    private JButton b1 = new JButton("Αποθήκευση σε Αρχείο");
    private JPanel panel = new JPanel();
    private ArrayList<Fleet> f = new ArrayList<>();
    
    public GUI(ArrayList<Fleet> a) {
    	
    	this.f=a;
    	
    	panel.add(text);
    	panel.add(b);
    	panel.add(b1);
    	
    	this.setContentPane(panel);
    	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	this.setVisible(true);
    	this.setSize(400,400);
    	this.setTitle("Exams");
    	
    	b.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
				
		    	Fleet s = null;
		    	String stolos =  text.getText();
		    	
				for(Fleet name: f) {
					if(stolos.equals(name.getCity())) {
						s=name;
						System.out.print("onoma: " + s.getCity());
						System.out.println("Plithos taxi: " + s.returnPlithos());
						System.out.println("Sinoliki aftonomia: " + s.returnAftonomia());
					}
						
		    	
		    }
			}
    		
    	});
    	
    	b1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				File file = new File("ANTONIS TSOUKKAS");
				try {
					FileWriter fileWriter = new FileWriter(file);
					ArrayList<Taxi> taxies = null;
					for(Fleet f1:f) {
						fileWriter.write(f1.getCity());
						fileWriter.write(System.lineSeparator());
						taxies = f1.getTaxies();
						for(Taxi a : taxies) {
							fileWriter.write("Onomateponimo odigu: " +a.getDn()+ "arithmos kikloforias: " + a.getAk()+ "aftonomia: " +a.aftonomia());
							fileWriter.write(System.lineSeparator());
						}
						fileWriter.write("Sinoliki aftonomia: "+f1.returnAftonomia());
						fileWriter.write(System.lineSeparator());
					}
					
					
					
					fileWriter.close();
				} catch (IOException i) {
					// TODO Auto-generated catch block
					i.printStackTrace();
				}
			}
    		
    	});
    
}
}
