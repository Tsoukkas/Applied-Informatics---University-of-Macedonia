import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       Fleet stolos = new Fleet("Iraklio");
       Fleet stolos2 = new Fleet("Rethimno");
       
       ElectricalTaxi a = new ElectricalTaxi("1111","Atreas",4);
       ElectricalTaxi b = new ElectricalTaxi("2222","Giorgos",5);
       
       GasolineTaxi c = new GasolineTaxi("3333","Antonis Tsoukkas",50,6);
       GasolineTaxi d = new GasolineTaxi("3333","Giannis",60,7);
       
       stolos.storeTaxi(a);
       stolos.storeTaxi(c);
       
       stolos2.storeTaxi(b);
       stolos2.storeTaxi(d);
       
       ArrayList<Fleet> stoloi = new ArrayList<>();
       stoloi.add(stolos2);
       stoloi.add(stolos);
       
       new GUI(stoloi);
	}

}
