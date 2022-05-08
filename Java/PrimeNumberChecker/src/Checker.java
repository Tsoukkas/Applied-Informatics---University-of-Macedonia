import java.util.Scanner;

public class Checker {
    private int x;
    private int i;
    private int flag;

public Checker() {
	flag=1;
    x=0;
}
 
 public void readfromkeyboard() {
	 
	 Scanner in = new Scanner(System.in);
    System.out.println("This proggram is checking if a number is Prime");
	 System.out.print("Number: ");
		x = in.nextInt();
 }
 
 public int Num_check(Checker x) {
	 while (i <= x / 2) {
	      // condition for nonprime number
	      if (x % i == 0) {
	        return flag = 1;
	      }
	      ++i;
	    } }
 
 public void printData() {
	 if(flag==0) {
		 System.out.println( x +"is a prime number.");
	 }
	 else {
		 System.out.println(x +"is not a prime number.");
	 }
 }
	

	 
 }
 

