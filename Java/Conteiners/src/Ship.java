import java.util.ArrayList;

public class Ship {
  private String name;
  private int capacity;
  private ArrayList<Container> containers = new ArrayList<>();
  
public Ship(String name1,int capacity1) {
	this.name=name1;
	this.capacity=capacity1;
}

public String getName() {
	return name;
}

public void addContainer(Container a1) {
	if(this.capacity > containers.size()) {
	containers.add(a1);
	System.out.println("The container has been loaded");
	}
	else {
		System.out.println("Sorry the Ship is full!");
	}
}


public double  calcTotalCharge() {
	double sum = 0;
	for(Container container: containers) {
		sum+= container.CalculateCharge();
	}
	return sum;
}

}
