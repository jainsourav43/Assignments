//14. Financial Application : loan amortization shedule

import java.util.*;

class LoanClass
{
	double Amount;
	int Years;
	float AnnualInterestRate;

	public LoanClass()
	{
		this.Amount=0;
		this.Years=0;
		this.AnnualInterestRate=0;
	}

	public LoanClass(double amount,int years,float rate)
	{
		this.Amount=amount;
		this.Years=years;
		this.AnnualInterestRate=rate/100;
	}

	//get functions

	public double GetAmount()
	{
		return this.Amount;
	}

	public int GetYears()
	{
		return this.Years;
	}

	public float GetAnnualInterestRate()
	{
		return this.AnnualInterestRate;
	}

	//set functions

	public void SetAmount(double amount)
	{
		this.Amount=amount;
	}

	public void SetYears(int years)
	{
		this.Years=years;
	}

	public void SetAnnualInterest(float rate)
	{
		this.AnnualInterestRate=rate/100;
	}

	//other necessary functions

	//for calculating monthly payment of loan

	public double MonthlyPayment()
	{
		return (((this.AnnualInterestRate/12)*this.Amount*(Math.pow((1+(this.AnnualInterestRate/12)),this.Years*12)))/((Math.pow(this.AnnualInterestRate/12+1,this.Years*12))-1));
	}
}

class Loan
{
	public static void main(String[] args)
	{
		double amount;
		float rate;
		int years;

		LoanClass obj=new LoanClass();

		System.out.print("\nEnter amount : ");
		amount=(new Scanner(System.in)).nextDouble();
		System.out.print("\nEnter annual interest rate : ");
		rate=(new Scanner(System.in)).nextFloat();
		System.out.print("\nEnter years : ");
		years=(new Scanner(System.in)).nextInt();

		obj.SetAmount(amount);
		obj.SetYears(years);
		obj.SetAnnualInterest(rate);

		System.out.printf("Monthly Payment : %.2f\n",obj.MonthlyPayment());
		System.out.printf("Total Payment : %.2f\n",obj.MonthlyPayment()*12);

		double principal;
		double interest=obj.GetAmount()*obj.GetAnnualInterestRate()/12;

		System.out.println("\nPayment#\tInterest\tPrincipal\tBalance\n");
		for(int i=1;i<=12;i++)
		{
			principal=obj.MonthlyPayment()-interest;
			amount-=principal;
			System.out.printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n",i,interest,principal,amount);
			//System.out.println(i+"\t"+interest+"\t"+principal+"\t"+amount);
			interest=amount*obj.GetAnnualInterestRate()/12;

		}
	}
}