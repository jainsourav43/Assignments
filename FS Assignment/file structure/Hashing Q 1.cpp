#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;
struct student 
{
	char roll[10];
	char name[10];
	char branch[10];
};
void pack(ofstream &fout,student &s)
{
	int l1,l2,l3;
	char buffer[40];int length1=10,i;
	cout<<"Enter the name of student\n";
	cin>>s.name;
	strcpy(buffer,s.name);
	l1=strlen(s.name);
	for(i=1;i<length1-l1+1;i++)
	{
		strcat(buffer,"*");
	}
	//strcat(buffer,"|");
	cout<<"Enter the branch of student\n";
	cin>>s.branch;
	strcat(buffer,s.branch);
	l2=strlen(s.branch);
	for(i=1;i<length1-l2+1;i++)
	{
		strcat(buffer,"*");
	}
	//strcat(buffer,"|");
	cout<<"Enter the roll no. of student\n";
	cin>>s.roll;
	strcat(buffer,s.roll);
	l3=strlen(s.roll);
	for(i=1;i<length1-l3+1;i++)
	{
		strcat(buffer,"*");
	}
	//strcat(buffer,"#");
	
    int  length =strlen(buffer);
    //fout<<length;
	fout<<buffer;
}
void unpack(ifstream &fin)
{
 student s;
 char b='\0';int j,i,k=0;
 int  length;
 //fin>>length;
 //cout<<length;
 for(i=0;i<3;i++)
 {//cout<<"UNPACK\n";
   k=0;
 	char a[10];j=0;
 	fin>>b;
 	while(k<9)
 	{//cout<<"WHIle UNPACK\n";
 	    if(b!='*')
 		a[j++]=b;
		 k++;
	    fin>>b; 
	 }
	 
	 a[j]='\0';
	 if(i==0) 
	 {
	 cout<<"The name of the student\n";
	 cout<<a<<endl;
    }
    else if(i==1)
    {
    	cout<<"The branch of the student\n";
	 cout<<a<<endl;
	}
	else
	{
		cout<<"The roll no. of the student\n";
		cout<<a<<endl;
	}
 }	
}
void insert(ostream &fout,long long int  str,int offset)
{
	char buffer[15];
	fout<<str<<"|"<<offset<<"|";
}
void search(istream &fin ,long long int h,long long str)
{
	long long a,b;char ch;
	cout<<"H= "<<h<<endl;
	cout<<"Str= "<<str<<endl;
	//fin.seekg()
	fin>>a>>ch>>b>>ch;
	cout<<a<<endl<<b<<endl;
	if(a==str)
	{
		cout<<"THE roll is present at \n"<<b<<endl;
	}
	else 
	{
		cout<<"Th roll is not present\n";
	}
}
int main()
{
	ofstream fout;
	fout.open("Student_Hashed.txt");
	student s[10];
	int i,j,k,l,n;
	cout<<"Enter the No of student\n";
	cin>>n;
	long long int h,ans,offset,h1;
	ofstream fout1,fout2;int n1,n2;
	fout1.open("Hashed_File1.txt");
	cout<<"Enter the no of address space in hashfile\n";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
	fout1<<"**********";
	}
	i=0;int ch;
	for(i=0;i<n;i++)
	{
		h1=fout.tellp();
	    pack(fout,s[i]);
	    h=atoi(s[i].roll);
		offset=(h%n1)*10;
		ans=atoi(s[i].roll);
		fout1.seekp(offset,ios::beg);
		insert(fout1,ans,h1);
	}
	 fout.close();
	 long long str;ifstream fin;
	 fout1.close();
	 fin.open("Hashed_File1.txt");
	 cout<<"Enter the roll no to be searched in Hashed file\n";
	 cin>>str;
	 h=(str%n1)*10;
	 fin.seekg(h,ios::beg);
	 search(fin,h,str);
	 fin.close();
}
