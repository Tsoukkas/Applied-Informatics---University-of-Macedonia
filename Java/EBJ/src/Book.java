
public class Book implements Measurable{
	private String title;
	 private String author;
	 private String editor;
	 private int year;
	 private String ISBN;
	 private int copies;
	 private String refNumber;
	 
	 public Book(String ti, String au, String ed, int y, String isbn, int c, String ref)
	 {
	 title = ti;
	 author = au;
	 editor = ed;
	 year = y;
	 ISBN = isbn;
	 copies = c;
	 refNumber = ref;
	 }

	 public void print()
	 {
	 System.out.println(title);
	 System.out.println("Author: " + author);
	 System.out.println("Editor: " + editor);
	 System.out.println("ISBN: " + ISBN);
	 System.out.println("Number of copies: " + copies + " Referene number: "
	 + refNumber);
	 }

	 
	 public void setRefNumber()
	 {
	 if (refNumber == "")
	 refNumber = author + year;
	 }

}
