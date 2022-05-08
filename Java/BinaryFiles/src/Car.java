import java.io.Serializable;

public class Car implements Serializable {
   private String Brand;
   private int cc;
   
   public Car(String Brand,int cc) {
	   this.Brand = Brand;
	   this.cc= cc;
	   }
   
   public void printDetails() {
	   System.out.println(Brand + ":" + cc);
   }
}
