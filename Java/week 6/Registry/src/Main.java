
public class Main {

	public static void main(String[] args) {
		Student s1 = new Student("Nikos Nikolaou", "ics20034");
		Student s2 = new Student("Maria Papadopoulou");
				
		Course c1 = new Course("Java", 5);
		Course c2 = new Course("C", 5);
		
		ClassRoom lab334 = new ClassRoom("Erg 334", 35);
		ClassRoom amf13 = new ClassRoom("Amfitheatro 13", 100);
		
		c1.setMyClassRoom(lab334);
		
		c1.addStudent(s1);
		c1.addStudent(s2);
		
		c1.printStudentsInfo();
	}
}
