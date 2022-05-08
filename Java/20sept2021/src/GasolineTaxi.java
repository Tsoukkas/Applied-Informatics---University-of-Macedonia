
public class GasolineTaxi extends Taxi {
    private int posotita;
    private double katanalosi;
    
    public GasolineTaxi(String a,String b, int c , double d) {
    	super(a,b);
    	this.posotita = c;
    	this.katanalosi = d;
    }

	public int getPosotita() {
		return posotita;
	}

	public void setPosotita(int posotita) {
		this.posotita = posotita;
	}

	public double getKatanalosi() {
		return katanalosi;
	}

	public void setKatanalosi(double katanalosi) {
		this.katanalosi = katanalosi;
	}
    
	public double returnAftonomia() {
		double a = 0;
		a =  (90*this.posotita / this.katanalosi) ;
		return a ;
	}
}
