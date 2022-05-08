
public class MolecularTest extends DiagnosticTest {
      private double accuracy;
      
      public MolecularTest(String a,String b,boolean c,String d,double e) {
    	  super(a,b,c,d);
    	  this.accuracy = e;
      }

	public double getAccuracy() {
		return accuracy;
	}

	public void setAccuracy(double accuracy) {
		this.accuracy = accuracy;
	}
    
	public String writer() {
		String a =null;
		a = "Molecular Test, date:"+ this.getDate() + "Result: "+ this.isResult()+" Type: "+this.getType()+ "Accuracy: "+ this.getAccuracy();
		return a ;
	}
}
