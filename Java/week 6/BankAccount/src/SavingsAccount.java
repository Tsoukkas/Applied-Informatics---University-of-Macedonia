

//klironomi ta panta apo tin bank account(oles tis methodus)
//edo tha valo mono methodus pou aforun tin savings account
public class SavingsAccount extends BankAccount {
         private double interestRate ;
	     
         public SavingsAccount(String name,double interestRate)
         {
        	 //kalo apo tin klasi bank account ton kataskevasti tis bankaccount
        	 
        	 super(name);
        	 this.interestRate = interestRate ;
         }
         
         public void addInterest() {
        
        	// double interest = getBalance() * interestRate/100;
        	 double interest = balance * interestRate/100 ;
        	 deposit(interest);
         
         }
         
         public void transfer(double amount , BankAccount ac) {
        	 withdraw(amount);
        	 ac.deposit(amount);
        	 
         }
        
         //Overriding
         public void printData() {
        	 System.out.println("Savings bank account: ");
        	 super.printData();
         }
}
