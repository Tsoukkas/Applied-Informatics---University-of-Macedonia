import java.util.ArrayList;

public class Registry {
   ArrayList<Suspect> allSuspects = new ArrayList<>();
   ArrayList<Communication> communications = new ArrayList<>();
 
public void addCommunication(Communication aCommunication){
            communications.add(aCommunication);      
  }


   public void addSuspect(Suspect ac) {
	   allSuspects.add(ac);
   }
 
   public Suspect getSuspectWithMostPartners() {
	  Suspect tester=null;
	  int count =0;
       for(Suspect a1: allSuspects){
    	   if(count ==0) {
    		   tester = a1;
    	   }
         if(tester.getSize() < a1.getSize()){
            tester=a1;
            count++;
         }
       }
       return tester;
   }

   public PhoneCall getLongestPhoneCallBetween(String number1, String number2)
   {
	   PhoneCall test = null;
    PhoneCall max = new PhoneCall("00496955444444", "00478484777777", 15, 10, 2021, 127);
    for(Communication comm: communications ) {
    	if(comm instanceof PhoneCall && comm.getNumber1().equals(number1) && comm.getNumber2().equals(number2)) {
    		 test = (PhoneCall) comm;
    		 if(max.getCallDuration()<test.getCallDuration()) {
    			 max = test;
    		 }
    	}
    }
    return max; 
   }
   
   public ArrayList<SMS> getMessagesBetween(String number1, String number2)
   {
	   ArrayList<SMS> text = new ArrayList<>();
	   SMS test = null;
	   for(Communication comm: communications ) {
	    	if(comm instanceof SMS && comm.getNumber1().equals(number1) && comm.getNumber2().equals(number2)) {
	    		test = (SMS) comm;
	    		if(test.getText().contains("Bomb") || test.getText().contains("Attack") || test.getText().contains("Explosives") || test.getText().contains("Gun") ) {
	    			 text.add(test);
	    		 }
	    	}
	    }
	    return text;   
   }
   
}
