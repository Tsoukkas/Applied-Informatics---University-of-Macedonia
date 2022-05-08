
public abstract class GeneralBook implements Comparable {
    private String title;
    private String author;
    private int code;
    
    public GeneralBook(String a,String b,int c) {
    	title=a;
    	author=b;
    	code=c;
    }
    
    public abstract boolean iseBook() ;
    
    public abstract void print();
    
    public int compareTo(Object arg0) {
		GeneralBook book = (GeneralBook) arg0;
		String string_code = String.valueOf(this.code);
		String string_code2 = String.valueOf(book.code);

		return string_code.compareTo(string_code2);
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public int getCode() {
		return code;
	}

	public void setCode(int code) {
		this.code = code;
	}
    
}
