
public class DiagnosticTest extends Test {
   private boolean result;
   private String type;
   
   public DiagnosticTest(String a,String b,boolean c,String d) {
	   super(a,b);
	   this.result = c;
	   this.type = d ;
   }

public boolean isResult() {
	return result;
}

public void setResult(boolean result) {
	this.result = result;
}

public String getType() {
	return type;
}

public void setType(String type) {
	this.type = type;
}

public String writer() { 
	String a =null;
	a = "Diagnostic Test, date:"+ this.getDate() + "Result: "+ this.isResult()+" Type: "+this.getType();
	return a ;
}
}
