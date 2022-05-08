//Name of libraries to import(include C)
import java.util.Scanner; //ipefthini gia na grafume apo to pliktrologio
//oles oi klasis public gia na mporun na tis vlepun oi ales 
public class MainProducts {
//ektos apo tis methodus dilono mono metavlites,oxi kodika
//	declare variables


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Create a Variable is that is an stream to keyboard
		Scanner in = new Scanner(System.in);
		//den ine sintaktiko na vazume edo tis metavlites
		//Variables used for describing the current product
    String pr_name;
   double pr_price;
 double pr_score;
    
    //Variables used for the best product
    String best_pr_name = "";
    double best_pr_score = -1;
    
  
    //epanalipsi
    while(true) {
    System.out.print("Please enter product name: ");
    //Aska input in the next line
    //System.out.println("Please enter product name: ");
    pr_name = in.nextLine();
    
    System.out.print("Please enter product price: ");
    pr_price = in.nextDouble();
     if(pr_price == 0) {
    	 System.out.print("Please enter product price: ");
    	    pr_price = in.nextDouble();
     }
    
    System.out.print("Please enter product score: ");
    pr_score = in.nextDouble();
    
    if((pr_score / pr_price) > best_pr_score) {
    	best_pr_score=(pr_score / pr_price);
    	best_pr_name=pr_name;
    }
    
    
    System.out.println("Do you want to continue (0 : NO / 1 : YES)?");
    int answer = in.nextInt();
    //me tin epomeni entoli pame stin epomeni grami
    in.nextLine();
    
    		
    if (answer == 0)break;
   
    
    
    }
   System.out.println("The best product is: "+ best_pr_name);
    
    
    
  }

}

//kaki praxtiki gia isagogi klasewn
//den grafo edo kodika sintaktiko lathos grafw mono sto anigma kai klisimo tis klasis