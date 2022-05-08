public class DataSet 
{
   private double sum;
   private Measurable maximum;
   private int count;

   public DataSet()
   {
     sum = 0;
     count = 0;
     maximum = null;
   }

   public void add(Measurable x)
   {
     sum = sum + x.getMeasure();
     if (count == 0 || maximum.getMeasure() < x.getMeasure()) 
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

   public Measurable getMaximum()
   {
     return maximum;
   }
}