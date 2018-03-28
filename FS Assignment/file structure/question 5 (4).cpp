#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
struct student
{
	char rno[10];
	char name[10];
	char  mark[10];
};
int main()
{
	ifstream fin1,fin2;char delim;
	fin1.open("F1(4).txt");int d;
	fin2.open("F2(4).txt");char b,a[10];
	student s1[50],s2[50],s3[100];
	int i=0,j=0;
	while(!fin1.eof())
	{
		//fin1.getline(s1[i].name,10,'|');
		for(j=0;j<3;j++)
		{
		d=0;
		for(int g=0;g<10;g++)
		{
		    fin1>>b;
			if(b!='*')
			{
				a[d++]=b;
			}
		
		}
		a[d]='\0';
		if(j==0)
		{
	
		strcpy(s1[i].name,a);cout<<"S1 name  "<<s1[i].name<< "\n"<<"III  = "<<i ;}
		else if(j==1)
		{

	    strcpy(s1[i].rno,a);cout<<"s1 roll "<<s1[i].rno<<"  \n"<<"III  = "<<i;}
	    else if(j==2)
	    {

	    strcpy(s1[i].mark,a);cout<<"S1 marks  "<<s1[i].mark<<" \n ";}
		
	}
	i++;
}i--;
int i1=0;
	while(!fin2.eof())
	{
		//fin2.getline(s2[j].name,10,'|');//cout<<s2[j].name<<"  ";
		/*fin2>>b;d=0;
		while(b!='|')
		{
			if(b!='*')
			{
				a[d++]=b;
			}
			fin2>>b;
		}
		a[d]='\0';*/
		fin2.getline(s2[i1].name,10,'|');cout<<"S1 name  "<<s2[i1].name<<" \n";
		fin2.getline(s2[i1].rno,10,'|');cout<<"s1 roll "<<s2[i1].rno<<"  \n";
		fin2.getline(s2[i1].mark,10,'#');cout<<"S1 marks  "<<s2[i1].mark<<" \n ";
		i1++;
	}i1--;
	int k1=0,k2=0,k3=0;int m1,m2;cout<<"  marks  ="<<s1[0].mark<<"  ";
	while(k1<i&&k2<i1)
	{
		m1=atoi(s1[k1].mark);cout<<"M1 ="<<m1<<endl;
		m2=atoi(s2[k2].mark);cout<<"M2 ="<<m2<<endl;
		if(m1<m2)
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
	while(k2<i1)
	{
			s3[k3]=s2[k2];
			k2++;
			k3++;
	}
	fin1.close();
	fin2.close();
	ofstream fout;
	fout.open("F3(4).txt");
	for(i=0;i<k3-1;i++)
	{cout<<"I   "<<i<<endl;
		fout<<s3[i].name<<"|";
		fout<<s3[i].rno<<"|";
		fout<<s3[i].mark<<"#";
		
	}
	fout.close();
}
