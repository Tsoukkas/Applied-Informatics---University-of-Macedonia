
public class AntigenTest extends DiagnosticTest {
     private int time;
     
     public AntigenTest(String a,String b,boolean c,String d,int e) {
    	 super(a,b,c,d);
    	 this.time = e ;
     }

	public int getTime() {
		return time;
	}

	public void setTime(int time) {
		this.time = time;
	}
	public String writer() {
		String a =null;
		a = "Antigen Test, date:"+ this.getDate() + "Result: "+ this.isResult()+" Type: "+this.getType()+ "Accuracy: "+ this.getTime();
		return a ;
	}
}
