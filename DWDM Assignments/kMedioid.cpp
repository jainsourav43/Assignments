#include<bits/stdc++.h>
#include<ctime>
using namespace std;
struct point
{
	int x,y,cluster;
};
int noOfPoints;
void generateRandomPoint(vector<point> &data)
{
	int i;
	srand(time(NULL));
	for(i=0;i<noOfPoints;i++)
	{
		point temp;
		temp.x=rand()%100;
		temp.y=rand()%100;
		temp.cluster=-1;
		data.push_back(temp);
	}
}
int distance(point p1,point p2)
{
	return (pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
void changemean(vector<point> &mean,int k,vector<point> &data)
{
	int i,j;
	for(i=0;i<k;i++)	
	{
		point newpoint;
		newpoint.x=0;
		newpoint.y=0;
		int count=0;
		for(j=0;j<noOfPoints;j++)
		{
			if(data[j].cluster==i)
			{
				newpoint.x=newpoint.x+data[j].x;
				newpoint.y=newpoint.y+data[j].y;
				count++;
			}
			
		}
		if(count!=0)
		{
			mean[i].x=newpoint.x/count;
			mean[i].y=newpoint.y/count;
		}
	}
}
void printmean(vector<point> mean,int k)

{
	cout<<"Printing Mean\n\n\n";
	for(int i=0;i<k;i++)
	{
		cout<<"( "<<mean[i].x<<"  , "<<mean[i].y<<")"<<endl;
	}
}
int k;
void KMeans(vector<point> &data)
{
	int i,j;
	cout<<"Enter the number of clusters\n";
	cin>>k;
	vector<point> mean(k+1,{-1,-1});
	for(i=0;i<k;i++)
	{
		mean[i]=data[i];
	}
//	printmean(mean,k);
	double minDistance=INT_MAX;
	for(i=0;i<noOfPoints;i++)
	{
		minDistance=INT_MAX;
		for(j=0;j<k;j++)
		{
			if(distance(data[i],mean[j])<minDistance)
			{
				minDistance=distance(data[i],mean[j]);
				data[i].cluster=j;
			}
		}
	}
	

	changemean(mean,k,data);
//	printmean(mean,k);
	while(1)
	{
		bool check=false;
		for(i=0;i<noOfPoints;i++)
		{
			minDistance =distance(mean[data[i].cluster],data[i]);
	//		cout<<"Min = "<<minDistance<<endl;
			for(j=0;j<k;j++)
			{
				if(distance(data[i],mean[j])<minDistance)
				{
					check=true;
					minDistance=distance(data[i],mean[j]);
					data[i].cluster=j;
				}
			}
		//	cout<<"MinDist = "<<minDistance<<endl;	
		}
		changemean(mean,k,data);
//		printmean(mean,k);
		if(!check)
		{
			break;
		}
	}
}
int main()
{
	cout<<"Enter the Number of Points\n";
	cin>>noOfPoints;
	vector<point> data;
	generateRandomPoint(data);
	KMeans(data);
	int i,j;
	
	for(i=0;i<k;i++)	
	{
		cout<<"Points belonging to Cluster  "<<i<<" \n\n\n";
		for(j=0;j<noOfPoints;j++)
		{
			if(data[j].cluster==i)
			{
				cout<<"( "<<data[j].x<<" , "<<data[j].y<<" ) ";
			}
		}
		cout<<endl;
	}
	
}
