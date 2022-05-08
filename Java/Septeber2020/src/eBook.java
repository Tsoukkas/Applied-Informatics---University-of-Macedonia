
public class eBook extends GeneralBook {
    private double mb;
    
    public eBook(String a,String b,int c,double m) {
    	super(a,b,c);
    	mb=m;
    }
 
    public boolean iseBook() {
    	return true;
    }
    
	public double getMb() {
		return mb;
	}

	public void setMb(double mb) {
		this.mb = mb;
	}
	
	public void print() {
		//eBook: τίτλος, επώνυμο, (κωδικός), μέγεθος
		System.out.println(this.getTitle() + ", "+ this.getAuthor()+ ", ("+ this.getCode() +"), "+ this.getMb());
	}
    
}
