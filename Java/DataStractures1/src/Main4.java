import java.util.Iterator;
import java.util.TreeSet;

public class Main4 {
	public static void main(String[] args) {
		TreeSet<String> treeSet = new TreeSet<>();
		
		treeSet.add("Olga");
		treeSet.add("Nikos");
		treeSet.add("Babis");
		treeSet.add("Takis");
		
		Iterator<String> iter = treeSet.iterator();
		
		while(iter.hasNext()) {
			System.out.println(iter.next());	
		
}
}
}
