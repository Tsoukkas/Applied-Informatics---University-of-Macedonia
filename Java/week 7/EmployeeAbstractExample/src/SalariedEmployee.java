//ÌÉÓÈÙÔÏÓ ÕÐÁËËÇËÏÓ

public class SalariedEmployee extends Employee {
	
	private double salary;
	private double extras;

	public SalariedEmployee(String name, double salary, double extras) {
		super(name);
		this.salary = salary;
		this.extras = extras;
	}
	
	// Õðïëïãéóìüò ìçíéáßïõ ìéóèïý => salary + extras
	public double calculateSalary()
	{				
		return salary + extras;
	}
}
