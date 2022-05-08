public class CoinDataSet 
{
   private double sum;
   private Coin maximum;
   private int count;

   public CoinDataSet()
   {
     sum = 0;
     count = 0;
     maximum = null;
   }

   public void add(Coin x)
   {
     sum = sum + x.getValue();
     if (count == 0 || maximum.getValue() < x.getValue()) 
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

   public Coin getMaximum()
   {
     return maximum;
   }
}