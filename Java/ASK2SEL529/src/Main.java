
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       Patient p1 = new Patient("Andonis","21139");
       Patient p2 = new Patient("Antreas","31273");
       
       Doctor d1 = new Doctor("Antreas","Ktiniatros",30);
       Doctor d2 = new Doctor("George","Ginekologos",40);
       
       Billing b1 = new Billing(p1,d1);
       Billing b2 = new Billing(p2,d2);
       
       b1.printDetails(3);
	}

}
