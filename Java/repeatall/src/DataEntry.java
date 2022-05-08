import java.util.ArrayList ;
import javax.swing.JOptionPane;
public class DataEntry {
	
	public void readData(ArrayList<Student> students) 
	{
		while(true) {
	String type =	JOptionPane.showInputDialog("Student type? Give 1=Stud, 2=Grad");
		
		int selection = Integer.parseInt(type);
		
		String name = JOptionPane.showInputDialog("Name?");
		String id = JOptionPane.showInputDialog("Id?");
		
		String supervisor = null ;
		if (selection == 2) {
			 supervisor = JOptionPane.showInputDialog("Supervisor");
			
		}
		Student s;
		if(selection == 1) {
			s = new Student(name , id);
			
		} else {
			s = new GraduateStudent(name,id,supervisor);
		}
		
		students.add(s);
		String answer = JOptionPane.showInputDialog("Continue? Y/N");
		if(answer.equalsIgnoreCase("N")) {
			break;
		}
		}
	
	}

}
