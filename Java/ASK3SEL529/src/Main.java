import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       ArrayList<Vehicle> v = new ArrayList<>();
       v.add(new Vehicle("nissan",26,"George"));
       v.add(new Vehicle("swift",26,"Sotiris"));
       v.add(new Vehicle("bmw",26,"Chris"));
       v.add(new Vehicle("honda",26,"Andonis"));
       v.add(new Vehicle("lancer",26,"Andreas"));
       v.add(new Vehicle("saxo",26,"Josh"));
       v.add(new Vehicle("Evo",20,"Panagiotis"));
       
      GUI gui = new GUI(v);
       
	}

}
