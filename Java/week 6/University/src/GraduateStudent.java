
public class GraduateStudent extends Student {
	private String supervisor;
	
	public GraduateStudent(String name, String id, String supervisor) {
		super(name, id);
		this.supervisor = supervisor;
	}
	
	public void printInfo()
	{
		super.printInfo();
		System.out.println("Supervisor: " + supervisor);
	}
}
