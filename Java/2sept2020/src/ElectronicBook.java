
public class ElectronicBook extends GeneralBook {
   private double mb;
   
   public ElectronicBook(String a,String b,int c,double d) {
	   super(a,b,c);
	   this.mb = d;
   }

   public double getMb() {
	return mb;
}

   public void setMb(double mb) {
	this.mb = mb;
}
   public String getInfo() {
	   String a = "";
	   a = "eBook: "+this.getTitle() +" ,"+this.getSurname()+ " ,"+" ("+this.getNumber()+")"+", "+this.getMb();
	   return a;
   }
   public boolean isElectric() {
	   return true;
   }
   
}
