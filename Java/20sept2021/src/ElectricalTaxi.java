
public class ElectricalTaxi extends Taxi {
    private int batteries;
    
    public ElectricalTaxi(String a,String b,int c) {
    	super(a,b);
    	this.batteries = c;
    }

	public int getBatteries() {
		return batteries;
	}

	public void setBatteries(int batteries) {
		this.batteries = batteries;
	}
    
	public double returnAftonomia() {
		double a = 0;
		a =  70*this.batteries;
		return a ;
	}
}
