
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        ClassicBook a = new ClassicBook("House","Tsoukkas",1,300);
        ClassicBook b = new ClassicBook("Trees","Ioanou",2,100);
        ElectronicBook c = new ElectronicBook("Plants","Antreou",3,500);
        ElectronicBook d = new ElectronicBook("See","Kostantinu",4,600);
        
        BookStore bookstore = new BookStore();
        
        bookstore.addElement(a);
        bookstore.addElement(d);
        bookstore.addElement(c);
        bookstore.addElement(b);
        
        bookstore.searchElement(1);
        bookstore.searchElement(5);
        
        new PrintFrame(bookstore);
	}

}
