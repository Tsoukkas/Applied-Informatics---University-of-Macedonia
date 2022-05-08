package fevruarios2020;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
      ArrayList<Insurance> list = new ArrayList<>();
      
      CarInsurance a = new CarInsurance(1,"Tsoukkas",7,18);
      CarInsurance b = new CarInsurance(2,"Georgiou",9,28);
      
      HouseInsurance c = new HouseInsurance(3,"Andreou",7,180);
      HouseInsurance d = new HouseInsurance(4,"Antoniou",7,360);
      
      list.add(d);
      list.add(c);
      list.add(b);
      list.add(a);
      
      new GUI(list);
	}

}
