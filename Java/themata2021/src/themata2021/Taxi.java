package themata2021;

public abstract class Taxi {
	private String ak;
	private String dn;
	
   public Taxi(String ak,String dn) {
	   this.ak =ak;
	   this.dn = dn ;
   }

public String getAk() {
	return ak;
}

public void setAk(String ak) {
	this.ak = ak;
}

public String getDn() {
	return dn;
}

public void setDn(String dn) {
	this.dn = dn;
}

public abstract double aftonomia();
   
}
