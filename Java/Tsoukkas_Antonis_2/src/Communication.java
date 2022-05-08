import java.util.ArrayList;

public class Communication{
   private String num1;
   private String num2;
   private int year;
   private int mouth;
   private int day;
  
public String getNumber1() {
	return num1;
}

public String getNumber2() {
	return num2;
}
public Communication(String pnum ,String pnum1,int number,int number1,int number2){
    num1=pnum;
    num2=pnum1;
    year=number;
    mouth=number1;
    day=number2;
}

public void printInfo(){
   
  System.out.println("Between " + num1 + "---" + num2
+ "on " + year + "/" + mouth + "/" + day);
}

}
