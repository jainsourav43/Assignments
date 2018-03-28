#include<iostream>
#define ll  long long 
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;
struct student 
{
	char roll[10];
	char name[10];
	char branch[10];
};
int main()
{
	int n,i,j;
	cout<<"Enter the no of students\n";
	cin>>n;
	ll  roll,n1,in,temp1,temp2;
	cout<<"Enter the no of address space\n";
	cin>>n1;
	ll a[n1][2];
	 for(i=0;i<n1;i++)
   {
   	a[i][0]=-1;a[i][1]=-1;
   }int m;
	for(m=0;m<n;m++)
	{
		cout<<"Enter the roll no\n";
		cin>>roll;
		in=roll%n1;
		if(a[in][0]==-1)
		{
			a[in][0]=roll;
			a[in][1]=-1;
		}
		else if(a[in][0]%n1==roll%n1)
		{ cout<<"else if \n";
			j=in;
			while(a[j][0]!=-1)
			{
			    if(a[j][1]==-1)
				(j++)%n1;
				else
				j=(j+a[j][1])%n1;
				if(a[j][0]==-1)
				{    
				    int ans;
					for(int l=0;l<n1;l++)
					{
						if(a[l][0]%n1==in)
						ans=l;
					}
					a[ans][1]=j;
					a[j][0]=roll;
					a[j][1]=-1;
				
					break;
				}
			}
		}
		else
		{
			cout<<"else \n";
			cout<<"IN = "<<in<<endl;
			temp1=a[in][0];
			temp2=a[in][1];
			
			a[in][0]=roll;
			a[in][1]=-1;
		    j=in;
			while(a[j][0]!=-1)
			{
				if(a[j][1]==-1)
				(j++)%n1;
				else
				j=(j+a[j][1])%n1;
				if(a[j][0]==-1)
				{
					cout<<"IN\n";
					int ans;
					for(int l=0;l<n1;l++)
					{
						if(a[l][1]%n1==in)
						ans=l;
					}
					cout<<"ans ="<<ans<<endl;
					cout<<"J  = "<<j<<endl;
					a[ans][1]=j;
					cout<<"J = "<<j<<endl;
					a[j][0]=temp1;
					a[j][1]=-1;
					break;
				}
			
			}
//			for(i=0;i<in;i++)
//			{
//				if(a[i][0]%n1==temp1%n1)
//				{
//					continue;
//				}
//			}
//			a[i][1]=j;
		}
//			for(i=0;i<n1;i++)
//	{
//	cout<<a[i][0]<<"  "<<a[i][1]<<endl;
//	}
	}
	for(i=0;i<n1;i++)
	{
	cout<<a[i][0]<<"  "<<a[i][1]<<endl;
	}
	return 0;
}
