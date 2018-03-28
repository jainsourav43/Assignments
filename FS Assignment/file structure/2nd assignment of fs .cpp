#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
using namespace std;
struct DOB
{
	int day;
	int month;
	int year;
};
struct person
{
	char name[10];
	DOB dob;
	int age;
};
istream &operator >> (istream &stream ,person &p)
{
	char delim;//cout<<">>\n";
	stream.getline(p.name,19,'/');
	stream>>p.age;stream>>delim;
	stream>>p.dob.day;stream>>delim;
	stream>>p.dob.month;stream>>delim;
	stream>>p.dob.year;stream>>delim;
    
	return stream;
}
ostream &operator << (ostream &fout,person &p)
{
	//cout<<"<<\n";
	
	fout<<p.name;
	fout<<"/";
	fout<<p.age;
    fout<<"/";
    fout<<p.dob.day;
    fout<<"-";
    fout<<p.dob.month;
    fout<<"-";
    fout<<p.dob.year;
    fout<<"#";
    
    return fout;
}

int main()
{
	ofstream fout,fout1,fout2;
	person p[10],p1[10];
	int i,j,d,m,y,a[3];struct person temp;
	char str[12];cout<<"Enter the no of persons \n";
	cin>>m;
	fout.open("input.txt");
	for(i=0;i<m;i++)
	{
	cout<<"Enter the name of the person\n";
	cin>>p[i].name;
	cout<<"Enter the date of  dob of the person\n";
    cin>>p[i].dob.day;
     cout<<"Enter the month of  dob of the person\n";
    cin>>p[i].dob.month;
    cout<<"Enter the year of  dob of the person\n";
    cin>>p[i].dob.year;
    cout<<"Entre the age of person\n";
    cin>>p[i].age;
	}
	int u;
for(i=0;i<m;i++)
{
	fout<<p[i];
}
fout.close();
ifstream fin;
fin.open("input.txt");
for(i=0;i<m;i++)
{
	fin>>p1[i];
}
for(i=0;i<m-1;i++)
{
	for(j=i;j<m-1-i;j++)
	{
		if(p1[j].dob.year>p1[j+1].dob.year)
		{
			 temp=p1[j];
			p1[j]=p1[j+1];
			p1[j+1]=temp;
		}
	}
}
fin.close();
fout.open("input.txt");
for(i=0;i<m;i++)
{
	fout<<p1[i];
}
fout.close();
	ifstream fin1;
	fin1.open("input.txt");
	fout1.open("output3.txt");int k=0;
	for(i=0;i<m;i++)
	{
	
		//if(p1[i].dob.year==p1[i+1].dob.year&&k==0)
		//{
	     	u=fin1.tellg();
			fin1>>p1[i];
			fout1<<p1[i].dob.year<<"-";
		   fout1<<u<<"\n";k=1;
	//}
	/*else
	{
		u=fin1.tellg();k=0;
			fin1>>p1[i];
			fout1<<p1[i].dob.year<<"-";
		
		fout1<<u<<"\n";k=1;
	}*/
	}
	fin1.close();
	fout.close();
return 0;
	}
