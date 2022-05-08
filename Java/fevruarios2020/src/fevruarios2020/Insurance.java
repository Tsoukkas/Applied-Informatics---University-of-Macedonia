package fevruarios2020;

public abstract class Insurance {
   private int code;
   private String surname;
   private int diarkia;
   
   public Insurance(int a,String b,int c) {
	   this.code=a;
	   this.surname=b;
	   this.diarkia=c;
   }

public int getCode() {
	return code;
}

public void setCode(int code) {
	this.code = code;
}

public String getSurname() {
	return surname;
}

public void setSurname(String surname) {
	this.surname = surname;
}

public int getDiarkia() {
	return diarkia;
}

public void setDiarkia(int diarkia) {
	this.diarkia = diarkia;
}

public abstract double asfalia() ;

public abstract String print();


public int compareTo(Object arg0) {
		Insurance a = (Insurance) arg0;
		String string_code = String.valueOf(this.code);
		String string_code2 = String.valueOf(a.code);

		return string_code.compareTo(string_code2);
	}
}

