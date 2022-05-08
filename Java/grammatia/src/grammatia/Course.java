package grammatia;

import java.util.Scanner;
import java.util.ArrayList;


public class Course {
	private String name;
	private ClassRoom aithusa;
	private ArrayList<Student> enrolledstudents ; 
	 enrolledstudents = new ArrayList<Student>();
	 
public Course(String text , int number) {
	name = text;
}
public String getName() {
	return name;
}

public void addStudent(Student s) {
	int count = 0;
	if(count < aithusa.capacity) {
	enrolledstudents.add(s);
	count++;
	}
	else {
		System.out.println("The classroom is full !");
	}
}
public void printStudents(Student s) {
	int index = 0;
	while(index <=aithusa.capacity ) {
		Student s1 = enrolledstudents.get(index);
      index++;
	}
}

}

