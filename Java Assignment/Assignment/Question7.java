import java.util.*;
// game Class 
class game
{
	int n1,n2,n3;// Date to be given by the Cute User 
        // Getter and Setter 
	public int getN1() {
		return n1;
	}

	public void setN1(int n1) {
		this.n1 = n1;
	}

	public int getN2() {
		return n2;
	}

	public void setN2(int n2) {
		this.n2 = n2;
	}

	public int getN3() {
		return n3;
	}

	public void setN3(int n3) {
		this.n3 = n3;
	}
// Generating the random Numbers and Checking  the Game Condition
	void randomgen()
	{
		int[] temp=new int[3];
		int i,score=100,strike=0,balls=0,tem,attempt=0;
		Random r=new Random();
		temp[0]=r.nextInt(10);
		temp[1]=r.nextInt(10);
		temp[2]=r.nextInt(10);	
		while(true)
		{
			System.out.println("Enter three numbers ");
			strike =0;
			balls =0;
			Scanner scan =new Scanner(System.in);
			tem=scan.nextInt();
			setN1(tem);
			tem=scan.nextInt();
			setN2(tem);
			tem=scan.nextInt();
			setN3(tem);
			System.out.println("You Entered " +n1+" " +n2+" "+n3 );
			System.out.println("Computer Generated "+ temp[0] +" "+ temp[1] +" "+ temp[2]);
			if(getN1()==temp[0])
			{
				strike++;
			}
			else if(getN1()==temp[1]||getN1()==temp[2])
			{
				balls++;
			}
			if(getN2()==temp[1])
			{
				strike++;
			}
			else if(getN2()==temp[0]||getN2()==temp[2])
			{
				balls++;
			}
			if(getN3()==temp[2])
			{
				strike++;
			}
			else if(getN3()==temp[1]||getN3()==temp[0])
			{
				balls++;
			}
			attempt++;
			System.out.println("You have " + strike +" stike  and  "+  balls +" balls");
			if(strike==3)break;
			if(attempt>20)break;
		}
		
		if(strike==3)
		{
			System.out.println("You WON!! and Your Score  is " + (score-5*(attempt))); 
		}
		else
		{
			System.out.println("You lose");
		}
		
	}
}
public class Question7 {
	public static void main(String args[])
	{
		
		game obj =new game();
		obj.randomgen();
		
		
	}

}
