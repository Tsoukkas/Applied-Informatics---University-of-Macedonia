
public abstract class GeneralBook {
    private String title;
    private String surname;
    private int number;
    
    public GeneralBook(String a,String b,int c) {
    	this.title = a;
    	this.surname = b;
    	this.number = c;
    }

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getSurname() {
		return surname;
	}

	public void setSurname(String surname) {
		this.surname = surname;
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}
	public abstract String getInfo() ;
	
	public int CompareTo(Object other) {
		GeneralBook a = (GeneralBook)other;
		if(this.number>a.number) {
			return 1;
		}
		else if(this.number <a.number) {
			return -1;
		}
		else {
			return 0;
		}
	}
	 public abstract boolean isElectric() ;
		   
    
}
