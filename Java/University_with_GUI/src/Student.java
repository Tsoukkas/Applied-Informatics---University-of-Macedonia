import java.util.ArrayList;

public class Student {
	
	private String name;
	private String AM;
	//υλοποίηση συσχέτισης φοιτητή με μαθήματα
	private ArrayList<Course> courses;
	
	public Student(String name, String aM) {
		this.name = name;
		AM = aM;
		courses = new ArrayList<Course>();
	}
	
	public void enrollIn(Course aCourse) {
		courses.add(aCourse);
	}
	
	public void printInfo() {
		System.out.println("Student name: " + name);
		System.out.println("Student AM: " + AM);
		System.out.println("----------------");
	}

}
