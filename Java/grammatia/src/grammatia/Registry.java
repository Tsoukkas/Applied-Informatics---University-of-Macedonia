package grammatia;

import java.util.ArrayList;
import java.util.Scanner;

public class Registry {
  private String name;
  private ArrayList<Course> courses  ; 
  courses = new ArrayList<Course>();
	 
public Registry(String text) {
	name = text ; 
}

public void addcourse(Course c) {
	courses.add(c);
}
public void printlessons() {
	int index = 0 ;
	System.out.println("Lessons");
	while(index <= courses.size()) {
		System.out.println(name);
		System.out.println("aithusa didaskalias: "+ courses.get() );
		index++;
	}
}


	 
}
