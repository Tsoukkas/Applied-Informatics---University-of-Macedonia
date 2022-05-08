
public class Course {
	private String name;
	private int credits;
	//pos dilonoume pinaka tipu student
	//pinakas 100 thesewn
	private Student[] enrolledStudents=new  Student[100];
	private int counter;
	
	public Course(String text,int number) {
		
		name=text;
		credits=number;
	    //den valame metavliti epd o counter ine apla enas arithmos kai sinithos to 0
		counter=0;
	}
//epistrefi to onoma tu mathimatos
	public String getName() {
		return name;
	}
//epistrefi tis ores tu mathimatos
	public int getCredits() {
		return credits;
	}
	
	//to arnitiko ine oti o pinakas exi size
	public void addStudent(Student s) {
		//kathos den exun kseperasti oi 100 thesis tu pinaka
		if(counter< enrolledStudents.length) {
     //edo apla vazi stin siggekrimeni thesi tu pinaka ola ta stixia tu mathiti	
		enrolledStudents[counter]=s;
		//afksisi gia na kserumeposus mathites exume mesa ston pinaka
		counter++;
		}
		else System.out.println("Course is full!");
	}
	
	public void printStudentsInfo() {
		
		System.out.println("Course:"+name);
		for(int i=0; i<=counter; i++) 
		{	
			Student s=enrolledStudents[i];
			/*
			s.printInfo();
			//OR
			grami 38-40 mpori na grafti kai--> enrolledStudents[i].printInfo();
			*/
			System.out.println((i+1)+"."+s.getName()+"("+s.getId()+")");
			
		}
	}
}
