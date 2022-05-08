package fevruarios2020;

public class CarInsurance extends Insurance {
     private int cc;
     
     public CarInsurance(int a,String b,int c,int d) {
    	 super(a,b,c);
    	 this.cc=d;
     }

	

	public int getCc() {
		return cc;
	}

	public void setCc(int cc) {
		this.cc = cc;
	}
    
	public  double asfalia() {
		return cc*this.getDiarkia()/60;
	}
	
	public  String print() {
	    String a = "Car Insurance description: "
	    		+ "code: "+ this.getCode() +
	    		 "Surname: "+ this.getSurname()+
	    		 "Diarkia: "+ this.getDiarkia()+
	    		 "Cost: " + this.asfalia();
	    return a;
	}
     
}
