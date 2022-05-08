
public class Journal implements Measurable{
	private String title;
	 private String editor;
	 private int year;
	 private int volume;
	 private int issue;
	 private String ISBN;
	 private int copies;
	 private String refNumber;
	 public Journal(String ti, String ed, int y, int v, int i, String isbn, int c,
	 String ref)
	 {
	 title = ti;
	 editor = ed;
	 year = y;
	 volume = v;
	 issue = i;
	 ISBN = isbn;
	 copies = c;
	 refNumber = ref;
	 }

	 public void print()
	 {
	 System.out.println(title);
	 System.out.println("Editor: " + editor);
	 System.out.println("Volume: " + volume + " Issue: " + issue);
	 System.out.println("ISBN: " + ISBN);
	 System.out.println("Number of copies: " + copies + " Referene number: "
	 + refNumber);
	 }

	 public void setRefNumber()
	 {
	 if (refNumber == "")
	 refNumber = title + volume + issue;
	 } 
}
