//6. CDA Account

import java.util.*;
import java.text.*;


//base class

class Account
{

	//private members 
	long AccountNumber;
	double Balance;
	float AnnualInterestRate;
	Date Created;

	//constructors

	public Account()
	{
		this.AccountNumber=0;
		this.Balance=0;
		this.AnnualInterestRate=0;
		this.Created=new Date();
	}

	//to create and account

	public Account(long account_number,double balance)
	{
		this.AccountNumber=account_number;
		this.Balance=balance;
		this.Created=new Date();
		this.AnnualInterestRate=0;
	}

	//get methods

	public long GetAccountNumber()
	{
		return this.AccountNumber;
	}

	public double GetBalance()
	{
		return this.Balance;
	}

	public float AnnualInterestRate()
	{
		return this.AnnualInterestRate;
	}

	//set functions  don't provide set functions for balance and created since they should not be altered

	public void SetAccountNumber(long number)
	{
		this.AccountNumber=number;
	}

	public void SetAnnualInterestRate(float annual_interest_rate)
	{
		this.AnnualInterestRate=annual_interest_rate;
	}

	public void Deposit(double Amount)
	{
		if(Amount>0)
		{
			this.Balance+=Amount;
		}
	}

	public double WithDraw(double Amount)
	{
		if(Amount<=this.Balance)
		{
			this.Balance-=Amount;
			return Amount;
		}
		return 0.0;
	}
}

//new CDAccount Class

class CDAccount extends Account
{
	int Duration;
	float CDAnnualInterestRate;

	//constructors;

	public CDAccount()
	{
		this.Duration=0;
		this.CDAnnualInterestRate=0.0f;
	}

	public CDAccount(int duration,float annual_interest_rate)
	{
		this.Duration=duration;
		super.SetAnnualInterestRate(annual_interest_rate);
		this.CDAnnualInterestRate=((float)(duration/3f)*(0.5f)+(float)(super.AnnualInterestRate));
	}

	//get functions

	public int getDuration()
	{
		return this.Duration;
	}

	public float CDAnnualInterestRate()
	{
		return this.CDAnnualInterestRate;
	}

	//set functions

	public void setDuration(int month)
	{
		this.Duration=month;
	}

	public void setCDAnnualInterestRate(float rate)
	{
		this.CDAnnualInterestRate=rate;
	}

	public double BalanceAfter(int duration)
	{
		double ReturnAmount=super.Balance;
		double interest=0.0;
		double sum=0.0;

		for(int i=1;i<=duration;i++)
		{

			interest=interest+ReturnAmount*(this.CDAnnualInterestRate/(1200));
			sum=sum+interest;
			ReturnAmount+=interest;
		}

		return (double)(super.Balance+sum);
	}

	public String PrintInformation()
	{
		//Concating every details of an account into a string and returing that string to print in the main function
		String PrintString=new String();
		PrintString="-------------\t--------------\t\t-------\t\t------------\n"+"AccountNumber\tInitialBalance\t\tRate(%)\t\tDate Created\n"+"-------------\t--------------\t\t-------\t\t------------\n";
		PrintString=PrintString+Long.toString(super.AccountNumber)+"\t\t"+Double.toString(super.Balance)+"\t\t\t"+Float.toString(this.CDAnnualInterestRate);
		PrintString=PrintString+"\t\t"+super.Created+"\n\n";
		for(int i=0;i<this.Duration;i++)
		{
			String priceString = new DecimalFormat("$##.##").format((this.BalanceAfter(i+1)));
			PrintString=PrintString+"\n\t\t\tMonth "+Integer.toString(i+1);
			if(i<9)
				PrintString=PrintString+"     ";
			else
				PrintString=PrintString+"    ";
				
			PrintString=PrintString+priceString;
		}
		return PrintString;
	}
}

class Question6
{
	public static void main(String[] args)
	{
		CDAccount[] obj=new CDAccount[5];
		for(int i=0;i<5;i++)
		{
			obj[i]=new CDAccount((i+1)*3,3.0f);
			obj[i].Deposit(1000.00*(i+1));
			obj[i].SetAccountNumber(100*(i+1));
		}

		for(int i=0;i<5;i++)
		{
			System.out.println("\n\n\n");
			System.out.println(obj[i].PrintInformation());
		}
	}
}