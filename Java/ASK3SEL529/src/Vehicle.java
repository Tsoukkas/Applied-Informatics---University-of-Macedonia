
public class Vehicle extends Person{
     private String brand;
     private int cc;
     
     public Vehicle(String brand,int cc,String owner) {
    	 super(owner);
    	 this.brand = brand;
    	 this.cc = cc;
     }

	public String getBrand() {
		return brand;
	}

	public void setBrand(String brand) {
		this.brand = brand;
	}

	public int getCc() {
		return cc;
	}

	public void setCc(int cc) {
		this.cc = cc;
	}

	
     
    public void printDetails() {
    	System.out.println("-----------");
    	System.out.println("Brand: "+this.brand);
    	System.out.println("CC: "+this.cc);
    	System.out.println("Owner "+ super.getName());
    }
}
