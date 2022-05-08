
public class Student {
	private String id;
	private String Name;
	private Course myCourse;
//vazi gia na thesi kai name kai id mazi 	
public Student(String text1,String text2) {
	id = text2;
	Name = text1;
}
//theti mono onoma kai mpeni default to id 999
public Student(String text1) {
	id = "999";
	Name = text1;
}
//theti mono id
public void setId(String anId) {
	 id = anId;
}
//epistrefi id
public String getId() {
	return id;
}
//ektiposi pliroforion siggekrimenu mathiti
public void printInfo() {
	System.out.println("-----------");
	System.out.println("Name: "+ Name);
	System.out.println("Id: "+ getId());
    if( myCourse!=null ) {
	System.out.println("Course: "+ myCourse.getName());
    System.out.println("Credits:"+ myCourse.getCredits());
    }
    else
    	System.out.println("No course selected!");
}
//theti mathima
public void setMyCourse(Course c) {
	myCourse = c;
}


}
