import java.util.ArrayList;
import java.util.Collection;


public class Suspect {
  private String P_Number;
  private String name;
  private String codename;
  private String town;
  private ArrayList<String> Numbers = new ArrayList<String>();
  private ArrayList<Suspect> Ipoptoi = new ArrayList<Suspect>();
  private int count; 

 public Suspect(String onoma,String code,String city) {
	 
	 name=onoma;
	 codename=code;
	 town=city;
	 
 }

public String getName() {
	return this.name;
}
 

public String getCodeName() {
	return this.codename;
}




public void addNumber(String number) {
	
	Numbers.add(number);

}




public void addSinergates(Suspect sinergatis) {
	
  
	if (Ipoptoi.contains(sinergatis)) {
	    System.out.println("Account found");
	}
	else {
	Ipoptoi.add(sinergatis);
	this.count++;
}
	
}


public int getSize(){
	return count;
}

public boolean isConnectedTo(Suspect aSuspect) {
	
	for(Suspect sps: Ipoptoi) {
		String name2 = aSuspect.getName();
	if (sps.getName() == name2) {
	    return true;
	    
	}
	else {
	return false;	
}

	
	}
return false; }

       
public ArrayList<Suspect> getCommonPartners(Suspect aSuspect){
	ArrayList<Suspect> partners = new ArrayList<>(Ipoptoi);  
	 
	    
        
        partners.retainAll(aSuspect.getList());
       return partners; 
	
    	}

   

private ArrayList<Suspect> getList() {
	// TODO Auto-generated method stub
	return Ipoptoi;
}

public void printPartners(ArrayList ac) {
	ArrayList<Suspect> a = new ArrayList<Suspect>(ac);
	for(Suspect ac1:a) {
		System.out.println(ac1.getName() + "," + ac1.getCodeName());
	}
  }





}


