
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student s1 = new Student("Papadopoulos Nikos","iis21100");
        Student s2 = new Student("Papa Maria");
     
        s2.setId("ics21009");	
	   System.out.println("Id for student 2: "+ s2.getId());
	   
	  // s1.printInfo();
	  // s2.printInfo();
	   
	   Course c1 = new Course("Java",5);
	   Course c2 = new Course("PHP",5);
	   
	   s1.setMyCourse(c1);
	   s2.setMyCourse(c1);
	   
	   s1.printInfo();
	   s2.printInfo();
	   
	   
	   
	   
	}
	

}
