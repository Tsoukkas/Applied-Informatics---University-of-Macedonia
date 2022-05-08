
public class Employee {
	protected String name;
	protected double salary;
	
	public Employee(String name, double salary)
	{
		this.name = name;
		this.salary = salary;
	}
	
	public double calculateIncome()
	{
		return salary*0.8;
	}
	
	public void printIncome()
	{
		System.out.println("Monthly income for "
				+ name + " is " + 
				calculateIncome() + " Euro");
	}
}