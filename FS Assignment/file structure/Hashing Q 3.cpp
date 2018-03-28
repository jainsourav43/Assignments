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
int n1;
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
    cout<<"Buffer  = "<<buffer<<endl;
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
void insertq(fstream &fout,long long int  str,int offset)
{
		int i=0;char ch;
	fout>>ch;	cout<<"CH1  = "<<ch<<endl;
	if(ch=='*')
	{
	fout.seekp(-1,ios ::cur);
	fout<<str<<"|"<<offset<<"|";
    }
    else
    {
    	i++;
    	fout.seekp((10*i-1)%(n1*14),ios::cur);
    	fout>>ch;cout<<"CH1  = "<<ch<<endl;
    	while(ch!='*')
    	{
    		fout.seekp((10*i-1)%(n1*14),ios :: cur);
    		fout>>ch;cout<<"CH1  = "<<ch<<endl;
    		if(ch=='#')
    		{
    			fout.seekp(ios::beg,ios ::cur);
			}
    		
		}
		fout<<str<<"|"<<offset<<"|";
		
	}
}
void insert(fstream &fout,long long int  str,int offset)
{
	char ch;int i=1;
	fout>>ch;
	if(ch=='*')
	{
	fout.seekp(-1,ios ::cur);
	fout<<str<<"|"<<offset<<"|";
    }
    else
    {
    	fout.seekp((14*i*i-1)%(n1*14),ios::cur);
    	cin>>ch;
    	while(ch=='*')
    	{
    		fout.seekp((14*i*i-1)%(n1*14),ios :: cur);
    		cin>>ch;
    		if(ch=='#')
    		{
    			fout.seekp(ios::beg,ios ::cur);
			}
    		
		}
		fout<<str<<"|"<<offset<<"|";
		
	}
}
void search(istream &fin ,long long int h,long long str)
{
	long long a,b;char ch;int i=0;
//	cout<<"H= "<<h<<endl;
//	cout<<"Str= "<<str<<endl;
	fin>>a>>ch>>b>>ch;
//	cout<<a<<endl<<b<<endl;

	if(a==str)
	{
		cout<<"THE roll is present at \n"<<b<<endl;
	}
	else 
	{i++;
		while(!fin.eof()&&a!=str)
		{
			fin.seekg((14*i*i-1)%(n1*14),ios ::cur);
			fin>>a>>ch>>b>>ch;
			if(a==str)
			{
				cout<<"THE roll is present at \n"<<b<<endl;
				return ;
			}
			i++;
		}
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
	fstream fout1,fout2;int n2;
	fout1.open("Hashed_File2.txt",ios ::in|ios ::out);
	cout<<"Enter the no of address space in hashfile\n";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
	fout1<<"**************";
	}
	fout1<<"#";
	i=0;int ch;
	for(i=0;i<n;i++)
	{
		h1=fout.tellp();
	    pack(fout,s[i]);
	    cout<<"Back from pack\n";
	    h=atoi(s[i].roll);
		offset=(h%n1)*14;
		cout<<"Offset = "<<offset<<endl;
		ans=atoi(s[i].roll);
		fout1.seekp(offset,ios::beg);
		insertq(fout1,ans,h1);
	}
	fout.close();
	 long long str;ifstream fin;
	 fin.open("Hashed_File2.txt");
	 cout<<"Enter the roll no to be searched in Hashed file\n";
	 cin>>str;
	 h=(str%n1)*14;
	 fin.seekg(h,ios::beg);
	 search(fin,h,str);
	 fin.close();
}
