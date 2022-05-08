
public class Main {

	public static void main(String[] args) {
		BankAccount BA1 = new BankAccount("Mara Papadopoulou");
		BA1.deposit(500);
		BA1.setName("Maria Papadopoulou");
		BA1.print();
		
		SavingsAccount BA2 = new SavingsAccount("Nik Papas", 1.5);
		BA2.setName("Nikos Papas");
		BA2.deposit(200);
		BA2.withdraw(50);
		BA2.print();

		BA2.transfer(100, BA1);
		BA1.print();
		BA2.print();
		
		CheckingAccount BA3 = new CheckingAccount("Bob");
		BA3.print();
		
		BankRegistry bank = new BankRegistry("BANK");
		bank.addAccount(BA1);
		bank.addAccount(BA2);
		bank.addAccount(BA3);
		
		bank.printAccounts();
	}

}
