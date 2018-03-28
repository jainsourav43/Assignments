#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;
int n;	int size;int sz[20];
int temp[20][2];
struct student 
{
	char roll[10];
	char name[10];
	char branch[10];
};
ostream &operator <<(ostream &fout,student &s)
{
	char buffer[100];
   fout<<s.name<<"|";strcpy(buffer,s.name);strcat(buffer,"|");
   fout<<s.roll<<"|";strcat(buffer,s.roll);strcat(buffer,"|");
   fout<<s.branch<<"#";strcat(buffer,s.branch);strcat(buffer,"#");
   size =strlen(buffer);
   return fout;
}
istream &operator >>(istream &fin,student &s)
{
	cout<<"Enter the name of the student\n";
	fin>>s.name;
	cout<<"Enter the roll no. of the student\n";
	fin>>s.roll;
	cout<<"enter the branch of the student\n";
	fin>>s.branch;
	return fin;
}
void pack(ostream &fout)
{
	student s[20];
	cout<<"Enter the number of student \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		fout<<s[i];
		sz[i]=size;
	}
}
void unpack(istream &fin)
{
	char a[10][10],b='\0';int i=0;int j=0;
	while(b!='#')
	{
		fin>>b;j=0;
		while(b!='|'&&b!='#')
		{
		    a[i][j++]=b;
			fin>>b;
			
		}
		i++;
	}
	i--;
	cout<<"The name of the student is \n";
	cout<<a[0]<<endl;
	cout<<"The roll no of thr student is\n";
	cout<<a[1]<<endl;
	cout<<"The branch of the student is \n";
	cout<<a[2]<<endl;
}
void search(istream &fin,istream &fin1,int c)
{
	int k1,k2;
	for(int i=0;i<n;i++)
	{
		fin1>>k1>>k2;
		if(k1==c)
		{
			break;
		}
	}
	fin.seekg(k2,ios::beg);
	char a[10][10],b='\0';int i=0;int j=0;
	while(b!='#')
	{
		fin>>b;j=0;
		while(b!='|'&&b!='#')
		{
		    a[i][j++]=b;
			fin>>b;
			
		}
		a[i][j]='\0';
		i++;
		
	}
	i--;
	cout<<"The name of the student is \n";
	cout<<a[0]<<endl;
	cout<<"The roll no of thr student is\n";
	cout<<a[1]<<endl;
	cout<<"The branch of the student is \n";
	cout<<a[2]<<endl;
}
int main()
{
	ofstream fout;student s;
	fout.open("Indexing.txt");
	pack(fout);
	fout.close();
	ifstream fin,fin1;
	fin.open("Indexing.txt");
	char b='\0',a[n][10];int j=0,i=0,k=0,k1,k2;cout<<"N=="<<n<<endl;
    for(int i=0;i<n;i++)
	{cout<<"2\n";
	    j=0;k2=fin.tellg();
		while(b!='#')
		{	j++;k=0;
		   fin>>b;
			while(b!='|'&&b!='#')
			{cout<<"4\n";
				cout<<"b  = "<<b<<endl;
				if(j==2)
				{
					a[i][k++]=b;
				}
				fin>>b;
			}
			if(j==2)
			{
			k1=atoi(a[i]);
			temp[i][0]=k1;
		    temp[i][1]=k2;
		    }
		}
		b='\0';
	}
	for(i=0;i<n;i++)
	{
		cout<<temp[i][0]<<"  "<<temp[i][1]<<endl;
	}fin.close();
	fout.open("Indexing.txt",ios ::out|ios::app);
	while(k!=-1)
	{
	cout<<"Enter 1 for adding the record press 1  else -1\n";
	cin>>k;
	if(k==1)
	{
		n++;
		k1=fout.tellp();
        cin>>s;
        fout<<s;
        sz[n-1]=size;
        k2=atoi(s.roll);
		temp[n-1][0]=k2;
		temp[n-1][1]=k1;
		for(j=0;j<n-1;j++)
		{
			temp[n-1][1]=temp[n-1][1]+temp[j][1];
		}cout<<"SZ[n-2]  = "<<sz[n-2]<<endl;
      temp[n-1][1]=temp[n-1][1]+sz[n-2];
	}
   }
  fout.close();
  	for(i=0;i<n;i++)
	{
		cout<<temp[i][0]<<"  "<<temp[i][1]<<endl;
	}
	ofstream fout1;
	fout1.open("Indexfile.txt");
	for(i=0;i<n;i++)
	{
		fout1<<temp[i][0]<<" "<<temp[i][1]<<endl;
	}
	fout1.close();
	cout<<"Enter the roll no. to search\n";
	cin>>k;
	fin1.open("indexfile.txt");
	fin.open("Indexing.txt");
	search(fin,fin1,k);
}

