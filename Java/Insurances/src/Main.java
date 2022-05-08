import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       ArrayList<Insurance> list = new ArrayList<>();
       
       CraInsurance a = new CraInsurance(1,"Tsoukkas",7,20);
       CraInsurance b = new CraInsurance(2,"Georgiou",8,21);
       
       HouseInsurance c = new HouseInsurance(3,"Ioanou",9,22);
       HouseInsurance d = new HouseInsurance(4,"Antreou",10,23);
       
       list.add(a);
       list.add(b);
       list.add(c);
       list.add(d);
       
       new GUI(list);
	}

}
