import java.util.ArrayList;

public class Course {
	
	private String title;
	private String instructor;
	private ArrayList<Student> students;
	
	public Course(String title, String instructor) {
		this.title = title;
		this.instructor = instructor;
		students = new ArrayList<Student>();
	}
	
	public String getTitle() {
		return title;
	}
	
	public void addStudent(Student aStudent) {
		students.add(aStudent);
		aStudent.enrollIn(this);
	}
	
	public void printCourseDetails() {
		System.out.println("Course title: " + title);
		System.out.println("Course instructor: " + instructor);
		for(Student student : students)
			student.printInfo();
		System.out.println("----------------");
	}
	

}
