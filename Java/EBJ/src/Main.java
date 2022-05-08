import java.util.ArrayList;

public class Main  {

	public static void main(String[] args) {
       ArrayList<Measurable> Books = new ArrayList<>();
       ArrayList<Journal> Journals = new ArrayList<>();
       new GUI();
       GUI.main(Books);
       for(Measurable b:Books) {
    	   b.print();
       }
       System.out.println(Books.size());
	}

}
