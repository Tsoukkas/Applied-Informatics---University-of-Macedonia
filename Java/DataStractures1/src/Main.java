import java.util.Iterator;
import java.util.LinkedList;

public class Main {
	 public static void main(String args[]) {
	LinkedList<Integer> list = new LinkedList<>();
	
	list.add(5);
	list.add(7);
	list.add(15);
	list.add(11);
	
	
	for(Integer i: list) {
		System.out.println(i.toString());
	}
	Iterator<Integer> itr =  list.iterator();
	//print the first item
	System.out.println(itr.next());
	
   
	

}
}