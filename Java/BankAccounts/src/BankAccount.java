//Superclass
public class BankAccount {
	protected String name;
	protected double balance;
	
	public BankAccount(String name)
	{
		this.name = name;
		balance = 0;
	}
	
	public BankAccount(String name, double balance)
	{
		this.name = name;
		this.balance = balance;
	}
	
	public void deposit(double amount)
	{
		balance += amount;
	}
	
	public void withdraw(double amount)
	{
		if ( amount <= balance )
			balance -= amount;
		else
			System.out.println("Not enough money");
	}
	
	public void print()
	{
		System.out.println(name + ", " + balance + " Euro");
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		if ( name.length() > 0 )
			this.name = name;
		else
		System.out.println("Not a valid value. Please give the name!");
	}

	public double getBalance() {
		return balance;
	}

	public void setBalance(double balance) {
		this.balance = balance;
	}	
}
