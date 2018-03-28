class Pattern3
{
	public static void main(String args[])
	{
	int i,j,k;
	for(i=1;i<=5;i++)
	{

		//for(j=1;j<=i;j++)
		//{
			System.out.print('*');
			if(i!=1)
			{
			for(k=1;k<=i-2;k++)
			{
				System.out.print(" ");
			}
			System.out.print('*');
			}
			for(k=1;k<=12-2*i;k++)
			{
				System.out.print(" ");
			}
			System.out.print('*');
			if(i!=1)
			{
			for(k=1;k<=i-2;k++)
			{
				System.out.print(" ");
			}
			System.out.print('*');
			}
		//}
      		System.out.println();
	}
	for(i=1;i<=12;i++)
	{
	System.out.print('*');
	}
	}
}
