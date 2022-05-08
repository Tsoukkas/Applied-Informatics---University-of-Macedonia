import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		ArrayList<Course> courses;
		
		courses = new ArrayList<Course>();
		courses.add(new Course("Java", "Papadopoulos"));
		courses.add(new Course("Math", "Stephanides"));
		courses.add(new Course("Databases", "Ioannou"));
		courses.add(new Course("Digital Economy", "Stiakakis"));
		
		new EnrollmentFrame(courses);
	}

}
