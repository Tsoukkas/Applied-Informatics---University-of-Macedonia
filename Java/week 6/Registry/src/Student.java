
public class Student {
 	private String name;
	private String id;
	private Course myCourse;
	
	public Student(String aName, String anId)
	{
		name = aName;
		id = anId;
	}
	
	public Student(String aName)
	{
		name = aName;
		id = "9999";
	}
	
	//Μέθοδος μετάλλαξης or mutator method or setter
	public void setName(String aname)
	{
		if ( aname.length() > 0 )
			name = aname;
		else
			System.out.println("Not a valid name");
	}
	
	public void setId(String ID)
	{
		id = ID;
	}
	
	//Μέθοδος πρόσβασης or accessor method or getter
	public String getName()
	{
		return name;
	}
	
	public String getId()
	{
		return id;
	}
	
	public void printInfo()
	{
		System.out.println("------------");
		System.out.println("Name: " + name);
		System.out.println("Id: " + id);
		if ( myCourse != null )
			System.out.println("Course: " + myCourse.getName() 
		                  + " (" + myCourse.getCredits() + ")" );
		else
			System.out.println("No course selected!");
	}
	
	public void setMyCourse(Course c)
	{
		myCourse = c;
	}
}