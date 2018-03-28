class Pattern4
{
	public static void main(String args[])
	{
	int i,j,k,l,a=1;
	for(i=1;i<=5;i++)
	{
		a=i;
		for(j=1;j<=3;j++)
		{
			System.out.print(a+" ");
			if(j==1)
			a=10-i+1;
			else
			a=i+10;
		}
		System.out.println();
	}
	}
}