#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	int rno;
	char name[10];
	int *mark;
};
int main()
{
	ifstream fin;
	student s[20],temp,s2[20];
	fin.open("F1(2).txt");
	int i=0,j,n,k,l;char delim;
	while(!fin.eof())
	{
	  fin.getline(s[i].name,10,'|');
	  fin>>s[i].rno>>delim;	
	  s[i].mark=new int[1];
	  fin>>s[i].mark[0]>>delim;
	  i++;
	}i=i-1;
	n=i;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(s[j].rno>s[j+1].rno)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	int h;
	ofstream fout;
	fout.open("F2(2).txt");i=0;
	while(i<n)
	{
		fout<<s[i].name<<"|";
		fout<<s[i].rno<<"|";
		k=s[i].rno;
		while(i<n&&k==s[i].rno)
		{
			if(k==s[i+1].rno)
			fout<<s[i].mark[0]<<"|";
			else
			{
					fout<<s[i].mark[0]<<"#";
			}
			
			i++;
		}
	}
	fout.close();
	return 0;
}
