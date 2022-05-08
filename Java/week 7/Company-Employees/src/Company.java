import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Company {
	private String name;
	private ArrayList<Employee> employees = 
			new ArrayList<>();

	public Company(String name) {
		this.name = name;
	}
	
	public void addEmployee()
	{
		String answer = JOptionPane.showInputDialog(
		"Type of Employee? E:Employee, T:TechEmployee");
		
		String employeeName = JOptionPane.showInputDialog(
				"Enter the name of the employee:");
		String salaryText = JOptionPane.showInputDialog(
				"Enter the salary of the employee:");
		double salary = Double.parseDouble(salaryText);
		
		Employee emp;
		if ( answer.equalsIgnoreCase("E") )
		{
			emp = new Employee(employeeName, salary);			
		}
		else
		{
			double bonus = Double.parseDouble(
							JOptionPane.showInputDialog(
							"Enter the bonus of the tech-employee:")
							);  
			emp = new TechEmployee(employeeName, salary);
			((TechEmployee)emp).setBonus(bonus);			
		}	
		employees.add(emp);
	}
	
	public void printEmployees()
	{
		System.out.println("Company: " + name);
		double totalIncome = 0;
		
		for(Employee e : employees)
		{
			e.printIncome();
			totalIncome += e.calculateIncome();
		}
		
		System.out.println("Total = " + totalIncome + " Euro");
	}

}
