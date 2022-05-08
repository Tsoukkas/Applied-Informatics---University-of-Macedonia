
public class TestCustomer {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       Account a1 = new Account(1234,100000);
       Account a2 = new Account(5678,20000);
       
       Customer c1 = new Customer("John",a1,a2,641274);
       
       a1.deposit(50);
       a2.deposit(80);
       
       a1.withdraw(10);
       a2.withdraw(20);
       
       c1.printAccounts();
       
	}

}
