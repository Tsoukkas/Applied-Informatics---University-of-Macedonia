public class Coin implements Measurable
{
    private double value;
    private String name;

    public Coin(double value, String name)
    {
        this.value = value;
        this.name = name;
    }

    public double getMeasure()
    {
        return value;
    }
    
    public String getName()
    {
        return name;
    }
}
