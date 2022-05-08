import java.util.ArrayList;

public class Course {
	private String name;
	private int credits;
	//dimiourgia listas
	private 	ArrayList<Student> enrolledStudents = new ArrayList<>();
	private int counter = 0;
	
	public Course(String name, int credits)
	{
		this.name = name;
		this.credits = credits;
	}
	
	public String getName()
	{
		return name;
	}
	
	public int getCredits()
	{
		return credits;
	}	
	
	public void addStudent(Student s)
	{
		//vazis ton mathiti sto mathima
			enrolledStudents.add(s);
			//gia to mathima ston mathiti
			s.setMyCourse(this);
	}
	
	public void printStudentsInfo()
	{
		System.out.println("Course: " + name);
		System.out.println("------------------");
	//	for(int i=0; i<enrolledStudents.size(); i++)
			
		//{
			//Student s = enrolledStudents.get(i);
			//s.printInfo();
			
			//OR
			//(enrolledStudents.get(i)).printInfo();
			
		//or
			for(Student s : enrolledStudents) { 
			s.printBasicInfo();                
			
		}
	}

	public void setName(String name) {
		this.name = name;
	}
	                                                                                                                                                                                                 
}
