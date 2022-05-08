
public class Book extends GeneralBook {
   
   private int page_number;
   
public Book(String a,String b,int code,int c) {
	  super(a,b,code);
	   this.page_number = c;
}

public boolean iseBook() {
	return false;
}

public int getPage_number() {
	return page_number;
}

public void setPage_number(int page_number) {
	this.page_number = page_number;
}


public void print() {
	//eBook: τίτλος, επώνυμο, (κωδικός), μέγεθος
	System.out.println(super.getTitle() + ", "+ this.getAuthor()+ ", ("+ this.getCode() +"), "+ this.getPage_number());
}

   
}
