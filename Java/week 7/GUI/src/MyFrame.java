import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame extends JFrame {
	
	public MyFrame() {
		
		//Βήμα 1. Δημιουργία Υποδοχέα
		JPanel panel = new JPanel();
		panel.setBackground(Color.MAGENTA);
		
		//Bήμα 2. Δημιουργία Γραφικών Συστατικών
		JButton button = new JButton("Press me!");
		JTextField textField = new JTextField(15);
		
		//Βήμα 3. Τοποθέτηση γραφ. συστατικών στον υποδοχέα
		panel.add(button);
		panel.add(textField);
		
		//Βήμα 4. Προσαρμογή υποδοχέα στο παράθυρο
		this.setContentPane(panel);
		
		
	}

}
