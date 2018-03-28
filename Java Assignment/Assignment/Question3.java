//Class Distance 
class Distance{
	
	double []dist=new double[30]; 
	int count;// Declaring Points 
	double [][] d={{-1,2,3},{-1,-1,-1},{5,2,1},{3,.5,9},{3.5,2,-1.5},{8,1.5,-3},{-4,-4,2},{-7,4,.5}};
	void findDistances()
	{
		
		int i=0,j=0;
		count=0;
// Calculating Distance 
		for(i=0;i<8;i++)
		{
			for(j=i+1;j<8;j++)
			{
			dist[count]=Math.abs(Math.sqrt((d[i][0]-d[j][0])*(d[i][0]-d[j][0])+(d[i][1]-d[j][1])*(d[i][1]-d[j][1])+(d[i][2]-d[j][2])*(d[i][2]-d[j][2])));
			count++;
			}
			
		}

	}
// Finding Minimun
	double findmin()
	{
		double min=100000;
		for(int i=0;i<count;i++)
		{	
			if(min>dist[i])
			{
				min=dist[i];
			}
		}
// Returning Minimum
		return min;
	}
	
}
public class Question3 {
	public static void main(String args[])
	{
		Distance obj =new Distance();
		obj.findDistances();
		double ans=obj.findmin();
		System.out.println("The MIn Distance is :");
		System.out.printf("%.2f",ans);
	}

}
