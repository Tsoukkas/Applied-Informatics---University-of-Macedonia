
public class Bulk extends Container {
   private double weight;
   
public  Bulk(String number,String dest,double varos) {
	super(number,dest);
	this.weight = varos;
}
public double CalculateCharge() {
	return 10*weight;
}
}
