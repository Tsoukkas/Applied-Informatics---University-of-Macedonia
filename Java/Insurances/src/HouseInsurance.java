
public class HouseInsurance extends Insurance {
     private int squares;
     
     public HouseInsurance(int a,String b,int c,int d){
    	 super(a,b,c);
    	 this.squares = d;
     }

	public int getSquares() {
		return squares;
	}

	public void setSquares(int squares) {
		this.squares = squares;
	}
    
	public int getcost() {
	  return this.squares*this.getMouths()/10 ;
	}
	
	public String printDetails() {
	   String a =null;
		a = "House Insurance description:" + super.printDetails(); 
		return a;	
	}
}
