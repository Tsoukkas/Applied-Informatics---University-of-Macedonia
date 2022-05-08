import java.io.Serializable;

public class Emplooye implements Serializable {
	private String name;
	private Car car;
	
	public Emplooye(String name,Car aCar) {
		 this.name = name;
		 car = aCar ;
	}
	
	public String getName() {
		return name;
	}

	public Car getCar() {
		return car;
	}
	
}
