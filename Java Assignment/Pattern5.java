import java.util.Scanner;
import java.io.*;
class Pattern5
{
	public static void main(String args[])
	{
	int a[]=new int[5];int max=0;int i,j,in;
	Scanner Bastard =new Scanner(System.in);
	a[0]=Bastard.nextInt();
	a[1]=Bastard.nextInt();
	a[2]=Bastard.nextInt();
	a[3]=Bastard.nextInt();
	a[4]=Bastard.nextInt();
	for(i=0;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			in=i;
		}
	}
	for(i=1;i<=max;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[j]>max-i)
			{
				if(j==0)
				System.out.print("*");
				else if(j==1)
				System.out.print("+");
				else if(j==2)
				System.out.print("#");
				else if(j==3)
				System.out.print("|");
				else if(j==4)
				System.out.print("-");
			}
			else
			System.out.print(" ");
			
		}
		System.out.println();
	}
	}
}