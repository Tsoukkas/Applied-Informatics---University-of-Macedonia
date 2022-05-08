
public class SMS extends Communication {
	 private String text;
	    public SMS(String number1,String number2,int number3,int number4,int number5,String number6){
	        super(number1,number2,number3,number4,number5);
	        this.text=number6;
	    }
	   public void printInfo(){
	       System.out.println("This SMS has the following info");
	       super.printInfo();
	       System.out.println("Text: "+ text);
	   }
	   public String getText() {
		   return text;
	   }
	   
	   
	}

