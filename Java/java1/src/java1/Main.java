package java1;

import java.awt.print.Book;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {

	//public static void main(String[] args) {
		// TODO Auto-generated method stub
    /*   HashMap<String, String> map = new HashMap<>();
	
       map.put("Mary", "2310 322548");
       map.put("John", "2310 322248");
       map.put("Bob", "2310 322348");
       map.put("George", "2310 322448");
       
       System.out.println("Bob's phone is: " + map.get("Bob"));
       
       for(String name: map.keySet()) {
    	   String value = map.get(name);
    	   System.out.println(name + ":" + value);*/
	public static void main(String[] args) {
		
		ArrayList<Book> johnsBooks = new ArrayList<>();
		johnsBooks.add(new Book("Moby Dick"));
		johnsBooks.add(new Book("The Catcher in the Rye"));
		
		ArrayList<Book> marysBooks = new ArrayList<>();
		johnsBooks.add(new Book("Moby Dick"));
		johnsBooks.add(new Book("The Catcher in the Rye"));
		
		HashMap<String, ArrayList<Book>> library = new HashMap<>();
		
		library.put("John", johnsBooks);
		library.put("Mary", marysBooks);
		//key set ine to sinolo ton onomaton
		for(String name: library.keySet()) {
			System.out.println(name + "has the following books");
			ArrayList<Book> loanedBooks = library.get(name);
			fro(Book book: loanedBooks){
				System.out.println(book.getTitle());
			}
		}
		
		
class Book {
	private String title;
	public Book(String text) {
		title = text ;
	}
	
	public String getTitle() {
		return title;
	}
		
       }
	}

}
