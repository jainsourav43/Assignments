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
	int pid;
};
istream &operator >> (istream &stream ,person &p)
{
	char delim;//cout<<">>\n";
	stream.getline(p.name,19,'|');
	stream>>p.dob.day;
	stream>>p.dob.month;
	stream>>p.dob.year;
    stream>>p.pid;
	return stream;
}
ostream &operator << (ostream &fout,person &p)
{
	//cout<<"<<\n";
	
	fout<<p.name;
	fout<<"|";
    fout<<p.dob.day;
    fout<<" ";
    fout<<p.dob.month;
    fout<<" ";
    fout<<p.dob.year;
    fout<<" ";
    fout<<p.pid;
    //fout<<" ";
    return fout;
}

int main()
{
	ofstream fout,fout1,fout2;
	person p[10],p1[10];
	int i,j,d,m,y,a[3];
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
    cout<<"Entre the pid of person\n";
    cin>>p[i].pid;
	   fout<<p[i];
	   fout<<"  ";
	}
	fout.close();
	ifstream fin;
	
	cout<<"Enter the date of birth by which u want to enter the data\n";
	cin>>str;
	i=0;j=0;cout<<str;int l;
	l=strlen(str);
	 while(i<l)
	{ 
	 cout<<"While\n";
	    a[j]=0;
		while(str[i]!='/'&&str[i]!='\0')
		{//cout<<"2\n";
		   a[j]=a[j]*10+str[i]-48;
		   	i++;
		}
		cout<<"a[j]"<<j<<"  "<<a[j];
	    i++;
		j++;
	}
	fin.open("input.txt");
	fout1.open("output1.txt");
	fout2.open("output2.txt");
	for(i=0;i<m;i++)
	{
		fin>>p1[i];cout<<"for\n";
		cout<<"p[i].dob.day"<<p1[i].dob.day<<"  \n";
		cout<<"p[i].dob.month"<<p1[i].dob.month<<"  \n";
		cout<<"p[i].dob.year"<<p1[i].dob.year<<"  ";
		cout<<p1[i].name<<"   ";
		if(p1[i].dob.year>a[2])
		{	//fout2.open("output2.txt",ios::app);
			fout2<<p1[i];
			//fout2.close();
		}
		else
		if(p1[i].dob.year==a[2]&&p1[i].dob.month>a[1])
		{//fout2.open("output2.txt",ios::app);
			fout2<<p1[i];
			//fout.close();
		}
		else if(p1[i].dob.year==a[2]&&p1[i].dob.month==a[1]&&p1[i].dob.day>a[0])
		{//fout2.open("output2.txt",ios::app);
			fout2<<p1[i];
		//	fout2.close();
		}
		else
		{//fout1.open("output1.txt",ios::app);
			fout1<<p1[i];
		//	fout1.close();
		}
		
	}
	fin.close();
	fout1.close();
	fout2.close();
	}
