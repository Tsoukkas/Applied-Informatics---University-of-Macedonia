import java.util.ArrayList;

public class Student {
	private String name;
	private String id;
	private ArrayList<Course> courses;
	
	public Student(String name, String id)
	{
		this.name = name;
		this.id = id;
		courses = new ArrayList<>();
	}
	
	public void addCourse(Course c)
	{
		courses.add(c);
	}
	
	public void printInfo()
	{
		System.out.println("-----------------");
		System.out.println("Name: " + name);
		System.out.println("ID: " + id);
		for(Course c : courses)
		{
			System.out.println(c.getName() + " (" + c.getCredits() + " ECTS)");
		}
		System.out.println("Number of courses: " + courses.size());	
	}
}
