#include<bits/stdc++.h>
using namespace std;
void mergefiles()
{
		fstream fout1,fout2,fout3,fout4;
		int k1=1,count1=count2=0;
		fout1.open("a1.txt");
		fout2.open("a2.txt");
		while(1)
		{
	    while(k1!=-2)
		{
			fout1>>k1;
			if(k1!=-1&&np<p)
			{
			a[count1]=k1;
			count1++;
		    }
		}
		k1=1;
	    while(k1!=-2)
	    {
	    	fout2>>k1;
	    	if(k1!=-1)
	    	{
	    	b[count2]=k1;
	    	count2++;
	    	}
	    }
		fout3.open("b1.txt");
		fout4.open("b2.txt");
		p1=0;i1=0,i2=0;
		while(count1>=0&&count2>=0)
		{
			if(a[i1]>b[i2])
			{
			 fout3<<b[i2]<<" ";
			 i2++;	
			}
			else
			{
			 fout3<<a[i1]<<" ";
			 i1++;	
			}
		}
	}
}
int main()
{
	int k,k1,k2,k3,count1=0,count2=0,p;
	ifstream fout;
	fout.open("inputfile.txt");
	cout<<"\nEnter the size of the partition\n" ;
	cin>>p;
	fstream fout1,fout2,fout3,fout4;char ch;
	int n=8;
	int a[4],b[4],c[4],i=0;
	fout1.open("a1.txt");
	fout2.open("a2.txt");
	fout3.open("b1.txt");
	fout4.open("b2.txt");
	while(!fout.eof())
	{
		if(i%2==0)
		{	
			fout>>k1;
			a[count1]=k1;
			count1++;
			if(count1>=4)
			{
				sort(a,a+count1);
				for(int j=0;j<count1;j++)
				{
					fout1<<a[j]<<" ";
				}
			fout1<<-1<<" ";
			count1=0;
		    }
		}
		else
		{
		
			
			fout>>k1;
			b[count2]=k1;
			count2++;
			if(count2>=4)
			{
				sort(b,b+count2);
				for(int j=0;j<count2;j++)
				{
					fout2<<b[j]<<" ";
				}
				fout2<<-1<<" ";
				count2=0;
			}
		}
		i++;
	}
	fout1<<-2<" ";
	fout2<<-2<<" ";
	count1=0;count2=0;
	while(p<n)
	{
	
		
		
	}
fout.close();
fout1.close();
fout2.close();
}
