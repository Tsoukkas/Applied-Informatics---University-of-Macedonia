package themata2021;

public class GasolineTaxi extends Taxi {
    private int litra;
    private double katanalosi;
    
    public GasolineTaxi(String a,String b,int c,double d) {
    	super(a,b);
    	litra = c;
    	katanalosi = d;
    }

	public int getlitra() {
		return litra;
	}

	public void setlitra(int rezevuar_vezinis) {
		this.litra = rezevuar_vezinis;
	}

	public double getKatanalosi() {
		return katanalosi;
	}

	public void setKatanalosi(double katanalosi) {
		this.katanalosi = katanalosi;
	}
	public double aftonomia() {
		return 90*(litra/katanalosi);
	}
}
