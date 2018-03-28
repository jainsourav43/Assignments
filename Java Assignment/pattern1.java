
class pattern1
{
	public static void main(String args[])
	{
		char  a;int j;
		int change =68;
		a=68;j=1;
		while(a<91)
		{
		if(j==1)
		{
		j++;
		for(int i=0;i<3;i++)
		{
		System.out.print(" ");
		}
		System.out.print(a);
			a++;
		System.out.print(a);
		a+=7;
		}
		else
		{
		for(int i=0;i<6;i++)
		{
		System.out.print(" ");
		}
		System.out.print(a);a++;
		System.out.print(a);
		a+=7;
		}
		}
		a=67;k=2;
		while(a<91)
		{
			  for(j=0;j<k;j++)
			   {
				System.out.print(" ");
			    }
			    System.out.print(a);
			   for(j=0;j<k;j++)
			   {
				System.out.print(" ");
			    }
		}
		

	}
}