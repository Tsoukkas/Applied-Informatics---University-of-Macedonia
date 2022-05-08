
public class ClassicBook extends GeneralBook {
    private int pages;
    
    public ClassicBook(String a,String b,int c,int d) {
    	super(a,b,c);
    	this.pages = d;
    }

	public int getPages() {
		return pages;
	}

	public void setPages(int pages) {
		this.pages = pages;
	}
	public String getInfo() {
		   String a = "";
		   a = "Book: "+this.getTitle() +" ,"+this.getSurname()+ " ,"+" ("+this.getNumber()+")"+", "+this.getPages();
		   return a;
	   }
	 public boolean isElectric() {
		   return false;
	   }
}
