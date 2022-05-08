import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		
		MyFrame mf = new MyFrame();
		mf.setVisible(true);
		mf.setSize(400, 400);
		mf.setTitle("My first window");
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

}
