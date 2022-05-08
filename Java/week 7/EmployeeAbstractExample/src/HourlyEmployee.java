//���������� ���������

public class HourlyEmployee extends Employee {
	
	private double wage;
	private int hours;

	public HourlyEmployee(String name, double wage, int hours) {
		super(name);
		this.wage = wage;
		this.hours = hours;
	}
	
	// ����������� �������� ������ => wage * hours
	public double calculateSalary()
	{			
		return wage*hours;
	}
}
