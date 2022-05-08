
public class CreateCDs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
      AudioCD a1 = new AudioCD("title",7,"John Lennon",17) ;
      AudioCD a2 = new AudioCD("title1",27,"Led Zeppelin",7);
      
      a1.setGotIt(true);
      a2.setGotIt(false);
      
      a1.setComment("my favourite album");
      a2.setComment("buy at first chance");
      
      a1.print();
      a2.print();
      
      a1.BiggestPT(a2);
      
      a1.SmallestNOT(a2);
	}

}
