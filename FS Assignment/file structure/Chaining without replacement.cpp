#include<iostream>
#define ll  long long 
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no of students\n";
	cin>>n;
	ll  roll,n1;
	cout<<"Enter the no of address space\n";
	cin>>n1;
   int in,j,i;int a[n1][2];
   for(i=0;i<n1;i++)
   {
   	a[i][0]=-1;a[i][1]=-1;
   }
	for(i=0;i<n;i++)
	{
		cout<<"Enter the roll no\n";
		cin>>roll;
		in=roll%n1;
		cout<<"in"<<in<<endl;
		cout<<"a[0][0] = "<<a[0][0]<<endl;
		if(a[in][0]==-1)
		{
			a[in][0]=roll;
			a[in][1]=-1;
		}
		else
		{
			j=in;
			cout<<" a[1]  "<<a[1][0]<<endl;
			if(a[j][0]%n1==roll%n1)
			{
			while(a[j][0]!=-1)
			{
				if(a[j][1]==-1)
				(j++)%n1;
				else
				j=(j+a[j][1])%n1;
				if(a[j][0]==-1)
				{int ans;
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
				//cout<<"J  = "<<j<<endl;
			}
		  }
		  else
		  { //cout<<"seconmd else\n";
		  	j=in;//cout<<"a = ="<<a[j][0]<<endl;
		  	while(a[j][0]!=-1)
		  	{
		  		j++%n1;//cout<<"j ="<<j<<endl;
		  		if(a[j][0]==-1)
		  		{
		  				int ans;bool check=false;
					for(int l=0;l<n1;l++)
					{
						if(a[l][0]%n1==roll%n1)
						{

						ans=l;
						check=true;
					}
						
					}
					if(check==true)
				a[ans][1]=j;
		  		a[j][0]=roll;
		  		a[j][1]=-1;
		  		break;
		     	}  
		   }
		  }
		}
//	for(int i1=0;i1<n1;i1++)
//	{
//		cout<<a[i1][0]<<"  "<<a[i1][1]<<endl;
//	}
	}
	for(i=0;i<n1;i++)
	{
		cout<<a[i][0]<<"  "<<a[i][1]<<endl;
	}
}
