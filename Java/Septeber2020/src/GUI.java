import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;

public class GUI extends JFrame {
   private JPanel panel = new JPanel();
   private JButton b = new JButton("Εκτύπωση");
   private ArrayList<GeneralBook> store1= null;
   
   
   public GUI(ArrayList<GeneralBook> s) {
	   
	   store1=s;
	   
	  
	   
	   this.setContentPane(panel);
	   this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	   this.setVisible(true);
	   this.setTitle("EXAMS");
	   this.setSize(500,500);
	   
	   panel.add(b);
	   
	   b.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			int ebooks=0;
			int books=0;
			for(GeneralBook a:store1) {
				a.print();
				if(a.iseBook()==true) {
					ebooks++;
				}
				else {
					books++;
				}
			}
			System.out.println("Books = "+books);
			System.out.println("Ebooks = "+ebooks);
		}
		   
	   });
	   
	   
   }
}
