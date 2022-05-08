package productwithclasses;

import java.util.Scanner;

public class product {
	
	
	//Variables used for describing the current product
private String name;
private double price;
private int score;

//vazi kapies statheres me tin enia oti tha tus thesi ala meta apo to pliktrologio
  public  product () {
	name = "";
	score = 0;
	price = 0.0;
			
 }

 public void printData() {
	 System.out.println(name + ", with value: "+ score + "is the best product");
 }
  
  
  
public boolean isBetter(product bestPr) {
	return ((score / price) > (bestPr.score / bestPr.price));
}
//diavasma apo to keyboard
public void readFromKeyboard() {
	//aparetiti opos dipote i scanner
	Scanner in = new Scanner(System.in);
	System.out.print("Name: ");
	name = in.nextLine();
	System.out.print("Price: ");
	price = in.nextDouble();
	System.out.print("Score: ");
	price = in.nextInt();
	in.hasNextLine();
	in.close();
	
}

  
}
