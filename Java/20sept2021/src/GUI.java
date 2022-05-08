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
    private JPanel panel = new JPanel();
    private JTextField field = new JTextField(10);
    private JButton button = new JButton("Εμφάνιση Αυτονομίας");
    private JButton button1 = new JButton("Αποθήκευση σε Αρχείο");
    private ArrayList<Fleet> list = new ArrayList<>();
    
    public GUI(ArrayList<Fleet> a) {
       this.list =a;
       this.setContentPane(panel);
       this.setDefaultCloseOperation(EXIT_ON_CLOSE);
       this.setVisible(true);
       this.setSize(400,400);
       this.setTitle("Taxies");
       
       button.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			String a = field.getText();
			for(Fleet item:list) {
				if(item.getName().equals(a)) {
					System.out.println("Name: "+item.getName());
					System.out.println("Plithos: "+item.getStolos().size());
					System.out.println("Sinoliki aftonomia: "+item.Aftonomies());
				}
			}
		}
    	   
       });
       
       button1.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			File file = new File("ANTONIS_TSOUKKAS.txt");
			try {
				FileWriter filewriter = new FileWriter(file);
				filewriter.write(field.getText());
				ArrayList<Taxi> taxies = null;
				for(Fleet item:list) {
					if(item.getName().equals(field.getText())) {
						taxies = item.stolos;
						filewriter.write(System.lineSeparator());
						for(Taxi a:taxies) {
							filewriter.write(a.getDriver());
							filewriter.write(System.lineSeparator());
							filewriter.write(a.getNumber());
							filewriter.write(System.lineSeparator());
							filewriter.write(String.valueOf(a.returnAftonomia()));
							filewriter.write(System.lineSeparator());
						}
						filewriter.write(String.valueOf(item.Aftonomies()));
						filewriter.close();
					}}
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
		}
    	   
       });
       
       panel.add(field);
       panel.add(button);
       panel.add(button1);
    }
    
}
