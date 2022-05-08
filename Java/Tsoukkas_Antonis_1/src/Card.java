import java.util.Random;
public class Card {
    private int random1,random2 ;
    private static  final int   min = 2;
    private static final int max = 11; 
    
public Card() {
	random1 = Card.getRandomNumberInRange(min, max);
	random2 = Card.getRandomNumberInRange(min, max);
}

private static int getRandomNumberInRange(int min, int max) {

	if (min >= max) {
		throw new IllegalArgumentException("max must be greater than min");
	}

	Random r = new Random();
	return r.nextInt((11 - 2) + 1) + 2;
}
public int athroisma() {
	return random1 + random2;
}
public void printdata() {
	System.out.println("You get a "+ random1 +" and "+random2+".");
}
public void total() {
	System.out.println("Your total is "+ (random1+random2) +".");
}
public void d_total() {
	System.out.println("His total is "+ (random1+random2) +".");
}

public void showing() {
	System.out.println("The dealer has a "+ random1 + " showing, and a hidden card.");
}
public void hidden() {
	System.out.println("His hidden card was " + random2 + ".");
}
public int extra() {
    int random_extra;
    return random_extra = getRandomNumberInRange(min,max);
}

public boolean sumchecking(int sum) {
	if(sum > 21) {
		
		return true;
	}
	else {
		return false;
	}
}

public void dealertotal() {
  System.out.println("Dealer total is " +  athroisma() + ".");	
}

public void teliko(int sum) {
	 System.out.println("Your total is " + sum  + ".");
}
}
