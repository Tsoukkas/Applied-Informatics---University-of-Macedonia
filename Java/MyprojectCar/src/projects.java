import java.io.Serializable;

public class projects implements Serializable {
     private String name;
     private int cc;
     private int year;
     
     public projects(String name1,int cc1,int year1) {
    	 name=name1;
    	 cc=cc1;
    	 year=year1;
     }

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getCc() {
		return cc;
	}

	public void setCc(int cc) {
		this.cc = cc;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}
	
	public void tostring() {
		System.out.println("Name: "+name+"CC: " +cc );
	}
     
}
