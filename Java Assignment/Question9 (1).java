import java.util.Scanner;

class futureInvestment{
	double annualInterestRate;
	int noOfYears;
	double amount;
	
	public double getAnnualInterestRate() {
		return annualInterestRate;
	}

	public void setAnnualInterestRate(double annualInterestRate) {
		this.annualInterestRate = annualInterestRate;
	}

	public int getNoOfYears() {
		return noOfYears;
	}

	public void setNoOfYears(int noOfYears) {
		this.noOfYears = noOfYears;
	}

	public double getAmount() {
		return amount;
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}

	double calculate()
	{
		double tmp;
		tmp=getAmount()*getAnnualInterestRate()*getNoOfYears()/100;
		return tmp;
	}
	void Display()
	{
		double toDisplay=( calculate());
	 System.out.println("Accumulated Amount is : "+(toDisplay+getAmount()));
	
	}
}
public class Question9 {
	
	@SuppressWarnings("resource")
	public static void main(String args[])
	{
	   futureInvestment obj=new futureInvestment();
	   System.out.println("Enter the Amount :");
	   Scanner scan = new Scanner(System.in);
	   int temp;double t;
	   t= scan.nextDouble();
	   obj.setAmount(t);
	   System.out.println("Enter the Rate ofInterest :");
	   t=scan.nextDouble();
	   obj.setAnnualInterestRate(t);
	   System.out.println("Ente the years :");
	   temp= scan.nextInt();
	   obj.setNoOfYears(temp);
	   obj.Display();
	   
	}

}
