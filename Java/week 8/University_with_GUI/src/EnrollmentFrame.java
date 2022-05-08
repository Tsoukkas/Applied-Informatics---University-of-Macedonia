import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class EnrollmentFrame extends JFrame {
	
	private JPanel panel;
	private JTextField nameField;
	private JTextField courseField;
	private JButton enrollButton;
	private JButton printCourseDetailsButton;
	
	private ArrayList<Course> courses;
	private ArrayList<Student> students;
	private int studentCounter = 0;
	
	public EnrollmentFrame(ArrayList<Course> courses) {
		
		this.courses = courses;
		
		students = new ArrayList<Student>();
		
		panel = new JPanel();
		nameField = new JTextField(10);
		courseField = new JTextField(10);
		enrollButton = new JButton("enroll In");
		printCourseDetailsButton = new JButton("Print Course Students");
		
		panel.add(nameField);
		panel.add(enrollButton);
		panel.add(courseField);
		panel.add(printCourseDetailsButton);
		
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		enrollButton.addActionListener(listener);
		printCourseDetailsButton.addActionListener(listener);
		
		this.setVisible(true);
		this.setTitle("Student Enrollment");
		this.setSize(400, 300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			
			String courseTitle = courseField.getText();
			
			Course selectedCourse = null;
			for(Course course : courses) {
				if(course.getTitle().equals(courseTitle))
					selectedCourse = course;
			}
			
			if(e.getSource().equals(enrollButton)) {
				
				String studentName = nameField.getText();
				String studentAM = "it" + studentCounter;
				Student newStudent = new Student(studentName, studentAM);
				studentCounter++;
				students.add(newStudent);
				
				selectedCourse.addStudent(newStudent);
				
			}
				
			else {
				selectedCourse.printCourseDetails();
			}
				
		}
		
	}

}
