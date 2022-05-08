import java.util.Collection;
import java.util.HashSet;

public class Main3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Collection<String> set1 = new HashSet<>();
		
		set1.add("A");
		set1.add("B");
		set1.add("C");
		set1.add("D");
		//set1.add("D");
		//set1.add("E");
		//set1.add("F");
		
		Collection<String> set2 = new HashSet<>();
		
		set2.add("D");
		set2.add("E");
		set2.add("F");
		//find if s2 is a suspect of s1
		//if the set1&set2 have the same items
		if(set1.containsAll(set2)) {
			System.out.println("set2 is a subset of s1");
			 }
		
		//set1.addAll(set2);
		//String label;
		//System.out.println("------------");
		//label = "Union of two set";
		//printSetElements(set1, label);
		
		set1.retainAll(set2);
		printSetElements(set1,"Intersection");
		set1.removeAll(set2);
		printSetElements(set1,"Set Difference");
		
	}

	private static void printSetElements(Collection<String> set1, String label) {
		System.out.println("---------"+ label +"--------");
		for(String s: set1) {
			System.out.println(s + ", ");
			}
	System.out.println("--------------------"); 
		
	}

}
