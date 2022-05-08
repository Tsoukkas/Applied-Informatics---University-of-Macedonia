
public abstract class  Container {
	private String code;
	private String destination;
	
public Container(String number,String dest) {
	this.code=number;
	this.destination=dest;
}
public abstract double CalculateCharge() ;

}
