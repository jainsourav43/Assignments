// 12. Scissor, Rock, Paper

import java.util.*;

//Scissor Rock Paper

class GameClass
{

	//2D array for checking winner (1 for row selected person won, -1 for column selected person won, 0 for both selected same so game draw)
	static int[][] Decision={{0,-1,1},{1,0,-1},{-1,1,0}};

	public static int CheckWinner(int input1,int input2)
	{
		//checking result of play
		if(Decision[input1][input2]==1)
		{
			//input1 user won
			return 1;
		}
		else if(Decision[input1][input2]==-1)
		{
			//input2 user won
			return 2;
		}
		else
		{
			//draw
			return 0;
		}
	}
}

class Game
{
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		System.out.print("\nScissor(0), Rock(1), Paper(2) : ");

		//taking input of user
		int input=scan.nextInt();

		//generating random computer's input
		int computer=(int)(Math.random()*3);

		System.out.print("\nComputer selected : "+computer+"\n");

		int result=GameClass.CheckWinner(input,computer);

		//checking result of play
		if(result==1)
		{
			//input1 user won
			System.out.print("\nYou won.");
		}
		else if(result==2)
		{
			//input2 user won
			System.out.print("\nComputer won.");
		}
		else
		{
			//draw
			System.out.print("\nDraw");
		}
		
		System.out.println();
		System.out.println();
	}
}