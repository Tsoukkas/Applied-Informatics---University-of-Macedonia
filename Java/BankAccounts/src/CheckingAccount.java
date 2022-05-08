public class CheckingAccount extends BankAccount{
    
    private int transactionsCount;
    private static final int FREE_TRANSACTIONS=3;
    private static final double TRANSACTION_FEE = 2.0;
    
    public CheckingAccount(String name, double initialBalance){
        super(name, initialBalance);
        transactionsCount=0;
    }
    
    public CheckingAccount(String name){
        super(name);
        transactionsCount=0;
    }
    
    public void deposit(double amount){
        transactionsCount++;
        super.deposit(amount);       
    }
    
    public void withdraw(double amount){
        transactionsCount++;
        super.withdraw(amount);
    }
    
    public void deductFees(){
        if (transactionsCount > FREE_TRANSACTIONS)
        {
            double fees=TRANSACTION_FEE*(transactionsCount -FREE_TRANSACTIONS);
            super.withdraw(fees);
        }
        transactionsCount=0;
    }     
    
    public void print()
    {
        System.out.print("*** Checking bank account: ");
        super.print();
    }
}