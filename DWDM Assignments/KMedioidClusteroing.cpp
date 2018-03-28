#include<bits/stdc++.h>
#include<ctime>
using namespace std;
struct point
{
	int x,y,cluster;
};
int noOfPoints;
vector< vector<point > > clusters;
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
	return (abs(p1.x-p2.x)+abs(p1.y-p2.y));
}
int findcost(vector<point>&data,vector<point> mean,int k )
{
	int i,j;
		int mindist=INT_MAX;
		int sum=0;
	for(i=0;i<data.size();i++)
	{
		mindist=INT_MAX;
		for(j=0;j<k;j++)
		{
			if(distance(data[i],mean[j])<mindist)
			{
				mindist=distance(data[i],mean[j]);
				data[i].cluster=j;
			}
		}
		sum=sum+mindist;
	}
	return sum;
}
void printmean(vector<point> mean,int k)
{
	cout<<"Printing Mean\n\n\n";
	for(int i=0;i<k;i++)
	{
		cout<<"( "<<mean[i].x<<"  , "<<mean[i].y<<")"<<endl;
	}
}
void reassignClusters(vector<point>&data,vector<point> mean,int k)
{
	int i,j;
	int minDistance;
	for(i=0;i<noOfPoints;i++)
	{
		minDistance=INT_MAX;
		for(j=0;j<k;j++)
		{
			if(distance(data[i],mean[j])<minDistance)
			{
				minDistance=distance(data[i],mean[j]);
				data[i].cluster=j;
				clusters[j].push_back(data[i]);
			}
		}
	}
}
void printclusters()
{
	cout<<"Printing The Good Clustres\n";
	cout<<endl<<endl;
	for(int i=0;i<clusters.size();i++)
	{
		
		for(int j=0;j<clusters[i].size();j++)
		{
			cout<<"( "<<clusters[i][j].x<<", "<<clusters[i][j].y<<")"<<" ";
		}
		cout<<endl<<endl;
	}
}
void changemean(vector<point> &mean,int k,vector<point> data)
{
	int i,j;

	int newMean,check;
	while(1)
	{
	cout<<"While\n";
	for(i=0;i<k;i++)	
	{
		check=0;
	//	int newMeanindex =rand()%clusters[i].size();
		point prevMean=mean[i];
		int prevcost=findcost(data,mean,k);
		for(j=0;j<clusters[i].size();j++)
		{	
			prevMean=mean[i];
			prevcost=findcost(data,mean,k);
			mean[i]=clusters[i][j];
			int newcost=findcost(data,mean,k);
			cout<<"newCost = "<<newcost<<endl;
			if(newcost>prevcost)
			{
				mean[i]=prevMean;
				
			}
			else
			{
				mean[i]=clusters[i][j];
				check=1;
			}
		}
		if(check==1)
		{	
		for(int j1=0;j1<noOfPoints+1;j1++)
		{
			clusters[j1].clear();
		}
		reassignClusters(data,mean,k);
		}
		printmean(mean,k);
	}
	if(check==0)
	{
		cout<<"DONE\n";
		break;
	}
	}
	printclusters();
}


int k;
void KMeans(vector<point> &data)
{
	int i,j;
	cout<<"Enter the number of clusters\n";
	cin>>k;
	for(int i=0;i<noOfPoints+1;i++)
	{
		clusters[i].clear();
	}
	vector<point> mean(k+1,{-1,-1});
	for(i=0;i<k;i++)
	{
		mean[i]=data[i];
	}
	printmean(mean,k);
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
				clusters[j].push_back(data[i]);
			}
		}
	}
	

	changemean(mean,k,data);
//	printmean(mean,k);
//	while(1)
//	{
//		bool check=false;
//		for(i=0;i<noOfPoints;i++)
//		{
//			minDistance =distance(mean[data[i].cluster],data[i]);
//			//cout<<"Min = "<<minDistance<<endl;
//			for(j=0;j<k;j++)
//			{
//				if(distance(data[i],mean[j])<minDistance)
//				{
//					check=true;
//					minDistance=distance(data[i],mean[j]);
//					data[i].cluster=j;
//					
//				}
//			}
//		//	cout<<"MinDist = "<<minDistance<<endl;	
//		}
//			for(int j=0;j<noOfPoints+1;j++)
//			{
//				clusters[j].clear();
//			}
//		for(i=0;i<noOfPoints;i++)
//		{
//			clusters[data[i].cluster].push_back(data[i]);
//		}
//		changemean(mean,k,data);
//		printmean(mean,k);
//		if(!check)
//		{
//			break;
//		}
//		printclusters();
//	}
}
int main()
{
	cout<<"Enter the Number of Points\n";
	cin>>noOfPoints;
	for(int i=0;i<noOfPoints+1;i++)
	{
		vector<point> temp;
		clusters.push_back(temp);
	}
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
