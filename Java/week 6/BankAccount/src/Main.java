
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//otan stin iperklasi exo kataskevasti tote ipoxreotika prepi na exo kai stin ali klasi 
		BankAccount BA1 = new BankAccount("Stelios Xinogalos"); 
       
		BA1.printData();
		
		SavingsAccount BA2 = new SavingsAccount("X Y" , 0.5);
		
		//mporo na kaleso opia dipote methodo tis BankAccount meso tin Savings ACCOUNT
		
	    BA2.printData();
	    BA2.deposit(1000);
	    BA2.withdraw(200);
	    BA2.printData();
	    BA2.transfer(300,BA1);
	    
	    BA1.printData();
	    BA2.printData();
	    
	}

}
