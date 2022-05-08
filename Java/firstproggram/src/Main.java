
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Create a Variable is that is an stream to keyboard
		Scanner in = new Scanner(System.in);
		proion paputsi = new proion();
		boolean flag = true;
		while(flag) {
			proion myne = new proion();
			myne.readfromkeyboard();
			if(myne.sigkrisi(paputsi)) {
				paputsi = myne ;
			}
			 System.out.println("More data ? (1=YES,2=NO)");
			    int answer = in.nextInt();
			    if(answer !=1 ) {
			    	flag = false; }
			    in.hasNextLine();
			}
		paputsi.printData();

	}

}
