import java.util.ArrayList;

public class BookStore {
    ArrayList<GeneralBook> list = new ArrayList<>();
    
    public void addElement(GeneralBook a) {
    	list.add(a);
    }
    
    public void searchElement(int code) {
    	for(GeneralBook a:list) {
    		if(a.getNumber() == code) {
    			System.out.println("The book exists");
    			System.out.println(a);
    		}
    		else {
    			System.out.println("The book doesnt exist in the bookstore list");
    		}
    	}
    }

	public ArrayList<GeneralBook> getList() {
		return list;
	}

	public void setList(ArrayList<GeneralBook> list) {
		this.list = list;
	}
    
}
