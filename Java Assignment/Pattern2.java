class Pattern2
{
	public static void main(String args[])
	{
	 char a =65,b=65;int i,j,k,l=1;
	for(i=1;i<5;i++)
	{	
		a=65;
		for(j=1;j<=i;j++)
		{
			System.out.print(a);
			
			a++;
		}
		for(k=1;k<=8-2*i;k++)
			{
				System.out.print(" ");
			}
		a--;
		b=a;
		for(j=1;j<=i;j++)
		{
			System.out.print(b);
			b--;
			l++;
		}
		System.out.println();
	}
	for(i=1;i<4;i++)
	{	
		a=65;
		for(j=1;j<=4-i;j++)
		{
			System.out.print(a);
			a++;
		}
		for(k=1;k<=2*i;k++)
			{
				System.out.print(" ");
			}
		a--;
		b=a;
		for(j=1;j<=4-i;j++)
		{
			System.out.print(b);
			b--;
			l++;
		}
		System.out.println();
	}

	}
}