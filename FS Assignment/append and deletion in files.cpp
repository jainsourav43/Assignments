#include<iostream>
#include<fstream>
using namespace std;
struct st{
char ro[10];
	char fname[10];
	char lname[10];
};
int main()
{
	ifstream fin,fin1;
	ofstream fout,fout1;
	st s[10],s1[10],s2[10];
	int i,j,k;
	fout.open("student.txt");
	for(i=0;i<5;i++)
	{
		cout<<"Enter the first ,last name and roll respec.\n"<<i+1<<endl;
		cin>>s[i].fname;
		fout<<s[i].fname<<" ";
		cin>>s[i].lname;
		fout<<s[i].lname<<" ";
		cin>>s[i].ro;
		fout<<s[i].ro<<" ";
		fout<<endl;
	}
	fout.close();
	fout.open("student.txt",ios::app);
	cout<<"Enter the details of the student u want to append\n";
	cout<<"Enter the first ,last name and roll respec.\n";
	cin>>s[5].fname;
	fout<<s[5].fname<<" ";
	cin>>s[5].lname;
	fout<<s[5].lname<<"  ";
	cin>>s[5].ro;
	fout<<s[5].ro<<"  ";
	fout.close();
	fin.open("student.txt",ios::in);
	fout1.open("dupli.txt");
	for(i=0;i<6;i++)
	{
			fin>>s1[i].fname;
			fin>>s1[i].lname;
			fin>>s1[i].ro;
		if(i!=2)
		{
			   fout1<<s1[i].fname<<" ";
				fout1<<s1[i].lname<<" ";
				fout1<<s1[i].ro<<" ";
		}
	}
	fin.close();
	fout1.close();
	fin1.open("dupli.txt");
	fout.open("student.txt");
	for(i=0;i<5;i++)
	{
	
		fin1>>s2[i].fname;
		fout<<s2[i].fname<<" ";
		cout<<s2[i].fname<<endl;
		fin1>>s2[i].lname;
		fout<<s2[i].lname<<" ";
		cout<<s2[i].lname<<endl;
		fin1>>s2[i].ro;
		fout<<s2[i].ro<<" ";
		cout<<s2[i].ro<<endl;
		fout<<endl;

	}
	fin1.close();fout.close();
	remove ("dupli.txt");
		return 0;
	}
