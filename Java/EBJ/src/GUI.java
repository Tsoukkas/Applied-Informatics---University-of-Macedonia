import java.util.ArrayList;
import javax.swing.JOptionPane;
public class GUI {
	public static void main(ArrayList<Measurable> books) {
     boolean more = true;
     while(more) {
    	 Measurable x = null;
    	 String type = JOptionPane.showInputDialog("What is the type of this thing? (1=BOOKS 2=JURNAL)");
    	 
    	 int selection = Integer.parseInt(type);
    	 
    	 if(selection ==1) {
    	 
    	 String title = JOptionPane.showInputDialog("Give me the title of the book:");
    	 
    	 String author = JOptionPane.showInputDialog("What is the name of the author?");
    	 
    	 String editor = JOptionPane.showInputDialog("Do you remember the name of the editor?");
    	 
    	 String years = JOptionPane.showInputDialog("The year of the book please bro");
    	 
    	 int year = Integer.parseInt(years);
    	 
    	 String ISBN = JOptionPane.showInputDialog("Give me the ISBN bro");
    	 
    	 String copies1 = JOptionPane.showInputDialog("Give me the number of copies please");
    	 
    	 int copies = Integer.parseInt(copies1);
    	 
    	 String refNumber = JOptionPane.showInputDialog("refNumber pleaseee");
    	 
    	 x = new Book(title,author,editor,year,ISBN,copies,refNumber);
    	 
    	 }
    	 
    	 else {
    		 
    		 String title = JOptionPane.showInputDialog("Give me the title of the book:");
        	 
        	
        	 
        	 String editor = JOptionPane.showInputDialog("Do you remember the name of the editor?");
        	 
        	 String years = JOptionPane.showInputDialog("The year of the book please bro");
        	 
        	 int year = Integer.parseInt(years);
    		 
        	 String volume1 = JOptionPane.showInputDialog("Give us the volume please ");
        	 
        	 int volume = Integer.parseInt(volume1) ;
        	 
             String issue1 = JOptionPane.showInputDialog("Give us the issue please ");
        	 
        	 int issue = Integer.parseInt(issue1) ;
        	 
        	 String ISBN = JOptionPane.showInputDialog("Give me the ISBN bro");
        	 
        	 String copies1 = JOptionPane.showInputDialog("Give me the number of copies please");
        	 
        	 int copies = Integer.parseInt(copies1);
        	 
        	 String refNumber = JOptionPane.showInputDialog("refNumber pleaseee");
        	 
        	 x = new Journal(title,editor,year,volume,issue,ISBN,copies,refNumber);
    	 }
    	 
    	 books.add(x);
    	 
    	 String answer = JOptionPane.showInputDialog("Want more (Y/N)");
    	 
    	 
    	 
    	 if(answer.equals("N")) {
    		 more = false;
    	 }
     }
	}
}