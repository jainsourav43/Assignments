#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int a[100];
	ifstream inf1;
	int n,l;
	ofstream of1,of2;
	of1.open("file1.txt");
	cout<<"Enter the numbers to be inserted <100\n";
	cin>>n;
	for(l=0;l<n;l++)
	{
		cin>>a[l];
		of1<<a[l]<<" ";
	}
	of1.close();
	inf1.open("file1.txt");
		cout<<"Enter how many numbers to be extracted\n";
		cin>>n;
		int i,j,k;int b[n];
		for(i=0;i<n;i++)
		{
			inf1>>b[i];
			cout<<b[i]<<" ";
		}
		return 0;
		
}

