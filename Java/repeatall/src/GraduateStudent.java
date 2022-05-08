
public class GraduateStudent extends Student {
	private String supervisor; 
	
  public GraduateStudent(String name ,String id ,String text2) {
	  super(name , id);
	  this.supervisor = text2;
  }
	  
  public void printInfo() {
	  System.out.println("*** Graduate student:");
	  super.printInfo();
	  System.out.println("Supervisor : " + supervisor);
  }
  }
