public class DataSetTest
{
   public static void main(String[] args)
   {
      BankAccountDataSet bankData = new BankAccountDataSet();
      bankData.add(new BankAccount(0));
      bankData.add(new BankAccount(10000));
      bankData.add(new BankAccount(2000));
      System.out.println("Average balance = " + bankData.getAverage());
      BankAccount maxBankAccount = bankData.getMaximum();
      System.out.println("Highest balance = " + maxBankAccount.getBalance());
      
      CoinDataSet coinData = new CoinDataSet();
      coinData.add(new Coin(0.25, "quarter"));
      coinData.add(new Coin(0.1, "dime"));
      coinData.add(new Coin(0.05, "nickel"));
      System.out.println("Average coin value = " + coinData.getAverage());
      Coin maxCoin = coinData.getMaximum();
      System.out.println("Highest coin value = " + maxCoin.getValue());
    }
}