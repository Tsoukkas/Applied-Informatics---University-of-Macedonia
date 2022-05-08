//Subclass
public class SavingsAccount extends BankAccount{
	private double interestRate;
	
	public SavingsAccount(String name, double interestRate)
	{
		super(name);
		this.interestRate = interestRate;
	}
	
	public SavingsAccount(String name, double balance, double interestRate)
	{
		super(name, balance);
		this.interestRate = interestRate;
	}
	
	public void addInterest()
	{
		//double interest = getBalance() * interestRate/100;
		double interest = balance * interestRate/100;
		deposit(interest);
	}

	public void transfer(double amount, BankAccount ac)
	{
		withdraw(amount);
		ac.deposit(amount);
	}
	
	//override
	public void print()
	{
		System.out.print("*** Savings bank account:");
		super.print();
	}
}
