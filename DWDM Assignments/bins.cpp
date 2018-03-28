#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bin_by_mean(vector <vector< int> > bins)
{
	int i,j;
	for(i=0;i<bins.size();i++)
	{
		int mean=0;
		for(j=0;j<bins[i].size();j++)
		{
			mean=mean+bins[i][j];
		}
		for(j=0;j<bins[i].size();j++)
		{
			bins[i][j]=mean/bins[i].size();
		}
	}
	for(i=0;i<bins.size();i++)
	{
		for(j=0;j<bins[i].size();j++)
		{
			cout<<bins[i][j]<<" ";
		}
		cout<<endl;
	}
}
void bin_by_median(vector <vector< int> > bins)
{
	int i,j;
	for(i=0;i<bins.size();i++)
	{
		int median=bins[i][bins[i].size()/2];
		for(j=0;j<bins[i].size();j++)
		{
			bins[i][j]=median;
		}
	}
	for(i=0;i<bins.size();i++)
	{
		for(j=0;j<bins[i].size();j++)
		{
			cout<<bins[i][j]<<" ";
		}
		cout<<endl;
	}
}
void bin_by_boundary(vector <vector< int> > bins)
{
	int i,j;
	for(i=0;i<bins.size();i++)
	{
		for(j=1;j<bins[i].size()-1;j++)
		{
			if(j<bins[i].size()-j-1)
			{
				bins[i][j]=bins[i][0];
			}
			else
			{
				bins[i][j]=bins[i][bins[i].size()-1];
			}
		}
	}
	for(i=0;i<bins.size();i++)
	{
		for(j=0;j<bins[i].size();j++)
		{
			cout<<bins[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	vector<int> arr;
	int i,n;
	cout<<"Enter The Number of Element in  Array\n";
	cin>>n;
	cout<<"Enter Array \n";
	for(i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	
	
	
	int j;
	vector< vector<int > >bins;
	int Size;
	cout<<"Enter the Size of Bin \n";
	cin>>Size;
	if(n%Size)
	{
		cout<<"Equal Sized Bins Can'y Be Created Error Terminating \n";
		return 0;
	}
	for(i=0;i<arr.size();i+=Size)
	{
		vector<int> temp;
		for(j=i;j<i+Size;j++)
		{
			temp.push_back(arr[j]);	
		}
		cout<<endl<<endl;
		bins.push_back(temp);
	}
	
	
	
	
	for(i=0;i<bins.size();i++)
	{
		for(j=0;j<bins[i].size();j++)
		{
			cout<<bins[i][j]<<" ";
		}
		cout<<endl;
	}
	char choice;
	cout<<"Enter 1 for mean 2 for median 3 for Boundary\n";
	cin>>choice;
	
	switch(choice)
	{
	case  '1':
	cout<<"BINS BY MEAN\n";
	bin_by_mean(bins);
	cout<<endl;
	break;
	case  '3':
		cout<<"BINS BY BOUNDARY\n";

	bin_by_boundary(bins);
	cout<<endl;
	break;
	case '2':
		cout<<"BINS BY MEDIAN\n";

	bin_by_median(bins);
	break;
	default:
		cout<<"Wrong Choice \n";
}
}
