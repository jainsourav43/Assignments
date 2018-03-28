#include <iostream>
#include<bits/stdc++.h>
#define NO_OF_Attributes 3
using namespace std;

int main()
{
	ifstream fin;
	fin.open("DataCleaning.txt");
	ofstream fout;
	string s;
	int mean1=0,mean2=0;
	int n1=0,n2=0;
	int count=0;
	getline(fin,s);
	while(!fin.eof())
	{
		s="";
		getline(fin,s);
		cout<<"S= "<<s<<endl;
		int i=0;
		count=0;
		for(i=0;i<s.length();)
		{
			count++;
			bool present=true;
			if(s[i]==' ')
			{
				present=false;
			
			}
			int num=0;
			bool isnum=false;
			if(s[i]<=57&&s[i]>=48)
			{
				isnum=true;
				while(s[i]!=' ')
				{
					
					if(s[i]<=57&&s[i]>=48)
					{
						num=num*10+(s[i]-'0');
					}
					i++;
				}
			}
			else
			{
				while(s[i]!=' ')
				{
					i++;	
				}
			}
			if(isnum)
			{
			cout<<"Count ="<<count<<endl;
			cout<<"Num= "<<num<<endl;
			}
			if(count==2&&present==true)
			{
				mean1=mean1+num;
				n1++;
			}
			else if(count==3&&present==true)
			{
				mean2=mean2+num;
				n2++;
			}
			i++;
			if(present==false) i++;
		}
		
		
		
	}
	mean1=mean1/n1;
	mean2=mean2/n2;
	cout<<"m1,m2 ="<<mean1<<"  "<<mean2<<endl;
	fin.close();
	fin.open("DataCleaning.txt");
	fout.open("DataCleaningOutput.txt");
	getline(fin,s);
	fout<<s<<endl;
	while(!fin.eof())
	{
		string s;
		getline(fin,s);
		cout<<"S= "<<s<<endl;
		int i=0;
		count=0;
		for(i=0;i<s.length();)
		{
			count++;
			bool present=true;
			if(s[i]==' ')
			{
				present=false;
			
			}
			int num=0;
			bool isnum=false;
			if(s[i]<=57&&s[i]>=48)
			{
				isnum=true;
				while(s[i]!=' ')
				{
					fout<<s[i];
					i++;	
				}
				
			}
			else
			{
				while(s[i]!=' ')
				{
					fout<<s[i];
					i++;	
				}
			}
			if(!present)
			{
			
					if(count==2)
					{
						fout<<mean1;
					}
					else if(count==3)
					{
						fout<<mean2;
					}
					else
					{
						fout<<"UNKNOWN";
					}
			}
			i++;
			fout<<' ';
			if(present==false) i++;
	}
			if(count<4)
			{
				fout<<"Unknown";
			}
		fout<<endl;
}

	fin.close();
	fout.close();
	
}
