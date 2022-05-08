
public class Main {

	public static void main(String[] args) {
		Company comp = new Company("My company");
		
		for(int i=1; i<=2; i++)
		{
			comp.addEmployee();
		}
		
		comp.printEmployees();		
	}

}
