import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		Ship ship1 = new Ship("Cobacabana", 100);
		Ship ship2 = new Ship("Hercules", 250);
		Ship ship3 = new Ship("Tinos", 120);
		Ship ship4 = new Ship("Kriti", 200);
		Ship ship5 = new Ship("SuperStar", 340);
		Ship ship6 = new Ship("Zeus", 280);
		
		ArrayList<Ship> ships = new ArrayList<>();
		ships.add(ship1);
		ships.add(ship2);
		ships.add(ship3);
		ships.add(ship4);
		ships.add(ship5);
		ships.add(ship6);
		
		new ContainerFrame(ships);
	}

}
