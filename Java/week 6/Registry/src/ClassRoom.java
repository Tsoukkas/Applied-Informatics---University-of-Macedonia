
public class ClassRoom {
	private String location;
	private int capacity;
	
	public ClassRoom(String location, int capacity)
	{
		this.location = location;
		this.capacity = capacity;
	}

	public String getLocation() {
		return location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}	
}