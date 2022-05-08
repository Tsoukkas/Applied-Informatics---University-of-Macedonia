
public class Customer {
   private String name;
   private Account depositAC;
   private Account checkingAC;
   private int mobile;
   
   public Customer(String a,Account b,Account c,int mobile) {
	   this.name = a;
	   this.checkingAC = b;
	   this.depositAC = c;
	   this.mobile = mobile ;
   }
   
 
   public void printAccounts() {
	   System.out.println("Name of Customer "+ this.name);
	   System.out.println("DepositAC: " +depositAC.getIBAN()+
	                       "Total: " + depositAC.getTotal());
	   System.out.println("DepositAC: " +checkingAC.getIBAN()+
               "Total: " + checkingAC.getTotal());
   }
   
}
