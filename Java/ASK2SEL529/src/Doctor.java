
public class Doctor extends Person {
     private String idikotita;
     private double xreosi;
     
     public Doctor(String name,String idikotita,double amount) {
    	 super(name);
    	 this.idikotita = idikotita;
    	 this.xreosi =amount;
     }

	public String getIdikotita() {
		return idikotita;
	}

	public void setIdikotita(String idikotita) {
		this.idikotita = idikotita;
	}

	public double getXreosi() {
		return xreosi;
	}

	public void setXreosi(double xreosi) {
		this.xreosi = xreosi;
	}
	
	public double isodima(double a) {
		double sum =0 ;
		
		sum = a*xreosi;
		
		return sum;
		
	}
	
	public void printDetails() {
		System.out.println("--------");
		System.out.println("Name: "+super.getName());
		System.out.println("Idikotita: " + idikotita + "Xreosi :" + xreosi);
	}
     
    public boolean equals(Object other) {
    	Doctor a = new Doctor("giorgos","pathologos" ,20);
    	a = (Doctor)other;
    	if(this.name == a.name && this.idikotita == a.idikotita) {
    		return true;
    	}
    	else return false;
    }
}
