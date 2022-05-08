
public class Student {
	
	private String name;
	private String id;
	
	public Student(String name, String id) {
		this.name = name;
		this.id = id;
	}
	
	public String toString() {
		return (name + ", " + id);
	}
	
	public boolean equals(Object obj) {
	
		//casting
		Student otherStudent = (Student)obj;
		
		if(id.equals(otherStudent.id) && name.equals(otherStudent.name))
			return true;
		else
			return false;
		
	}

}
