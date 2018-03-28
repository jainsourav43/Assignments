#include<iostream>
#include<fstream>
#include<algorithm>
struct bank
{
	int id;
	int ac;
	char name[20];
};
using namespace std;
int main()
{
	int i,j,k,l,n,c;
    ifstream inf1, inf2;
    ofstream of1,of2;
   c=0;
    while(c!=3)
    { cout<<"Press 1 for inserting and 2 for extracting and 3 for quit\n";
    cin>>c;
    if(c==1)
    {
    	of1.open("s.txt");
    	cout<<"Enter the no. of custumer to be inserted\n";
    	cin>>n;
    	bank b[n];
    	for(i=0;i<n;i++)
    	{
    		cout<<"Enter the id of custumer\n";
    		cin>>b[i].id;
    		of1<<b[i].id<<" ";
    		cout<<"enter the ac no. of custumer\n";
    		cin>>b[i].ac;
    		of1<<b[i].ac<<" ";
    		cout<<"Enter the name of custumer\n";
    		cin>>b[i].name;
    		of1<<b[i].name;
		}
		of1.close();
    }
    else if(c==2)
    {
    	inf1.open("s.txt");
		{
			cout<<"Enter the no. of custumerv u want to extracted the data\n";
			cin>>n;
			bank ci[n];
			for(j=0;j<n;j++)
			{
				inf1>>ci[i].id;
				cout<<ci[i].id<<endl;
				inf1>>ci[i].ac;
				cout<<ci[i].ac<<endl;
				inf1>>ci[i].name;
				cout<<ci[i].name<<endl;
			}
		}
	}
	else
	{
		return 0;
	}
	}
	}
