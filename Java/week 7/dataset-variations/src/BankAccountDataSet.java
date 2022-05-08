public class BankAccountDataSet
{
   private double sum;
   private BankAccount maximum;
   private int count;

   public BankAccountDataSet()
   {
     sum = 0;
     count = 0;
     maximum = null;
   }

   public void add(BankAccount x)
   {
     sum = sum + x.getBalance();
     if (count == 0 || maximum.getBalance() < x.getBalance()) 
        maximum  = x;
     count++;
   }

   public double getAverage()
   {
     if (count == 0) 
        return 0;
     else 
        return sum / count;
   }

   public BankAccount getMaximum()
   {
     return maximum;
   }
}