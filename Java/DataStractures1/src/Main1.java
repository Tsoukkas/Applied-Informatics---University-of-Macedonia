import java.util.HashSet;
import java.util.Iterator;

public class Main1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashSet<String> set = new HashSet();
		set.add("John");
		set.add("Nick");
		set.add("Mary");
		set.add("John");
		
		Iterator i =set.iterator();
		while(i.hasNext()) {
			String text = (String) i.next();
			
			System.out.println(text);
	}

}
}
