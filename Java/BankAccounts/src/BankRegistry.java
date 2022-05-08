import java.util.ArrayList;

public class BankRegistry {
	private String name;
	private ArrayList<BankAccount> accounts = new ArrayList<>();
	
	public BankRegistry(String name)
	{
		this.name = name;
	}
	
	public void addAccount(BankAccount ac)
	{
		accounts.add(ac);
	}
	
	public void printAccounts()
	{
		System.out.println("======== Bank: " + name + " ========");
		for(BankAccount ac : accounts)
		{
			ac.print();
		}
	}

}
