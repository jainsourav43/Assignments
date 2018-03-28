//7. Baseball game

import java.util.*;

class Game
{
	int n1,n2,n3;
	int[] strike;

	//constructors

	public Game()
	{
		this.n1=this.n2=this.n3=0;
		this.strike=new int[10];

		//initially setting each strike element to zero later modifiying according to the random numbers generated
		for(int i=0;i<10;i++)
			this.strike[i]=0;
	}

	//get functions

	public int GetN1()
	{
		return this.n1;
	}

	public int GetN2()
	{
		return this.n2;
	}

	public int GetN3()
	{
		return this.n3;
	}

	//set functions

	public void SetNumbers()
	{
		int[] temp_arr=new int[10];

		//to ensure that all numbers should be distinct we use an array of numbers from 1 to 10 and then dearranging their sequence and radomly selecting three numbers

		//first filling array
		for(int i=0;i<10;i++)
			temp_arr[i]=i+1;

		for(int i=0;i<100;i++)
		{
			int index1=(int)((Math.random())*10);
			int index2=(int)((Math.random())*10);
			int temp=temp_arr[index1];
			temp_arr[index1]=temp_arr[index2];
			temp_arr[index2]=temp;
		}

		/*System.out.println();
		for(int i=0;i<10;i++)
			System.out.print(temp_arr[i]+" ");*/

		//selecting three numbers for the game purpose

		this.n1=temp_arr[0];
		this.n2=temp_arr[4];
		this.n3=temp_arr[9];

		//also setting strike array correspondingly 
		this.strike[this.n1-1]=1;
		this.strike[this.n2-1]=2;
		this.strike[this.n3-1]=3;
	}

	//fuction for cheking every move of the player (a,b,c) are inputs of the player

	public int Check(int a,int b,int c)
	{
		int f1,f2,f3;
		f1=this.strike[a-1];
		f2=this.strike[b-1];
		f3=this.strike[c-1];
		if(f1==1 && f2==2 && f3==3)
			return -1;
		int s=0,ba=0;  //s for strike and ba for ball
		if(a==this.n1)
			s++;
		if(b==this.n2)
			s++;
		if(c==this.n3)
			s++;
		if(f1!=0)
			ba++;
		if(f2!=0)
			ba++;
		if(f3!=0)
			ba++;
		ba=ba-s;

		return (s*10 + ba);   //an integer where first digit is number of strikes and 2nd digit is number of balls

	}
	
}

class Baseball
{
	public static void main(String[] args)
	{
		Game ball=new Game();
		Scanner scanner=new Scanner(System.in);

		int a,b,c;

		ball.SetNumbers();

		//System.out.println("Numbers are "+ball.GetN1()+" "+ball.GetN2()+" "+ball.GetN3()+"\n");

		int count=0;
		do
		{
			System.out.print("\n % Enter three numbers >> \n ");
			a=scanner.nextInt();
			b=scanner.nextInt();
			c=scanner.nextInt();
			int res=ball.Check(a,b,c);
			if(res==-1)
			{
				System.out.println(" % Wonderful.\n");
				break;
			}
			else if((100 - count*5)<=0)
			{
				System.out.println("\n % Sorry. Your score becomes invalid.\n");
				break;
			}
			else 
			{
				System.out.print(" % "+(int)(res%10) + " ball " + (int)(res/10) + " strike ");
			}
			count++;
		}
		while(true);
		if((100-count*5)<=0)
		{
			System.out.print("\n % Your Score becomes Zero.\n\nThree numbers were : ");
			System.out.print(ball.GetN1()+" "+ball.GetN2()+" "+ball.GetN3()+"\n\n");
		}
		else
		{
			System.out.print("\n % Your score is : "+(int)(100-count*5)+"\n\n");
		}	
	}
}