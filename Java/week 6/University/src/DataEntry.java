import java.util.ArrayList;
import javax.swing.JOptionPane;

public class DataEntry {

	public static void readData(ArrayList<Student> students)
	{
		String answer;
		do{
			String type = JOptionPane.showInputDialog("Student type? 1:Stud, 2:Grad");
			int selection = Integer.parseInt(type);
			
			String name = JOptionPane.showInputDialog("Student name?");
			String id = JOptionPane.showInputDialog("Student ID?");
			
			String supervisor=""; //i null
			if ( selection==2 ){
				supervisor = JOptionPane.showInputDialog("Supervisor?");
			}

			Student student;
			if ( selection==1 ){
				student = new Student(name, id);
			}
			else{
				student = new GraduateStudent(name, id, supervisor);
			}
			students.add(student);
			
			answer = JOptionPane.showInputDialog("More students? y/n");
		}while(answer.equalsIgnoreCase("y"));		
				
	}

	
}
