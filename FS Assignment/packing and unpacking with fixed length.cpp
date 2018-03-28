#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
	char name[10];
	char branch[10];
	char rollno[10];
};
void pack(ofstream &fout)
{
	student s;i nt l1,l2,l3;
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
	cin>>s.rollno;
	strcat(buffer,s.rollno);
	l3=strlen(s.rollno);
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
int main()
{
	ofstream fout;
	ifstream fin;int i,j,k,l,m,n;
	fout.open("student.txt");
	cout<<"Enter the no. of student \n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		pack(fout);
	}
	fout.close();
	fin.open("student.txt");
	for(i=0;i<n;i++)
	{
		unpack(fin);
 }
	fin.close();
	return 0;
}
