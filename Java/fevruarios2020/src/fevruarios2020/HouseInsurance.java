package fevruarios2020;

public class HouseInsurance extends Insurance{
	private int tetragonika;
	
	public HouseInsurance(int a,String b,int c,int d) {
		super(a,b,c);
		this.tetragonika=d;
	}

	public int getTetragonika() {
		return tetragonika;
	}

	public void setTetragonika(int tetragonika) {
		this.tetragonika = tetragonika;
	}
	
	public  double asfalia() {
		return tetragonika*this.getDiarkia()/10;
	}
	
	public  String print() {
	    String a = "House Insurance description: "
	    		+ "code: "+ this.getCode() +
	    		 "Surname: "+ this.getSurname()+
	    		 "Diarkia: "+ this.getDiarkia()+
	    		 "Cost: " + this.asfalia();
	    return a;
	}

}
