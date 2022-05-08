import java.util.ArrayList ;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		Course C1 = new Course("Java",5);
		Course C2 = new Course ("C" , 5);
		
		Student S1 =new Student("Nikos", "ics20100");
		
		S1.addCourse(C1);
		S1.addCourse(C2);
		S1.printInfo();
        
		GraduateStudent S2 = new GraduateStudent("Maria" , "iis20045" , "Petros Nikolaou");
		S2.addCourse(C1);
		S2.printInfo();
		*/
		ArrayList<Student> students = new ArrayList<>();
		
		DataEntry data = new DataEntry();
		data.readData(students);
		
		for(Student s : students) {
			s.printInfo();
		}
		
	}

}
