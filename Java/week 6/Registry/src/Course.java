import java.util.ArrayList;

public class Course {
	private String name;
	private int credits;
	private ArrayList<Student> enrolledStudents;
	private ClassRoom myClassRoom;
	
	public Course(String aCourse, int number)
	{
		name = aCourse;
		credits = number;
		enrolledStudents = new ArrayList<Student>();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getCredits() {
		return credits;
	}

	public void setCredits(int credits) {
		this.credits = credits;
	}	
	
	public void addStudent(Student s)
	{
		if ( myClassRoom.getCapacity() > enrolledStudents.size() ) 
		{
			enrolledStudents.add(s);
			s.setMyCourse(this);
		}
		else
			System.out.println("Sorry the course is full!");						
	}
	
	public void printStudentsInfo()
	{
		System.out.println("====== COURSE: " + name + " =======");
		System.out.println("Classroom: " + myClassRoom.getLocation());
		System.out.println("List of students => ");
		
		for(Student s : enrolledStudents)
		{
			System.out.println(s.getName() + " (" + s.getId() + ")");
		}		
	}
	
	public void setMyClassRoom(ClassRoom c)
	{
		myClassRoom = c;
	}
}