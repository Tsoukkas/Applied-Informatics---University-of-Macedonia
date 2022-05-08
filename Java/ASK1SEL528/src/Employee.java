
public class Employee extends Person {
     private double year_salary;
     private int year;
     private String number;
     
     public Employee(String name,double a,int b,String n) {
    	 super(name);
    	 this.year_salary = a;
    	 this.year = b;
    	 this.number = n;
     }

	public double getYear_salary() {
		return year_salary;
	}

	public void setYear_salary(double year_salary) {
		this.year_salary = year_salary;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public String getNumber() {
		return number;
	}

	public void setNumber(String number) {
		this.number = number;
	}
	
	public boolean equals(Employee other) {
		return this.name == other.name;
	}
}
