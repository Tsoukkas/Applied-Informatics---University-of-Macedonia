import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PrintFrame extends JFrame{
   private JPanel panel = new JPanel();
   private JButton button = new JButton("Εκτύπωση");
   private BookStore b = null;
   private ArrayList<GeneralBook> list = new ArrayList<>();
public PrintFrame(BookStore a) {
	b=a;
	list=b.getList();
	this.setContentPane(panel);
	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	this.setVisible(true);
	this.setTitle("Books");
	this.setSize(400,400);
	
	button.addActionListener(new ActionListener() {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			int counter=0;
		    int counter1 = 0;
			for(GeneralBook item:list) {
				System.out.println(item.getInfo());
				if(item.isElectric()) {
					counter++;
				}
				else {
					counter1++;
				}
			}
			System.out.println("ElectricBooks: "+counter);
			System.out.println("ClassicBooks: "+counter1);
		}
		
	});
	
	
	panel.add(button);
}

}
