import java.util.Scanner;
class Search
{
	public static void main(String args[])
	{
		System.out.println("Enter the value of n ");
		Second obj1=new Second();
		Scanner Bastard =new Scanner(System.in);
		int n,i,s,j,count=0;
		n=Bastard.nextInt();
		int a[]=new int[n];
		int in[]=new int[n];
		System.out.println("Enter the Array Elements ");
		for(i=0;i<n;i++)
		{
			a[i]=Bastard.nextInt();
		}
		System.out.println("Enter theNUmber u wanna search");
		s=Bastard.nextInt(); 
		j=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==s)
			{
				count++;
				in[j++]=i;
			}
		}
		System.out.println("The Number was found "+count +"  Number of times at the following indexes ");
		for(i=0;i<j;i++)
		{
		System.out.println(in[i]+1);
		}
	}
}