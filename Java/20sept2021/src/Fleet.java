import java.util.ArrayList;

public class Fleet {
    private String name;
	ArrayList<Taxi> stolos = new ArrayList<Taxi>();
   
   public Fleet(String a) {
	   this.name = a;
   }
   
   public String getName() {
	return name;
}

   public double Aftonomies() {
	   double sum = 0;
	   for(Taxi a:stolos) {
		   sum+=a.returnAftonomia();
	   }
	   return sum;
   }
public void setName(String name) {
	this.name = name;
}

public void storeTaxi(Taxi a) {
	   stolos.add(a);
   }

public ArrayList<Taxi> getStolos() {
	return stolos;
}

public void setStolos(ArrayList<Taxi> stolos) {
	this.stolos = stolos;
}
   
}
