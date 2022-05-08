import java.util.Scanner;

public class proion {
    
	private String marka;
	private double timi;
	private double size;
	
	


public proion() {
	marka = "";
	timi = 0.0;
	size = 0.0;
}

public void readfromkeyboard() {
	Scanner in = new Scanner(System.in);
	System.out.println("Dose marka paputsion: ");
    marka=in.nextLine();
    System.out.println("Dose timi: ");
    timi=in.nextDouble();
    System.out.println("Dose size: ");
    size=in.nextDouble();
    in.hasNextLine();
	
}

public boolean sigkrisi(proion paputsi) {
	return (paputsi.timi>timi);
}

public void printData() {
	System.out.println("To paputsi: "+ marka); 
    System.out.println( "einai to pio akrivo");
}

}