import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//        projects p1 = new projects("honda",1800,1998);
//        projects p2 = new projects("Skylline",2600,1999);
//        
//        Mechanics m1 = new Mechanics("Andreas",20000,p1);
//        Mechanics m2 = new Mechanics("Giorgos",90000,p2);
//        
//        ArrayList<Mechanics> m = new ArrayList<>();
//        
//        m.add(m2);
//        m.add(m1);
//        
//        File file = new File("Mechanics");
//        
//        try {
//        	FileOutputStream outStream = new FileOutputStream(file);
//    		
//    		ObjectOutputStream out = new ObjectOutputStream(outStream);
//    		
//    		out.writeObject(m);
//    		out.close();
//    		outStream.close();
//        }catch (FileNotFoundException exc) {
//    		// TODO Auto-generated catch block
//    		exc.printStackTrace();
//    	} catch (IOException exc) {
//    		// TODO Auto-generated catch block
//    		exc.printStackTrace();
//    	}
//        System.out.println("Serialazation has been performed");
ArrayList<Mechanics> m = null;
		
		File file = new File("Mechanics");
		
		try {
			FileInputStream inputStream = new FileInputStream(file);
			ObjectInputStream input = new ObjectInputStream(inputStream);
			
			m = (ArrayList<Mechanics>) input.readObject();
			
			input.close();
			inputStream.close();
			
			System.out.println("The following projects have been retrived from the file");
			for(Mechanics e: m) {
				System.out.println("Mechanic: " +e.getName());
				System.out.println("will project the car: ");
				e.getCar().tostring();
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
