import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       ArrayList<String> names = new ArrayList<>();
       
       names.add("George");
       names.add("Giannis");
       names.add("Andonis");
       names.add("Anna");
       names.add("Alexis");
       names.add("Christos");
       
       File file = new File("names.txt");
       
       try {
		FileWriter fileWriter = new FileWriter(file);
		
		for(String name: names) {
			fileWriter.write(name);
			fileWriter.write(System.lineSeparator());
		}
		
		fileWriter.close();
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
       new GUI();
       
}

}
