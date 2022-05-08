import java.util.Random;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       System.out.println("Welcome to the simplified blackjack game!");
      Card player = new Card();
     Card dealer = new Card();
     
     player.printdata();
     player.total();
     
     dealer.showing();
     
     int a=0 , sum = player.athroisma();
     boolean death ;
     while(true) {
	     Scanner in = new Scanner(System.in);
	     System.out.println("Would you like to “hit” or “stay”?");
	     
	      
	     String answer = in.nextLine();
	     a =0;
	     if (answer.equals("hit")) {
	    	a= player.extra() ;
	    	 System.out.println("You drew a "+ a );
	    	 sum +=a ;
	    	 player.teliko(sum);
	     }
		      
	    	 
	    	 
	       death = player.sumchecking(sum);
	    	 if(death == true) {
	    		 System.out.println("DEALER WINS!");
	    		 System.exit(0);
	    	 }
	    	 
	    	 
	     
	     if(answer.equals("stay")) {
	    	 System.out.println("OK, dealer is playing.") ;
	    	 dealer.hidden();
	    	 dealer.d_total();
	    	 break;
	     }
	     
	    	
     }
     int b,sum1=dealer.athroisma() ;
     while(true) {
     int x ;
    x= 1 + (int)(Math.random() * 2);
     
         
     
	if(x == 2) {
		 System.out.println("Dealer chooses to hit");
		  b =dealer.extra();
    	 System.out.println("He draws a "+ b );
    	  sum1 +=b  ;
    	 dealer.teliko(sum1);
    	 boolean death1 ;
       death1 = dealer.sumchecking(sum1);
    	 if(death1 == true) {
    		 System.out.println("PLAYER WINS!");
    		 System.exit(0);
    	 }
	 }
	 else if(x == 1 ) {
		System.out.println("Dealer stays.");
		dealer.dealertotal();
		player.total();
		break;
	 }
     }
     if(dealer.athroisma() > player.athroisma()) {
    	 System.out.println("DEALER WINS!");
     }
     else {
    	 System.out.println("PLAYER WINS!");
     }
  
}
}