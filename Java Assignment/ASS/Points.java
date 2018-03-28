//3. Points 

//main class
class PointClass
{
	float x,y,z;

	//constructors

	public PointClass()
	{
		this.x=this.y=this.z=0;
	}

	public PointClass(float x,float y,float z)
	{
		this.x=x;
		this.y=y;
		this.z=z;
	}

	//get functions

	public float GetX()
	{
		return this.x;
	}

	public float GetY()
	{
		return this.y;
	}

	public float GetZ()
	{
		return this.z;
	}

	//set fucntions

	public void SetX(float x)
	{
		this.x=x;
	}

	public void SetY(float y)
	{
		this.y=y;
	}

	public void SetZ(float z)
	{
		this.z=z;
	}

	public void SetPoint(float x,float y,float z)
	{
		this.x=x;
		this.y=y;
		this.z=z;
	}

	//function to find distance between two given points
	public static float distance(PointClass p1,PointClass p2)
	{
		return (float)(Math.sqrt((p1.GetX()-p2.GetX())*(p1.GetX()-p2.GetX()) +(p1.GetY()-p2.GetY())*(p1.GetY()-p2.GetY()) + (p1.GetZ()-p2.GetZ())*(p1.GetZ()-p2.GetZ())));
	}
}

class Points
{
	public static void main(String[] args)
	{

		PointClass point1=new PointClass();
		PointClass point2=new PointClass();

		//defining points as given in question

		float[][] points={{-1f,2f,3f},{-1f,-1f,-1f},{5f,2f,1f},{3f,0.5f,9f},{3.5f,2f,-1.5f},{8f,1.5f,-3f},{-4f,4f,2f},{-7f,4f,-0.5f}};
		float temp=-1;
		int p1=0,p2=0;

		//finding minimum distance between defined points and points by brute force method (calculating distance between all pairs possible and then choosing required pair)

		for(int i=0;i<8;i++)
		{
			point1.SetPoint(points[i][0],points[i][1],points[i][2]);
			for(int j=i+1;j<8;j++)
			{
				point2.SetPoint(points[j][0],points[j][1],points[j][2]);
				float k=PointClass.distance(point1,point2);
				/*
				System.out.print("\n\nDistance between ");
				System.out.print(" ("+points[i][0]+" , "+points[i][1]+" , "+points[i][2]+" ) and ");
				System.out.print(" ( "+points[j][0]+" , "+ points[j][1]+" , "+points[j][2]+" ) ");
				System.out.print(" is = "+k+"\n");
				*/
				if(temp==-1)
				{
					temp=k;
					p1=i;
					p2=j;
				}
				else if(temp>k)
				{
					temp=k;
					p1=i;
					p2=j;
				}
			}
		}

		//printing points and minimum distance

		System.out.print("\nPoints are ("+points[p1][0]+" , "+points[p1][1]+" , "+points[p1][2]+" ) and ");
		System.out.print(" ( "+points[p2][0]+" , "+ points[p2][1]+" , "+points[p2][2]+" )\n");
		System.out.printf("\nDistance is %.3f\n",temp);
	}

}