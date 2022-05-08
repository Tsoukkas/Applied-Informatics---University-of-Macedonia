import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class DiagnosticCenter {
     ArrayList<Test> list = new ArrayList<>();
     
     public void addTest(Test a) {
    	 list.add(a);
     }

	public ArrayList<Test> getList() {
		return list;
	}

	public void setList(ArrayList<Test> list) {
		this.list = list;
	}
     
	public void checkForTest(ArrayList<String> a){
		File file = new File("test.txt");
		try {
			FileWriter filewriter = new FileWriter(file);
			for(String item:a) {
				for(Test thing:list) {
					if(thing.getSurname().equals(item)) {
						filewriter.write(item+" has performed a test with the following information:");
						filewriter.write(thing.writer());
					}
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
