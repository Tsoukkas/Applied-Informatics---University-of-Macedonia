import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class BookStore {
    private ArrayList<GeneralBook> books = new ArrayList<>();

    public void addElement(GeneralBook a) {
    	books.add(a); 	
    }
    
    
    public ArrayList<GeneralBook> getBooks() {
		return books;
	}


	public void setBooks(ArrayList<GeneralBook> books) {
		this.books = books;
	}


	public void printDetails() {
    	for(GeneralBook b:books) {
    		b.print();
    	}
    }
    
	public void searchElement(int code) {
		
		GeneralBook selectedBook = null;
		
		for(GeneralBook book: books) {
			if(book.getCode() == code){
				selectedBook = book;
				
			}
			
		}
		if(selectedBook == null) {
			System.out.println("Book isn't listed");
		}else {
			selectedBook.print();
			
		}
		
	}

}
