// 4. years

import java.util.*;

// main class

class Minutes
{
	//memeber variable
	long minutes;

	//constructor

	public Minutes()
	{
		this.minutes=0;
	}

	public Minutes(long minutes)
	{
		this.minutes=minutes;
	}

	//get functions

	public long GetMinutes()
	{
		return this.minutes;
	}

	//set functions

	public void SetMinutes(long minutes)
	{
		this.minutes=minutes;
	}

	// function to calculate number of years

	public long Years()
	{
		return this.minutes/(365*24*60);
	}

	//to calculate days
	public long Days()
	{
		return ((this.minutes%(365*24*60))/(24*60));
	}
}

class Years
{
	public static void main(String[] args)
	{
		//creating an object of Minutes class
		Minutes obj=new Minutes();

		long n;
		System.out.print("\nEnter minutes : ");
		Scanner scanner=new Scanner(System.in);

		n=scanner.nextInt();
		obj.SetMinutes(n);

		System.out.print("\nNumber of years approximately = "+obj.Years()+"\n");
		System.out.println("\nNumber of days approximately = "+obj.Days());

	}
}