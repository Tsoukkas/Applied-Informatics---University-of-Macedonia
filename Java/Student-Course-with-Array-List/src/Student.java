
public class Student {
	private String name;
	private String id;
	private Course myCourse;
	
	//gia na mporo na theso kai ta dio mazi an thelo
	public Student(String text1, String text2)
	{
		name = text1;
		id = text2;
	}
	//an den theso to id mpeni aftomata to 9999
	public Student(String text1)
	{
		name = text1;
		id = "9999";
	}
	//epistrofi onomatos
	public String getName()
	{
		return name;
	}
	//epistrofi id
	public String getId()
	{
		return id;
	}
    //theto onoma
	public void setName(String aName)
	{
		if ( aName.length() > 0)
			name = aName;
		else
			System.out.println("Not a valid name");
	}
	//vazo mono id
	public void setId(String anId)
	{
		id = anId;
	}
	//ektiposi pliroforion
	public void printInfo()
	{
		System.out.println("-------------");
		System.out.println("Name: " + name);
		System.out.println("Id: " + getid());
		if ( myCourse!=null )
		{
			System.out.println("Course: " + myCourse.getName());
			System.out.println("Credits: " + myCourse.getCredits());
		}
		else
			System.out.println("*** No course selected");
	}
	//theto mathima
	public void setMyCourse(Course c)
	{
		myCourse = c;
	}
  //ektiposi vasikon pliroforion
	public void printBasicInfo()
	{
		System.out.println(name + " (" + id +")");
	}
}
