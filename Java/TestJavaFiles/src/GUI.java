import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GUI extends JFrame{
   private JPanel panel = new JPanel();
   private JButton button = new JButton("Open File");
   private	JFileChooser fileChooser = new JFileChooser();

	public GUI() {
		panel.add(button);
		panel.add(fileChooser);
		this.setContentPane(panel);
		this.setVisible(true);
		this.setSize(400,400);
		this.setTitle("Test");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int value = fileChooser.showOpenDialog(panel);
				
				if(value == JFileChooser.OPEN_DIALOG) {
                    File file = fileChooser.getSelectedFile();
					
					
					try {
						FileReader fileReader = new FileReader(file);
						
						BufferedReader reader = new BufferedReader(fileReader);
						
						String name = reader.readLine();
						 
						while(name != null) {
							System.out.println(name);
							name= reader.readLine();
						}
						
						reader.close();
						fileReader.close();
						
						
					} catch (FileNotFoundException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			}
			
		});
	}
}
