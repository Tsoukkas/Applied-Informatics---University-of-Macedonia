
public class Person {
    protected String name;
    
    public Person() {
    	this.name= "No name yet";
    }
    public Person(String initialName) {
    	name=initialName;
    }
    public void setname(String newname) {
    	name=newname;
    }
    public String getName() {
    	return name;
    }
    public void writeOutput() {
    	System.out.println("Name: " +name);
    }
    public boolean hasSameName(Person otherPerson) {
    	return this.name.equalsIgnoreCase(otherPerson.name);
    }
}