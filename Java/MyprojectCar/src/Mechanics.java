import java.io.Serializable;

public class Mechanics implements Serializable {
     private String name;
     private int price;
     private projects car;
     
    public Mechanics(String name1,int price1,projects car1) {
    	name=name1;
    	price1=price;
    	car=car1;
    }

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getPrice() {
		return price;
	}

	public void setPrice(int price) {
		this.price = price;
	}

	public projects getCar() {
		return car;
	}

	public void setCar(projects car) {
		this.car = car;
	}
    
}
