
public class PhoneCall extends Communication{
	
	private int seconds;
	
	
	public PhoneCall(String num12, String num23, int day, int month, int year, int seconds){
		super(num12,num23, day, month, year);
		this.seconds = seconds;
	}
	
	public void printInfo() {
		System.out.println("This phone call has the following info");
		super.printInfo();
		System.out.println("Duration: " +seconds);
	}
	
	public int getCallDuration()
		{
		return seconds;
		}
}