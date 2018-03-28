

import java.util.*;
@SuppressWarnings("resource")
class ISBN{
	int d;
	// set d
	void setds()
	{
		Scanner scan =new Scanner(System.in);
		d=scan.nextInt();
	}
	//check leading zeroes
    int checkTrailingZero()
	{
		int temp=d;
		int count=0;
		while(temp>0)
		{
			temp/=10;
			count++;
		}
		return count;
	}
    
    
    //return sum
	int total()
	{
		int temp=d;
		int i=0,sum=0,j=9;
		for(i=0;i<9;i++)
		{
			sum+=(temp%10)*(j--);
			temp=temp/10;
		}
		return sum;
		
	}
	
	//check the condition for x and print the correct ISBN 
	void checkAndPrint()
	{
		if(checkTrailingZero()<9)
		{
			for(int i=0;i<9-checkTrailingZero();i++)
			{
				System.out.print("0");
			}
		}
		System.out.print(d);
		if(total()%11<10)
		{
			System.out.print(total()%11);
		}
		else
		{
			System.out.print("X");
		}
			
	}
	
	
}
public class Question11 {
	public static void main(String args[])
	{
	ISBN obj= new ISBN();
	System.out.println("Enter the nine digits of your ISBN ");
	obj.setds();
	obj.checkAndPrint();
	}
}
