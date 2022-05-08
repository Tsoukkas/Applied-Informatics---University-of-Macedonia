
public class Billing {
    private Patient a;
    private Doctor b;
    
    public Billing(Patient a,Doctor b) {
    	this.a = a;
    	this.b = b;
    }
    
    
    public void printDetails(double x) {
    	System.out.println("--------");
    	System.out.println("Sum= "+ b.isodima(x));
    }
}
