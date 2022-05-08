import java.util.ArrayList;
public class Main {

	public static void main(String[] args) {
		//theti mathites
		Student s1 = new Student("Nikos", "dai19100");
		Student s2 = new Student("Maria");
		//theti mathiata
		Course c1 = new Course("Java", 5);
		Course c2 = new Course("PHP", 5);
		//vazi mathimata stus mathites
		s1.setMyCourse(c1);
		s2.setMyCourse(c1);
		//vazi sta mathimata mathites
		c1.addStudent(s1);
		c1.addStudent(s2);
		//ektiponi tus mathites tu mathimatos c1		
		c1.printStudentsInfo();	
		
		
		
	}

}
