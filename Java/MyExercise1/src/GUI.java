import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

public class GUI extends JFrame{
      private JPanel panel = new JPanel() ;
      private JTextField text = new JTextField(10);
      private JButton button = new JButton("Count");
      private JButton button1 = new JButton("Add");
      private JLabel label = new JLabel("Counter");
      private JList list = new JList();
      private DefaultListModel model = new DefaultListModel();
      private JScrollPane spanel = new JScrollPane(list);
      
      public GUI() {
   
    	  
    	  
    	  
    	  list.setModel(model);
    	  
    	  panel.add(button);
    	  panel.add(label);
    	  panel.add(spanel);
    	  panel.add(text);
    	  panel.add(button1);
    	  
    	  
    	  button1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int a = Integer.parseInt(text.getText());
				
				model.addElement(a);
				
			}
    		  
    	  });
    	  
    	  button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				ArrayList<Integer> a = new ArrayList<Integer>();
				a = Collections.list(model.elements());
			   int sum = 0;
				for(Integer item:a) {
					sum+=item;
				}
				model.addElement(sum);
			}
    		  
    	  });
    	  
    	  
    	  this.setContentPane(panel);
    	  this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	  this.setVisible(true);
    	  this.setTitle("Program Counting");
    	  this.setSize(400,400);
      }
}
