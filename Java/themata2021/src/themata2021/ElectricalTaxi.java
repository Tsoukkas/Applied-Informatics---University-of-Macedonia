package themata2021;

public class ElectricalTaxi extends Taxi {
     private int plithos_mpatarion;
     
     public ElectricalTaxi(String a,String b,int c) {
    	 super(a,b);
    	 this.plithos_mpatarion = c;
     }

	public int getPlithos_mpatarion() {
		return plithos_mpatarion;
	}

	public void setPlithos_mpatarion(int plithos_mpatarion) {
		this.plithos_mpatarion = plithos_mpatarion;
	}
     
	public double aftonomia() {
		return 70*plithos_mpatarion;
	}
}
