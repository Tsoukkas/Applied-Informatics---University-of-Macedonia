
public class Refrigerator extends Container {
    private double power;
    
public Refrigerator(String code,String dest,double power1) {
	super(code,dest);
	this.power=power1;
}
public double CalculateCharge() {
	return 2000*power;
}
}
