import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class CreateStudentFrame extends JFrame {
	
	private ArrayList<Course> courses = new ArrayList();
	
	private JPanel panel = new JPanel();
	private JTextField nameField = new JTextField("Student name");
	private JTextField idField = new JTextField("Student id");
	private JTextField courseNameField = new JTextField("Course Name");
	private JButton enrollStudentButton = new JButton("Enroll Student");
	
	public CreateStudentFrame() {
		
		courses.add(new Course("Java"));
		courses.add(new Course("Math"));
		courses.add(new Course("Databases"));
		courses.add(new Course("Python"));
		
		panel.add(nameField);
		panel.add(idField);
		panel.add(courseNameField);
		panel.add(enrollStudentButton);
		
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		enrollStudentButton.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(400, 400);
		this.setTitle("Create Student");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			
			String name = nameField.getText();
			String id = idField.getText();
			Student student = new Student(name, id);
			
			String courseName = courseNameField.getText();
			
			Course selectedCourse = null;
			for(Course course: courses)
				if(course.getName().equals(courseName))
					selectedCourse = course;
			
			selectedCourse.enrollStudent(student);
			selectedCourse.printCourseDetails();
			
		}
		
	}

}
