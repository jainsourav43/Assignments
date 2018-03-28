#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
struct ch
{
	char name1[10];
	char dob[11];
};
struct  emp
{
	int empid;
	char name[10];
	int n;
	ch c[10];
};
void pack(ofstream &fout)
{
	struct emp e;int i;char temp[20];
	cout<<"Enter the employee id \n";
	cin>>e.empid;
    itoa(e.empid,temp,10);
    fout<<temp<<"|";
    cout<<"Enter the name of the employee\n";
    cin>>e.name;
    fout<<e.name<<"|";
    cout<<"Enter the no of children\n";
    cin>>e.n;
    itoa(e.n,temp,10);
    fout<<temp<<"|";
    for(i=0;i<e.n;i++)
    {
    	cout<<"Enter the name of the child\n";
    	cin>>e.c[i].name1;
    	fout<<e.c[i].name1<<"|";
    	cout<<"Enter the DOB of child\n";
    	cin>>e.c[i].dob;
    	if(i<e.n-1)
    	fout<<e.c[i].dob<<"|";
    	else
    	fout<<e.c[i].dob<<"#";
	}
}
void unpack(ifstream &fin)
{
	int i,j,k;
	emp e;char temp[20];
	fin.getline(temp,20,'|');
	k=atoi(temp);
	cout<<"The emp id of th eemployee is "<<k<<endl;
	fin.getline(e.name,20,'|');
	cout<<"The name  of the employee is   "<<e.name<<endl;
    fin.getline(temp,10,'|');
    k=atoi(temp);
    for(i=0;i<k;i++)
    {
    	fin.getline(e.c[i].name1,10,'|');
    	cout<<"The name of the child   "<<e.c[i].name1<<endl;
    	if(i<k-1)
    	fin.getline(e.c[i].dob,10,'|');
    	else
    	fin.getline(e.c[i].dob,10,'#');
    	cout<<"The DOB of the child is   "<<e.c[i].dob<<endl; 
	}
	
}
int main()
{
	int n1,i,j,k,l;
	cout<<"Entre the no of employee\n";
	cin>>n1;
	ofstream fout;
	fout.open("Employee_rp .txt");
	for(i=0;i<n1;i++)
	{
		pack(fout);
	}
	fout.close();
	ifstream fin;
	fin.open("Employee_rp .txt");
	for(i=0;i<n1;i++)
	{
		unpack(fin);
	}
	return 0;
}

