package grammatia;

import java.util.Scanner;


public class Student {
   private String name;
   private String id;
   private Course course;
   
public Student(String text1,String text2) {
	name = text1;
	id = text2;
}

public void setanId(String text) {
	id = text;
}

public String getName() {
	return name;
}

public String getId() {
	return id;
}
public void setCourse(Course mathima) {
	course = mathima ; 
}

public void printInfo() {
	System.out.println("Name "+ name + "with id "+ getId());
}

	
	
}
