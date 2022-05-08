package themata2021;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList<Fleet> stoloi = new ArrayList<>();
       
	   Fleet a = new Fleet("Iraklio");
       Fleet b = new Fleet("Rethimno");
       
       GasolineTaxi c = new GasolineTaxi("121344","George",70,6.0);
       GasolineTaxi d = new GasolineTaxi("13224","AndonisTsoukkas",80,7.0);
       
       ElectricalTaxi e = new ElectricalTaxi("143554","Lenos",7);
       ElectricalTaxi z = new ElectricalTaxi("1212134","Iasonas",78);
       
       a.storeTaxi(c);
       a.storeTaxi(e);
       
       b.storeTaxi(d);
       b.storeTaxi(z);
       
       stoloi.add(b);
       stoloi.add(a);
       
       new GUI(stoloi);
	}

}
