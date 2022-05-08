
public class Student {
	private String name;
	private String id;
	private Course myCourse;
	//theti onoma kai id
	public Student(String text1, String text2) {
		
		name=text1;
		id=text2;
		}
	//theti onoma kai mpeni to id apo mono tu to 9999
	public Student(String text1) {
		name=text1;
		id="9999";
	}
	//vazi mono id 
	public void setId(String anId) {
		id=anId;
	}
	//epistrefi to id
	public String getId()
	{
		return id;
	}
	//epistrefi to onoma
	public String getName() {
		return name;
	}
	//ektiposi pliroforion
	public void printInfo()
	{
		System.out.println("---------------");
		System.out.println("Name:"+name);
		System.out.println("Id:"+getId());
		if (myCourse!=null) {
		System.out.println("Course:"+myCourse.getName());
		System.out.println("Credits:"+myCourse.getCredits());
		}
		else
			System.out.println("No course selected!");
	}
	//theti mathima (ginete se sinartisi alis klasis mmazi me tin prosthiki mathiti gt den iparxi logos na kanume dio ksexoristus vroxus mpori na gini se 1
	public void setMyCourse(Course c) {
		myCourse= c;
		
	}
	
}
