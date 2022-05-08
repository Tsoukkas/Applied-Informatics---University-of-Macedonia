
public class Main {

	public static void main(String[] args) {
		Student s1= new Student("Papadopoulos Nikos","iis21100");
		Student s2= new Student("Papa Maria");
		
		s2.setId("ics21009");
		//System.out.println("Id for student 2:"+ s2.getId());
		
		//s1.printInfo();
		//s2.printInfo();
		
		Course c1 = new Course("Java",5);
		Course c2 = new Course("PHP",5);
		//o s1 exi epileksi to mathima c1
		s1.setMyCourse(c1);
		s2.setMyCourse(c1);
		
		//s1.printInfo();
		//s2.printInfo();
		//vazi ton siggekrimeno mathiti stin lista me to mathima c1 i c2
		c1.addStudent(s1);
		c1.addStudent(s2);
		
		c1.printStudentsInfo();
		//den to vazume epd den valame kapio mathiti na exi to c2
		//c2.printStudentsInfo();
	}

}
