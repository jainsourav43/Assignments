// 10. Future Day

import java.util.*;

class DayClass
{
	int day;

	//constructors

	public DayClass()
	{
		this.day=0;
	}

	public DayClass(int k)
	{
		if(k>=0 && k<=6)
			this.day=k;
		else
			this.day=0;
	}

	//get functions

	public int GetDay()
	{
		return this.day;
	}

	//set functions

	public void SetDay(int k)
	{
		this.day=k;
	}

	//for getting day corresponding to an integer
	public static String Day(int k)
	{
		switch(k)
		{
			case 0:	return "Sunday";
			case 1: return "Monday";
			case 2: return "Tuesday";
			case 3: return "Wednesday";
			case 4: return "Thursday";
			case 5: return "Friday";
			case 6: return "Saturday";
		}
		return "NoDay";
	}
	
}

class Day
{
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);

		DayClass obj=new DayClass();

		int CurrDay,Days;
		do
		{
			System.out.print("\nEnter today's day : ");
			CurrDay=scan.nextInt();
			if(CurrDay<0||CurrDay>6)
			{
				System.out.println("\nYou have Entered an invalid day.Please try again.");
			}
		}
		while(CurrDay<0||CurrDay>6);

		//setting day of the instance of DayClass object
		obj.SetDay(CurrDay);

		do
		{
			System.out.print("\nEnter number of days elapsed since today : ");
			Days=scan.nextInt();
			if(Days<0)
			{
				System.out.println("\nOnly positive values are allowed.Please enter days agian.");
			}
		}
		while(Days<0);

		System.out.println("\nToday is "+DayClass.Day(obj.GetDay())+" and future day is "+DayClass.Day((obj.GetDay()+Days)%7));
	}
}