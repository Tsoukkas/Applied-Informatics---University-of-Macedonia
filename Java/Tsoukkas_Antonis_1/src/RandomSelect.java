import java.lang.Math;
import java.util.Scanner;
public class RandomSelect  
{  
	public void choose() {
	Scanner in = new Scanner(System.in);
    System.out.println("Would you like to “hit” or “stay”?");
    while(true) {
	     Scanner in = new Scanner(System.in);
	     System.out.println("Would you like to “hit” or “stay”?");
	      int a , sum;
	      a =player.extra();
	      sum =a + player.athroisma();
	     String answer = in.nextLine();
	     if (answer.equals("hit")) {
	    	 
	    	 System.out.println("You drew a "+ a );
	    	 
	    	 System.out.println("Your total is " + sum  + ".");
	     }
	    	
	    	 
	     }
}
}
