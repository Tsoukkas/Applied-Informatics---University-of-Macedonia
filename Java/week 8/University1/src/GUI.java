import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
	
	//step 1
	private JPanel panel;
	//step 2
	private JTextField nameField, idField;
	private JButton createStudentButton;
	private JTextField courseField;
	private JButton printCourseDetailsButton;
	
	private ArrayList<Course> courses = new ArrayList<Course>();
	
	public GUI() {
		
		courses.add(new Course("Java"));
		courses.add(new Course("Python"));
		courses.add(new Course("C++"));
		courses.add(new Course("JavaScript"));
		
		panel = new JPanel();
		
		nameField = new JTextField("Enter the name");
		idField = new JTextField("Enter the id");
		createStudentButton = new JButton("Create Student");
		courseField = new JTextField("Enter a course");
		printCourseDetailsButton = new JButton("Print course details");
		
		//step 3
		panel.add(nameField);
		panel.add(idField);
		panel.add(createStudentButton);
		panel.add(courseField);
		panel.add(printCourseDetailsButton);
		
		//step 4
		this.setContentPane(panel);
		
		//3o βήμα: κατασκευή αντικειμένου ακροατή
		ButtonListener listener = new ButtonListener();
		//4o βήμα: σύνδεση ακροατή με πηγή συμβάτων
		createStudentButton.addActionListener(listener);
		printCourseDetailsButton.addActionListener(listener);
		
		this.setSize(400, 400);
		this.setVisible(true);
		this.setTitle("Student form");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	//1ο βήμα, δημιουργία κλάσης-ακροατή
	class ButtonListener implements ActionListener {
		
		//2ο βήμα: Συγγραφή εκτελούμενου κώδικα
		public void actionPerformed(ActionEvent e) {
			
			if(e.getSource().equals(createStudentButton)) {
			
				String name = nameField.getText();
				String id = idField.getText();
				
				Student s = new Student(name, id);
				
				System.out.println("A student has been successfully created!!!");
				
				//θέλω να προσθέσω τον νέο φοιτητή στο επιλεγμένο μάθημα
				String courseName = courseField.getText();
				
				for(Course course: courses)
					if(courseName.equals(course.getTitle()))
						course.addStudent(s);
			}
			else {
				
				String selectedCourseName = courseField.getText();
				
				Course selectedCourse = null;
				
				for(Course course: courses)
					if(selectedCourseName.equals(course.getTitle()))
						selectedCourse = course;
				
				selectedCourse.printDetails();
				
			}
		}
		
	}

}
