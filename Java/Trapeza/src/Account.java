
public class Account {
    private int IBAN;
    private int total ;
    
    public Account(int a , int b) {
    	this.IBAN = a;
    	this.total = b;
    }

	public int getIBAN() {
		return IBAN;
	}

	public void setIBAN(int iBAN) {
		IBAN = iBAN;
	}

	public int getTotal() {
		return total;
	}

	public void setTotal(int total) {
		this.total = total;
	}
    
    public void deposit(int number) {
    	this.total += number;
    }
    
    public void withdraw(int number) {
    	if(this.total < number) {
    		System.out.println("You dont have this amount of money in your Bank Account");
    	}
    	else {
    	this.total -= number;
    	    System.out.println("Withdraw Succesful");
        }
    }
    
    
}
