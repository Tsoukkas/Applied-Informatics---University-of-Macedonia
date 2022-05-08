import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		Checker flag = new Checker();
		Checker x = new Checker();
		x.readfromkeyboard();
		Num_check(x);
		x.printData();
		

	}

	
}
