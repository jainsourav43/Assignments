//9. Financial Application: Calculate future investment value

import java.util.*;

class InvestmentClass
{
	double InvestmentAmount;
	double AnnualInterestRate;

	//constructors

	public InvestmentClass()
	{
		this.InvestmentAmount=this.AnnualInterestRate=0;
	}

	public InvestmentClass(double investment_amount,double annual_interest_rate)
	{
		this.InvestmentAmount=investment_amount;
		this.AnnualInterestRate=annual_interest_rate;
	}

	//get functions

	public double GetAmount()
	{
		return this.InvestmentAmount;
	}

	public double GetRate()
	{
		return this.AnnualInterestRate;
	}

	//set functions

	public void SetAmount(double amount)
	{
		this.InvestmentAmount=amount;
	}

	public void SetRate(double rate)
	{
		this.AnnualInterestRate=rate;
	}

	//to calculate accumulated amount

	public double AccumulateAmount(int years)
	{
		return (this.InvestmentAmount*(1+this.AnnualInterestRate)*years);
	}

}

class Investment
{
	public static void main(String[] args)
	{
		InvestmentClass obj=new InvestmentClass();
		Scanner scan=new Scanner(System.in);
		double InvAmount,AnnIntRate;
		int Years;
		System.out.print("\nEnter investment amount : ");
		InvAmount=scan.nextDouble();
		System.out.print("\nEnter annual interest rate in percentage : ");
		AnnIntRate=scan.nextDouble();
		AnnIntRate=AnnIntRate/100;

		obj.SetAmount(InvAmount);
		obj.SetRate(AnnIntRate);
		
		System.out.print("\nEnter number of years : ");
		Years=scan.nextInt();
		System.out.printf("\nAccumulated value is : $%.3f\n",obj.AccumulateAmount(Years));
	}
}