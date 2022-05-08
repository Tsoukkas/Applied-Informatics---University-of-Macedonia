
public abstract class Taxi {
    private String number;
    private String driver;
    
    public Taxi(String a,String b) {
    	this.number = a;
    	this.driver = b;
    }

	public String getNumber() {
		return number;
	}

	public void setNumber(String number) {
		this.number = number;
	}

	public String getDriver() {
		return driver;
	}

	public void setDriver(String driver) {
		this.driver = driver;
	}
    
	public abstract double returnAftonomia() ;
		
}
