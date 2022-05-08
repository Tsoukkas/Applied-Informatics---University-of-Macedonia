
public class Soldier {
	
	private String id;
	private static int counter = 0;
	
	public Soldier(String anID) {
		id = anID;
		counter++;
	}
	
	public static int getCounter() {
		return counter;
	}

}