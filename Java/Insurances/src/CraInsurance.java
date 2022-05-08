
public class CraInsurance extends Insurance {
    private int cc;
    
    public CraInsurance(int a,String b,int c,int d) {
    	super(a,b,c);
    	this.cc = d;
    }

	public int getPososta() {
		return cc;
	}

	public void setPososta(int pososta) {
		this.cc = pososta;
	}
	
	public int getcost() {
		  return this.cc*this.getMouths()/60 ;
		}
	
	public String printDetails() {
		String a =null;
		a = "Car Insurance description:" +super.printDetails();
		return a;	
	}
}
