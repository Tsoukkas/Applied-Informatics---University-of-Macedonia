import java.util.ArrayList;
public class Student {
   protected String name;
   protected String id;
   private ArrayList<Course> courses ;
   
public Student(String text,String text2) {
	this.name=text;
	this.id=text2;
	courses = new ArrayList<>() ; 
	
}

public void addCourse(Course c) {
	courses.add(c);
}

public void printInfo() {
	System.out.println("---------------------");
	System.out.println(name + "(" + id + ")");
	
		for(Course c: courses) {
			System.out.println(c.getName() + "," + c.getCredits() + " ECTS");
		}
		System.out.println("Number of Courses: " + courses.size());
	}
}
   

