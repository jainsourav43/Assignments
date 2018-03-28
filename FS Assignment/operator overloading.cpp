#include<bits/stdc++.h>
using namespace std;
struct st{
    char ro[10];
	char fname[10];
	char lname[10];
};
ostream & operator <<(ostream &stream ,st &s)
{int i;

	stream<<s.fname<<"|";
	stream<<s.lname<<"|";
	stream<<s.ro<<"|";
	return stream;
}
istream & operator >>(istream &stream1,st &s)
{
	stream1.getline(s.fname,10,'|');
	stream1.getline(s.lname,10,'|');
	stream1.getline(s.ro,10,'|');
	return stream1;
}
int main()
{
	ifstream fin,fin1;
	ofstream fout,fout1;
	st s[10],s1[10],s2[10],si;
	int i,j,k;
	fout.open("student.txt");
	for(i=0;i<1;i++)
	{
		cout<<"Enter the first ,last name and roll respec.\n"<<i+1<<endl;
		cin>>si.fname;
		cin>>si.lname;
		cin>>si.ro;
	    fout<<si;
	    cout<<si;
	
}
	fout.close();
	cout<<"Enter the details of the student u want to append\n";
	fout.open("student.txt",ios::app);
	cin>>si.fname;
	cin>>si.lname;
    cin>>si.ro;
    fout<<si;
    cout<<si;
    fout.close();
	fin.open("student.txt");int t=5;
	fout1.open("dupli.txt");i=0;
while(fin>>si)
{

	if(strcmp(si.fname,"sourav"))
	fout1<<si;
		i++;
}
fout1.close();
remove("student.txt");
rename("dupli.txt","student.txt");
	return 0;
}
