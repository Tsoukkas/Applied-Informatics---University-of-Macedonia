import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       ArrayList<String> hobbies = new ArrayList<>();
       
       hobbies.add("golf");
       hobbies.add("football");
       hobbies.add("chess");
       hobbies.add("Maths");
       
      
	File file = new File("hobbies.txt");
       
	try {
		FileWriter writer = new FileWriter(file);
	     for(String m:hobbies) {
	    	 writer.write(m);
	    	 writer.write(System.lineSeparator());
	     }
	     writer.close();
	}catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
       new GUI();
		
	}

}
