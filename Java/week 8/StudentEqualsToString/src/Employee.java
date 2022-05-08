
public class Employee {
	
	private String firstName;
	private String lastName;
	private double salary;
	
	public Employee(String firstName, String lastName, double salary) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.salary = salary;
	}
	
	public boolean equals(Object obj) {
		Employee otherEmployee = (Employee)obj;
		
		return (lastName.equals(otherEmployee.lastName));
	}
	

}
