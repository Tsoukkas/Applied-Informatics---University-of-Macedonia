import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;

public class Main2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> names = new ArrayList<>();
		
		names.add("George");
		names.add("Mary");
		names.add("Mary");
		names.add("Bob");
		names.add("George");
		
		for(String text : names) {
			System.out.println(text);
				}
	      Collection<String> noDups = new HashSet<String>(names);
	      
	      System.out.println("-------------");
	      for(String text: noDups) {
	    	  System.out.println(text);

	}

}
}
