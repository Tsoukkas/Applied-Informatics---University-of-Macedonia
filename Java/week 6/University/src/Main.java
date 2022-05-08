import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		Course C1 = new Course("Java", 5);
		Course C2 = new Course("C", 5);
		
		Student S1 = new Student("Nikos", "ics20100");
		S1.addCourse(C1);
		S1.addCourse(C2);
		
		GraduateStudent S2 = new GraduateStudent("Maria", "mai20100", "Pappadopoulos");
		S2.addCourse(C1);
		
		ArrayList<Student> students = new ArrayList<>();
		students.add(S1);
		students.add(S2);
		
		DataEntry.readData(students);
		
		for(Student s : students)
		{
			s.printInfo();
		}		
	}
}