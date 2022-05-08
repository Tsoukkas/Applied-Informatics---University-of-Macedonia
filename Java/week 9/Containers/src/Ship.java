import java.util.ArrayList;

public class Ship {
	
	private String name;
	private int capacity;
	private ArrayList<Container> containers = new ArrayList<>();
	
	public String getName() {
		return name;
	}
	
	public Ship(String name, int capacity) {
		this.name = name;
		this.capacity = capacity;
	}
	
	public void addContainer(Container aContainer) {
		if(containers.size() < capacity) {
			containers.add(aContainer);
			System.out.println("The container has been loaded");
		}
		else
			System.out.println("Sorry the ship is full");
	}
	
	public double calcTotalCharge() {
		double sum = 0;
		for(Container container: containers) {
			sum += container.calculateCharge();
		}
		return sum;
	}
	

}
