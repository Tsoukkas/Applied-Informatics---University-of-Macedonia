import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
      ArrayList<String> food = new ArrayList<>();
      
      food.add("chicken");
      food.add("Beef Burger");
      food.add("chicken Burger");
      food.add("Pasta");
      food.add("Kebab");
      
      
      File file = new File("food.txt");
      
      try {
		FileWriter fw = new FileWriter(file);
		
		for(String f:food) {
			fw.write(f);
			fw.write(System.lineSeparator());
		}
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
      
    
	}

}
