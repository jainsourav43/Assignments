//13. Parameter of a Triangle

import java.util.*;

abstract class Shape
{
	abstract float Area();
	abstract float Parameter();
}

class TriangleClass extends Shape
{
	float side1,side2,side3;

	//constructors
	TriangleClass()
	{
		this.side1=this.side2=this.side3=0;
	}

	TriangleClass(float a,float b,float c)
	{
		this.side1=a;
		this.side2=b;
		this.side3=c;
	}

	//get functions

	public float GetSide1()
	{
		return this.side1;
	}

	public float GetSide2()
	{
		return this.side2;
	}

	public float GetSide3()
	{
		return this.side3;
	}

	//set functions

	public void SetSide1(float side)
	{
		this.side1=side;
	}

	public void SetSide2(float side)
	{
		this.side2=side;
	}

	public void SetSide3(float side)
	{
		this.side3=side;
	}

	//overriding base class methods

	@Override
	public float Parameter()
	{
		//checking first if trinagle is valid
		if(!this.isTriangle())
			return 0;
		return (this.side1+this.side2+this.side3);
	}

	@Override
	public float Area()
	{
		//cehcking first if trinagle is valid
		if(!this.isTriangle())
			return 0;
		//p for paramter of the triangle
		float p=this.Parameter()/2;
		return (float)(Math.sqrt(p*(p-this.side1)*(p-this.side2)*(this.side3)));
	}

	//for checking if triangle with given sides is valid or not
	public boolean isTriangle()
	{
		if(this.side1+this.side2<=this.side3)
			return false;
		if(this.side1+this.side3<=this.side2)
			return false;
		if(this.side2+this.side3<=this.side1)
			return false;
		return true;
	}

}

class Triangle
{

	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);

		//creating instance of Triangle class
		TriangleClass triangle=new TriangleClass();

		//temporary variable for taking input
		int temp;

		//taking inputs of three sides
		System.out.print("\nEnter side1 of the triangle : ");
		temp=scan.nextInt();
		triangle.SetSide1(temp);

		System.out.print("\nEnter side2 of the triangle : ");
		temp=scan.nextInt();
		triangle.SetSide2(temp);

		System.out.print("\nEnter side3 of the triangle : ");
		temp=scan.nextInt();
		triangle.SetSide3(temp);

		//checking conditions for result printing
		if(!triangle.isTriangle())
		{
			System.out.println("\nTrinagle not valid.\n");
		}
		else
			System.out.println("\nParameter of trinagle is : "+triangle.Parameter()+"\n");

	}
}