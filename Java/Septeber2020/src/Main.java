
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
      Book a = new Book("ABCD","Tsoukkas",1,400);
      
      Book b = new Book("ABCDE","Andreas",2,450);
     
      
      eBook c = new eBook("ABCDEF","Stefanos",3,500.1);
      eBook d = new eBook("ABCDEFG","Panagiotis",4,550.2);
     
      BookStore store = new BookStore();
      
      store.addElement(a);
      store.addElement(b);
      store.addElement(c);
      store.addElement(d);
      
      store.searchElement(1);
      store.searchElement(8);
      
      
     new GUI(store.getBooks());
	}

}
