import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//        ArrayList<Integer> list = new ArrayList<>();
//        
//        list.add(1);
//        list.add(2);
//        list.add(3);
//        list.add(4);
//        list.add(5);
//        
//        File file = new File("numbers.txt");
//        try {
//			FileOutputStream out = new FileOutputStream(file);
//			ObjectOutputStream oout = new ObjectOutputStream(out);
//			
//			oout.writeObject(list);
//			oout.close();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//      
		ArrayList<Integer> a =null;
		
		File file = new File("numbers.txt");	
		
		
			FileInputStream fi;
			ObjectInputStream input = null;
				
					try {
						fi = new FileInputStream(file);
						input = new ObjectInputStream(fi);
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				
				
				try {
					a = (ArrayList<Integer>) input.readObject();
					
					for(Integer b:a) {
						System.out.println(b);
					}
				} catch (ClassNotFoundException | IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				// TODO Auto-generated catch block
	}}		
				
			
			
			
		
		
		
		
		
		
		
	



