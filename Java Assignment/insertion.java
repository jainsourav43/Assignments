import java.util.Scanner;
class insertion
{
	void insertion1(int a[],int n)
	{
		int i,k;
		for(i=1;i<n;i++)
		{
			for(k=i;k>0&&a[k]>a[i];k--)
			{
				a[k]=a[k-1];
			}
			System.out.println("The k+1  is "+ (k+1));
			a[k+1]=a[i];
		}
		System.out.println("The Sorted array is ");
		for(i=0;i<n;i++)
		System.out.println(a[i]);	
	}
	public static void main(String args[])
	{
		System.out.println("Enter the value of n ");
		insertion obj1=new insertion();
		Scanner Bastard =new Scanner(System.in);
		int n,i;
		n=Bastard.nextInt();
		int a[]=new int[n];
		System.out.println("Enter the Array Elements ");
		for(i=0;i<n;i++)
		{
			a[i]=Bastard.nextInt();
		}
                obj1.insertion1(a,n);
	}
}