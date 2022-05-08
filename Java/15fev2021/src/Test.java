
public abstract class Test {
  private String surname;
  private String date;
  
  public Test(String a,String b) {
	  this.surname = a;
	  this.date = b;
  }

public String getSurname() {
	return surname;
}

public void setSurname(String surname) {
	this.surname = surname;
}

public String getDate() {
	return date;
}

public void setDate(String date) {
	this.date = date;
}
 
public abstract String writer() ;

}
