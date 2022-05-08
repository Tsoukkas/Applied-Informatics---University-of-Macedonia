package java;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

public class GUI extends JFrame {
	
	private JPanel panel = new JPanel();
	private JTextField input = new JTextField("Enter a name");
	private JButton addButton = new JButton("Add");
	private JList list = new JList();
	private JButton shuffleButton = new JButton("Shuffle");
	private DefaultListModel model = new DefaultListModel();
	private JScrollPane scrollPane ;
	
	public GUI() {
		
		
		
		list.setModel(model);
		scrollPane = new JScrollPane(list);
		
		panel.add(input);
		panel.add(addButton);
		panel.add(addButton);
		panel.add(scrollPane);
		panel.add(shuffleButton);
		
		this.setContentPane(panel);
		
		addButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String name = input.getText();
				model.addElement(name);
						
			}
			
		});
		
		shuffleButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				ArrayList<String> namesList = Collections.list(model.elements());
				
				Collections.shuffle(namesList);
				
				model.clear();
				
				for(String name : namesList) {
					model.addElement(name);
				}
			}
			
		});
		
		this.setVisible(true);
		this.setSize(400,400);
		this.setTitle("ALgorithms");
		
		
	}

}
