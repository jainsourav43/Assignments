#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
struct hourly
{
	int ph;
	int ts;
	int nh;
};
union salary
{
	int monthly;
	struct hourly h;
};
struct  emp
{
	int empid;
	char name[10];
	int tag;
	salary s;
};
void pack(ofstream &fout,int i)
{
	struct  emp e;char temp[20];
	cout<<"Enter the emp id of   "<<i+1<< " employee\n";
	cin>>e.empid;
	itoa(e.empid,temp,10);
	fout<<temp;
	fout<<"|";
	cout<<"Enter the name of employee\n";
	cin>>e.name;
	fout<<e.name;
	fout<<"|";
	cout<<"Enter 1 for monthly and two for hourly salary \n";
	cin>>e.tag;
	itoa(e.tag,temp,10);
	fout<<temp<<"|";
	if(e.tag==1)
	{
		cout<<"Enter the monthly salary \n";
		cin>>e.s.monthly;
		itoa(e.s.monthly,temp,10);
		fout<<temp;
		fout<<"#";
	}
	else if (e.tag==2)
	{
		cout<<"Entrer the per hour salary \n";
		cin>>e.s.h.ph;
		itoa(e.s.h.ph,temp,10);
		fout<<temp;
		fout<<"|";
		cout<<"Enter the total salary\n";
		cin>>e.s.h.ts;
		itoa(e.s.h.ts,temp,10);
		fout<<temp;
		fout<<"|";
		cout<<"Enter the no of hour\n";
		cin>>e.s.h.nh;
		itoa(e.s.h.nh,temp,10);
		fout<<temp;
		fout<<"#";
	}
	
}
void unpack(ifstream &fin)
{
	struct emp e;
	char temp[20];int k,k1;
	fin.getline(temp,20,'|');
	 k=atoi(temp);
	cout<<"EID of the employee is   "<<k<<endl;
	fin.getline(e.name,10,'|');
	cout<<"Name of the employee is   "<<e.name<<""<<endl;
	fin.getline(temp,20,'|');
	k=atoi(temp);
	if(k==1)
	{
		fin.getline(temp,20,'#');
		k1=atoi(temp);
		cout<<"The onthly salary of the employee is "<<k1<<"\n ";
	}
	else if (k==2)
	{
		fin.getline(temp,20,'|');
		k1=atoi(temp);
		cout<<"The per hour salary of the employee is "<<k1<<endl;
		fin.getline(temp,20,'|');
		k1=atoi(temp);
		cout<<" the total salary is "<<k1<<" \n";
		fin.getline(temp,20,'#');
		k1=atoi(temp);
		cout<<"The no of hours for the employee is "<<k1<<"  \n";
	}
}
int main()
{
  int i,j,k,n,m;
  cout<<"Enter the no. of employee\n";
  cin>>n;
  ofstream fout;
  fout.open("employee.txt");
  for(i=0;i<n;i++)
  {
  	pack(fout,i);
  }
  fout.close();
  ifstream fin;
  fin.open("employee.txt");
  for(i=0;i<n;i++)
  {
  	unpack(fin);
  }
  fin.close();
  	return 0;
}
