import java.util.Scanner;
class Second
{
   void findsecond(int a[],int n)
  {
	
	int max=0,i,j,in=0;
	boolean v[]=new boolean[n];
	for(i=0;i<n;i++)
	v[i]=true;
	for(i=0;i<2;i++)
	{
		 max=0;
		for(j=0;j<n;j++)
		{
			if(max<a[j]&&v[j]==true)
			{
				max=a[j];
				in=j;
			}		
		}
		v[in]=false;
	}
        System.out.println("The second maximum number id = "+max);
  }

void findsecondmin(int a[],int n)
  {
	
	int max=0,i,j,in=0;
	boolean v[]=new boolean[n];
	for(i=0;i<n;i++)
	v[i]=true;
	for(i=0;i<2;i++)
	{
		 max=1000000;
		for(j=0;j<n;j++)
		{
			if(max>a[j]&&v[j]==true)
			{
				max=a[j];
				in=j;
			}		
		}
		v[in]=false;
	}
        System.out.println("The second Minimum number is = "+max);
  }
	public static void main(String args[])
	{
		System.out.println("Enter the value of n ");
		Second obj1=new Second();
		Scanner Bastard =new Scanner(System.in);
		int n,i;
		n=Bastard.nextInt();
		int a[]=new int[n];
		System.out.println("Enter the Array Elements ");
		for(i=0;i<n;i++)
		{
			a[i]=Bastard.nextInt();
		}
		obj1.findsecond(a,n);
		obj1.findsecondmin(a,n);
	}
}