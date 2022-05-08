import java.util.ArrayList;

import javax.swing.JOptionPane;


public class DataInput {
	
	public static void read(ArrayList<Employee> employees) {
		//ανάγνωση δεδομένων απο το χρήστη
		
		boolean more = true;
		
		while(more) {
			
			String employeeType = 
					JOptionPane.showInputDialog("What type of employee? (A: Hourly employee, B: Salaried)"); 
			
			String name = JOptionPane.showInputDialog("Enter Name");
			
			Employee employee;
			if(employeeType.equals("A")) {
				String wageText = JOptionPane.showInputDialog("Wage?");
				double wage = Double.parseDouble(wageText);
				String hoursText = JOptionPane.showInputDialog("Hours?");
				int hours = Integer.parseInt(hoursText);
				employee = new HourlyEmployee(name, wage, hours);
			}
			else {
				String salaryText = JOptionPane.showInputDialog("Salary?");
				double salary = Double.parseDouble(salaryText);
				String extrasText = JOptionPane.showInputDialog("Extras?");
				int extras = Integer.parseInt(extrasText);
				employee = new SalariedEmployee(name, salary, extras);
			}
			
			employees.add(employee);
			
			String answer = JOptionPane.showInputDialog("More? (yes/no)");
			if(answer.equals("no"))
				more = false;			
		}
	}

}