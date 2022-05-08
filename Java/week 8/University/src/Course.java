import java.util.ArrayList;

public class Course {
	
	private String name;
	private ArrayList<Student> students = new ArrayList();

	public Course(String name) {
		this.name = name;
	}
	
	public void enrollStudent(Student aStudent) {
		students.add(aStudent);
		System.out.println("A student has been enrolled");
	}
	
	public void printCourseDetails() {
		System.out.println("-----------------");
		System.out.println("Course: " + name);
		System.out.println("---has the following students---");
		for(Student stud: students)
			System.out.println(stud);
	}
	
	public String getName() {
		return name;
	}
}
