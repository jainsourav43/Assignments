import java.util.*;

class Grid{
	int n;

	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}
	boolean check(int d[][])
	{
		
	}
	
	
}
public class Question8 {
	public static void main(String args[])
	{
		int i,j;
		int[][] grid = new int [10][10];
		String choice;char ch;
		Grid obj = new Grid();
		do
		{
	    System.out.println("Select Choice");
		System.out.println("Enter the Grid Size :"+1 );
		System.out.println("Generate the Grid  :"+2);
		System.out.println("Exit :"+3);
		Random r =new Random();
		Scanner scan =new Scanner(System.in);
		i=scan.nextInt();
		if(i==1)
		{
			System.out.println("Enter the Size of the Grid");
			j=scan.nextInt();
			obj.setN(j);
		}
		else if (i==2)
		{
			for(i=0;i<obj.getN();i++)
			{
				for(j=0;j<obj.getN();j++)
				{
					grid[i][j]=r.nextInt(obj.getN()*obj.getN()+50);
				}
			}
			for(i=0;i<obj.getN();i++)
			{
				for(j=0;j<obj.getN();j++)
				{
					System.out.print(grid[i][j]+ " ");
				}
				System.out.println();
			}
		}
		else if (i==3)
		{
			break;
		}
		else {
		System.out.println("Wrong choice ");	
		}
		System.out.println("Do u Want to Continue ");
		choice=scan.next();
		ch=choice.charAt(0);

		}while(ch=='Y');
	}

}
