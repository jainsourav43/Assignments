// 12. ISBN

import java.util.*;

class ISBNClass
{
	String number;

	//constructors

	public ISBNClass()
	{
		this.number=null;
	}

	public ISBNClass(String number)
	{
		this.number=number;
	}

	//get functions

	public String GetNumber()
	{
		return this.number;
	}

	//set functions
	public void SetNumber(String number)
	{
		if(number.length()>10)
			return;
		for(int i=0;i<number.length();i++)
		{
			char c=number.charAt(i);
			if((int)(c)>57 && (int)(c)<48 && i!=9)
			{
				return;
			}
			else if(i==9 && !(c=='x' || c=='X'))
			{
				return;
			}
		}
		this.number=number;
	}

	//for setting last number
	public void SetLastDigit()
	{
		if(this.number.length()!=9)
			return;

		//for saving sum
		int TempSum=0;

		for(int i=0;i<9;i++)
		{
			TempSum=TempSum+(number.charAt(i)-48)*(i+1);
		}


		if(TempSum%11==10)
			this.number=this.number+"X";
		else
			{
				switch(TempSum%11)
				{
					case 0: this.number=this.number+"0";
							break;
					case 1: this.number=this.number+"1";
							break;
					case 2: this.number=this.number+"2";
							break;
					case 3: this.number=this.number+"3";
							break;
					case 4: this.number=this.number+"4";
							break;
					case 5: this.number=this.number+"5";
							break;
					case 6: this.number=this.number+"6";
							break;
					case 7: this.number=this.number+"7";
							break;
					case 8: this.number=this.number+"8";
							break;
					case 9: this.number=this.number+"9";
							break;
				}
			}
	}
}

class ISBN
{
	public static void main(String[] args)
	{
		ISBNClass obj=new ISBNClass();

		String Number;
		Scanner scan=new Scanner(System.in);
		System.out.print("\nEnter the first 9 digits of and ISBN as integer : ");
		Number=scan.nextLine();

		obj.SetNumber(Number);
		obj.SetLastDigit();
		
		System.out.print("The ISBN-10 number is "+obj.GetNumber()+"\n");
	}
}