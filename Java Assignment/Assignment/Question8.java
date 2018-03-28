//8. Grid

import java.util.*;

//main class grid

class GridClass
{
	int size;
	int[][] grid;

	//constructors
	public GridClass()
	{
		this.size=0;
		this.grid=null;
	}

	public GridClass(int size)
	{
		this.size=size;
		this.grid=new int[size][size];
	}

	//get functions
	public int GetSize()
	{
		return this.size;
	}

	public int[][] GetGrid()
	{
		return this.grid;
	}

	//Set functions 
	public void SetSize(int size)
	{
		this.size=size;
	}

	public void SetGrid(int[][] grid)
	{
		this.grid=grid;
	}

	//for generating values and filling the grid of size 'size*size'
	public void GenerateGrid()
	{
		/*
			taking a temporary array of size (size*size) and initially filling with each element in increasing order,
			then to dearrange the order swaping, two elements present at randomly generated indexes within the range of the array,
			then writing that array to the main grid
		*/
		int[] Temp=new int[this.size*this.size];

		for(int i=0;i<this.size*this.size;i++)
		{
			Temp[i]=i+1;
		}

		//resetting grid of the class

		this.grid=new int[this.size][this.size];

		for(int i=0;i<this.size*this.size;i++)
		{ 
			int first=((int)(Math.random()*(this.size*this.size)));
			int second=((int)(Math.random()*(this.size*this.size)));
			int temp=Temp[first];
			Temp[first]=Temp[second];
			Temp[second]=temp;
		}

		//for index of [Temp] array
		int count=0;

		//filling grid with randomly generated distinct values within the range
		for(int i=0;i<this.size;i++)
		{
			for(int j=0;j<this.size;j++)
			{
				this.grid[i][j]=Temp[count];
				count++;
			}
		}
	}	
}

class Question8
{
	public static void main(String[] args)
	{
		Scanner scanner=new Scanner(System.in);
		GridClass obj=new GridClass();

		//choice for taking input of user
		int choice;

		// n for size of grid
		int n=0;

		//flag for exiting from loop
		boolean flag=true;

		//for checking if size has been entered or not before generating a grid (n should not be 0 for generating a grid)
		boolean SizeEntered=false;

		do
		{
			System.out.println("\nSelect a choice : ");
			System.out.println("1: Enter the grid size ");
			System.out.println("2: Generate the grid");
			System.out.println("3: Exit\n");
			System.out.print("\nEnter choice here : ");
			choice=scanner.nextInt();
			System.out.println();
			switch(choice)
			{
				case 1: System.out.print("\nPlease enter size of grid : ");
						n=scanner.nextInt();
						if(n!=0)
						{
							SizeEntered=true;
							obj.SetSize(n);
						}
						else
						{
							System.out.print("\nSize entered is not valid.\n");
						}
						break;
				case 2: if(!SizeEntered)
						{
							System.out.print("\nYou have not enterd size for the grid. Please enter size first by selecting option 1.\n\n");
							break;
						}
						obj.GenerateGrid();
						System.out.println("\nGrid with size "+n+"x"+n+" is : \n");
						int [][] temp=obj.GetGrid();
						Question8.PrintGrid(temp,n);
						break;
				case 3: System.out.println("\nYou selected to exit.\n\t\tGood Bye\n\n");
						flag=false;
						break;
			}
			if(flag)
			{
				System.out.print("\nDo You want to continue(Y/N) ? : ");
				char ch=(scanner.next()).charAt(0);
				if(ch!='Y'&&ch!='y')
				{
					flag=false;
					System.out.println("\nBye\n");
				}
			}
		}
		while(flag);
	}

		//just for printing the grid
	public static void PrintGrid(int[][] grid,int size)
	{
		System.out.println();
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				System.out.format("%3d",grid[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
}