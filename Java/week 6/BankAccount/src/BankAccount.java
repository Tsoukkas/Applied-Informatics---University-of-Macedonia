
public class BankAccount {
	protected String name;
	protected double balance;
//thelume 2 kataskevastes gt theli me to an theto logariasmo i an oxi na iparxi kati stathero
	public BankAccount(String name) 
	{
		this.name = name ;
		balance = 0;
	}

public void printData() {
		System.out.println(name + ", " + balance + " euro");
	}
	
public void deposit(double amount) {
	balance += amount ;
}

public void withdraw(double amount) {
	balance -= amount;
}

public String getName() {
	return name;
}

public void setName(String name) {
	this.name = name;
}

public double getBalance() {
	return balance;
}

public void setBalance(double balance) {
	this.balance = balance;
}
	
}
