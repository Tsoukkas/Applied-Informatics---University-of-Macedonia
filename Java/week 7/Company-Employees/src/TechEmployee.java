
public class TechEmployee extends Employee {
	private double bonus;
	
	public TechEmployee(String name, double salary) {
		super(name, salary);
		bonus = 0;
	}
	
	public void printIncome()
	{
		super.printIncome();
		System.out.println("Bonus: " + bonus + " Euro");
	}
	
	public double calculateIncome()
	{
		return salary*0.7 + bonus;
	}

	public void setBonus(double bonus)
	{
		this.bonus = bonus;
	}
}
