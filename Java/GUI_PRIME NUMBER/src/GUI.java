import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.zip.CheckedInputStream;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame{
     private JPanel panel = new JPanel();
     private JTextField field = new JTextField("Number");
     private JButton button = new JButton("CHECK");
     private JButton button1 = new JButton("CLEAR");
     
     public GUI() {
    	 panel.add(field);
    	 panel.add(button);
    	 panel.add(button1);
    	 
    	 
    	 button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int a =0;
				check(a = Integer.parseInt(field.getText()));
				
				
			}

			private void check(int n) {
				// TODO Auto-generated method stub
				 int i;
				 int m = 0;
				 int flag = 0;  
				  m=n/2;      
				  if(n==0||n==1){  
				   System.out.println(n+" is not prime number");      
				  }else{  
				   for(i=2;i<=m;i++){      
				    if(n%i==0){      
				     System.out.println(n+" is not prime number");      
				     flag=1;      
				     break;      
				    }      
				   }      
				   if(flag==0)  { System.out.println(n+" is prime number"); }  
				  }//end of else  
			}
    		 
    	 });
    	 
    	 button1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
			    field.setText("");	
			}
    		 
    	 });
    	 
    	 
    	 
    	 this.setContentPane(panel);
    	 this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	 this.setVisible(true);
    	 this.setTitle("Prime Number Checker");
    	 this.setSize(400,400);
     }
}
