import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		
//		Car c1 = new Car("Jaguar", 3200);
//		Car c2 = new Car("Mitsubishi", 1500);
//		Car c3 = new Car("Lexus", 1600);
//		
//		
//		
//       Emplooye e1 = new Emplooye("Andonis",c2);
//       Emplooye e2 = new Emplooye("Giorgos",c1);
//       Emplooye e3 = new Emplooye("Alexis",c3);
//       
//       ArrayList<Emplooye> emplooyes = new ArrayList<>();
//       emplooyes.add(e1);
//       emplooyes.add(e2);
//       emplooyes.add(e3);
//       
//       File file = new File("employees.ser");
//       
//       try {
//		FileOutputStream outStream = new FileOutputStream(file);
//		
//		ObjectOutputStream out = new ObjectOutputStream(outStream);
//		
//		out.writeObject(emplooyes);
//		out.close();
//		outStream.close();
//		
//	} catch (FileNotFoundException exc) {
//		// TODO Auto-generated catch block
//		exc.printStackTrace();
//	} catch (IOException exc) {
//		// TODO Auto-generated catch block
//		exc.printStackTrace();
//	}
//       
//       System.out.println("Serialazation has been performed");
//		
		ArrayList<Emplooye> emplooyes = null;
		
		File file = new File("employees.ser");
		
		try {
			FileInputStream inputStream = new FileInputStream(file);
			ObjectInputStream input = new ObjectInputStream(inputStream);
			
			emplooyes = (ArrayList<Emplooye>) input.readObject();
			
			input.close();
			inputStream.close();
			
			System.out.println("The following emplooyes have been retrived from the file");
			for(Emplooye e: emplooyes) {
				System.out.println("Emplooye: " +e.getName());
				System.out.println("own the car: ");
				e.getCar().printDetails();
			}
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (ClassNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
       
	}

}
//}
