#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct student
{
	int rno;
	char name[10];
	int mark;
};
int main()
{
	ifstream fin1,fin2;char delim;
	fin1.open("F1(3).txt");
	fin2.open("F2(3).txt");
	student s1[50],s2[50],s3[100];
	int i=0,j=0;
	while(!fin1.eof())
	{
		fin1.getline(s1[i].name,10,'|');
		fin1>>s1[i].rno>>delim;
		fin1>>s1[i].mark>>delim;
		i++;
	}
	while(!fin2.eof())
	{
		fin2.getline(s2[j].name,10,'|');//cout<<s2[j].name<<"  ";
		fin2>>s2[j].rno>>delim;
		fin2>>s2[j].mark>>delim;
		j++;
	}
	int k1=0,k2=0,k3=0;
	while(k1<i&&k2<j)
	{
		if(s1[k1].mark<s2[k2].mark)
		{
			s3[k3]=s1[k1];
			k1++;
			k3++;
		}
		else
		{
			s3[k3]=s2[k2];
			k2++;
			k3++;
		}
	}
	while(k1<i)
	{
			s3[k3]=s1[k1];
			k1++;
			k3++;
	}
	while(k2<j)
	{
			s3[k3]=s2[k2];
			k2++;
			k3++;
	}
	fin1.close();
	fin2.close();
	ofstream fout;
	fout.open("F3(3).txt");
	for(i=0;i<k3-2;i++)
	{
		fout<<s3[i].name<<"|";
		fout<<s3[i].rno<<"|";
		fout<<s3[i].mark<<"#";
		
	}
	fout.close();
}
