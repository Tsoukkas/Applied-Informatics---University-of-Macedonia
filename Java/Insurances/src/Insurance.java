
public abstract class Insurance {
    private int number;
    private String surname;
    private int mouths;
    
    public Insurance(int a,String b,int c) {
    	this.number = a;
    	this.surname = b;
    	this.mouths = c;
    }

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public String getSurname() {
		return surname;
	}

	public void setSurname(String surname) {
		this.surname = surname;
	}

	public int getMouths() {
		return mouths;
	}

	public void setMouths(int mouths) {
		this.mouths = mouths;
	}
    
	public abstract int getcost();
	
	public String printDetails() {
		String a = null ;
	a =	"Code: "+ this.number+ "Surname:"+ this.getSurname() + "Mouths" + this.getMouths()+ "Cost:"+ this.getcost();
	return a;
	}
	
	public int CompareTo(Object other) {
		Insurance a = (Insurance) other;
		int b =this.number;
		int c = a.getNumber();
		int result = 0;
		if(b>c) {
			result = c;
		}
		else {
			result =b;
		}
		return result ; 
	}
}
