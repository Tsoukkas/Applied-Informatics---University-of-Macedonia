package productwithclasses;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
			
			
			//Create a Variable is that is an stream to keyboard
			Scanner in = new Scanner(System.in);
			product bestPr = new product();
			
	
	  
	    //epanalipsi
	    while(true) {
	    product currproduct = new product();
	    currproduct.readFromKeyboard();
	    if(currproduct.isBetter(bestPr)) {
	    	bestPr = currproduct;
	    }
	    System.out.println("More data ? (1=YES,2=NO)");
	    int answer = in.nextInt();
	    if(answer !=1)
	    	break;
	    in.hasNextLine();
	}
   bestPr.printData();
}

	
}
