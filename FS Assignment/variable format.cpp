#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
using namespace std;
struct hourly
{
	int no;
	int ph;
	int ts;
};
union salary
{
	int monthly;
	struct hourly h;
};
struct emp1 
{
	char eid[10];
	char ename[20];
	salary s1;
	int tag;
};
void pack(ofstream &fout)
{
	struct emp1 emp;
	int length,i,j,k;char temp[50];
	char buffer[200];
	cout<<"ENTER THE name of employee :";
	cin>>emp.ename;
	strcpy(buffer,emp.ename);strcat(buffer,"|");
	cout<<"Enter the id of employee :";
	cin>>emp.eid;
	strcat(buffer,emp.eid);strcat(buffer,"|");
	cout<<"Enter 1 for monthly salary and 2 for hourly   :";
	cin>>emp.tag;
	itoa(emp.tag,temp,10);
	strcat(buffer,temp);strcat(buffer,"|");
	if(emp.tag==1)
	{
		cout<<"Enter the Monthly sal;ary of employee :";
		cin>>emp.s1.monthly;
		itoa(emp.s1.monthly,temp,10);
		strcat(buffer,temp);strcat(buffer,"|");
	}
	else
	{
		cout<<"Enter the no. of hours :";
		cin>>emp.s1.h.no;
		itoa(emp.s1.h.no,temp,10);
		strcat(buffer,temp);strcat(buffer,"|");
		cout<<"Enter the per hour salary of employee\n ";
		cin>>emp.s1.h.ph;
		itoa(emp.s1.h.ph,temp,10);
		strcat(buffer,temp);strcat(buffer,"|");
		cout<<"ENter the total salary of hours\n";
		cin>>emp.s1.h.ts;
		itoa(emp.s1.h.ts,temp,10);
		strcat(buffer,temp);strcat(buffer,"|");
	}
	int l=strlen(buffer);
	fout<<l;
	fout<<buffer;
}
void unpack(ifstream fin)
{
	struct emp1 emp;int n;
	char b='\0',a[40],temp[50];
	int k=0,l,i=0,j=0,num;
	fin>>l;
	while(k<l)
	{   fin>>b;
	
	   if(b=='|')
	   {
		i++;
		j=0;
	   }
		if(b!='|')
		{
			a[j++]=b;
		}
		k++;
		if(i>2)
		{
			n=atoi(a);
			
		}
	}
}
int main()
{
	int i,j;
	ofstream fout;
	fout.open("EMPLOYEE.txt");int n;
	cout<<"Enter the no of employees\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
	pack(fout);
   }
	fout.close();
	return 0;
}
