package themata2021;

import java.util.ArrayList;

public class Fleet {
    private String city;
    private ArrayList<Taxi> taxies = new ArrayList<>();
    private int plithos;
    
    public Fleet(String a) {
     this.city = a;
     plithos = 0;
    }
    
    
    public String getCity() {
		return city;
	}
    
    public int returnPlithos() {
    	return plithos;
    }


	public void setCity(String city) {
		this.city = city;
	}


	public ArrayList<Taxi> getTaxies() {
		return taxies;
	}


	public void setTaxies(ArrayList<Taxi> taxies) {
		this.taxies = taxies;
	}


	public void storeTaxi(Taxi a) {
    	taxies.add(a);
    	plithos++;
    }
	
	public double returnAftonomia() {
		double sum=0;
		
		for(Taxi t: taxies) {
			sum += t.aftonomia();
		}
	
		return sum;	
	
	}    
}
