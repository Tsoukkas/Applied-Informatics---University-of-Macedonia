
public class Truck extends Vehicle {
     private double fortio;
     private double dinatotita;
     
	public Truck(String brand1,String owner1,int cc1,double fortio,double dinatotita) {
		super(brand1,cc1,owner1);
		this.fortio = fortio;
		this.dinatotita = dinatotita;
	}

	public double getFortio() {
		return fortio;
	}

	public void setFortio(double fortio) {
		this.fortio = fortio;
	}

	public double getDinatotita() {
		return dinatotita;
	}

	public void setDinatotita(double dinatotita) {
		this.dinatotita = dinatotita;
	}
	
     
}
