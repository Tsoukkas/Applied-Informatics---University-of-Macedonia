
public class Main {

	public static void main(String[] args) {
		
		Student s1 = new Student("John", "dai17040");
		Student s2 = new Student("Bob", "dai17040");
		
		//System.out.println invokes method toString of Student
		System.out.println(s1);
		
		//Check whether two objects are 'equal'
		if(s1.equals(s2))
			System.out.println("Students s1 and s2 refer to the same person");
		else
			System.out.println("Students s1 and s2 refer to different persons");
		
		
	}

}
