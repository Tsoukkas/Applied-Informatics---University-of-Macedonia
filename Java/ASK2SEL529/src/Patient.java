
public class Patient extends Person {
     private String Id;
     
     public Patient(String name,String id)
     {
    	 super(name);
    	 this.Id = id;
     }

	public String getId() {
		return Id;
	}

	public void setId(String id) {
		Id = id;
	}
     
	public void printDetails() {
		System.out.println("-------");
		System.out.println("Name: " + super.getName());
		System.out.println("Id: " + Id);
	}
}
