//libraries
import java.util.Scanner;

public class example {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
         int age;		
         String name;
         String mikroteros ="";
		int min = 0;
	   while(true) {
		 System.out.println("Name:");  
		   name=in.nextLine();
		System.out.println("Age");
		age=in.nextInt();
		if(age<0) {
			System.out.println("To y na ine pio megalo apo to 0");
		    age=in.nextInt();
		}
		//vrisko to min
		if(age<min) {
			min=age;
			mikroteros=name;
		}
		 System.out.println("Do you want to continue (0 : NO / 1 : YES)?");
		    int answer = in.nextInt();
		    //me tin epomeni entoli pame stin epomeni grami
		    in.nextLine();
		    
		    if(answer==0)break;
		
	}
	  System.out.println("tin mikroteri ilikia tin exi o "+ mikroteros+ "kai ine " + age + " xronon"); 
	  

}
}