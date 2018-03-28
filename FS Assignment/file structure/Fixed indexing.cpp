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
void pack(ofstream &fout)
{
	student s[20];int l1,l2,l3;
	char buffer[40];int length1=10,i;
	cout<<"Enter the no of student\n";
	cin>>n;
	for(int j=0;j<n;j++)
	{
	cout<<"Enter the name of student\n";
	cin>>s[j].name;
	strcpy(buffer,s[j].name);
	l1=strlen(s[j].name);cout<<buffer<<endl;
	for(i=1;i<length1-l1+1;i++)
	{
		strcat(buffer,"*");
	}
	//strcat(buffer,"|");
	cout<<"Enter the roll no. of student\n";
	cin>>s[j].roll;
	strcat(buffer,s[j].roll);cout<<buffer<<endl;
	l3=strlen(s[j].roll);
	for(i=1;i<length1-l3+1;i++)
	{
		strcat(buffer,"*");
	}cout<<buffer<<endl;
	//strcat(buffer,"#");
	

	cout<<"Enter the branch of student\n";
	cin>>s[j].branch;
	strcat(buffer,s[j].branch);
	l2=strlen(s[j].branch);
	for(i=1;i<length1-l2+1;i++)
	{
		strcat(buffer,"*");
	}cout<<buffer<<endl;
	    int  length =strlen(buffer);
	    temp[j][0]=atoi(s[j].roll);
	    temp[j][1]=j*30;
	fout<<buffer;
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
int  search(int start ,int end,int r)
{int mid;
	if(start<=end)
	{
	mid=start+(end-start)/2;
	if(temp[mid][0]<r)
	{
		return search(mid+1,end,r);
	}
	else if(temp[mid][0]>r)
	{
		return search(start,end-1,r);
	}
	else if(temp[mid][0]==r)
	{
		return temp[mid][1];
	}
}
	
}
/*void search(istream &fin,istream &fin1,int c)
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
		s[i][j]='\0';
		i++;
		
	}
	i--;
	cout<<"The name of the student is \n";
	cout<<a[0]<<endl;
	cout<<"The roll no of thr student is\n";
	cout<<a[1]<<endl;
	cout<<"The branch of the student is \n";
	cout<<a[2]<<endl;
}*/

int main()
{
	int k1,k2,k,j;
	ofstream fout;student s;
	fout.open("fixedIndexing.txt");
	pack(fout);
	fout.close();
	int i;
	for( i=0;i<n;i++)
	{
		cout<<temp[i][0]<<"  "<<temp[i][1]<<endl;
	}//fin.close();
	fout.open(" fixedIndexing.txt",ios ::out|ios::app);
	while(k!=-1)
	{
	cout<<"Enter 1 for adding the record press 1  else -1\n";
	cin>>k;
	if(k==1)
	{
		n++;
		k1=fout.tellp();
        pack(fout);
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
  	for( i=0;i<n;i++)
	{
		cout<<temp[i][0]<<"  "<<temp[i][1]<<endl;
	}
	ofstream fout1;
	fout1.open("fixedIndexfile.txt");
	for(i=0;i<n;i++)
	{
		fout1<<temp[i][0]<<" "<<temp[i][1]<<endl;
	}
	fout1.close();
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(temp[j][1]>temp[j+1][1])
			{
			int t=temp[j][1];
			temp[j][1]=temp[j+1][1];
			temp[j+1][1]=t;
			int t2=temp[j][0];
			temp[j][0]=temp[j+1][0];
			temp[j+1][0]=t2;
			}
		}
	}
	int r;ifstream fin;
	cout<<"Enter the roll no to search\n";
	cin>>r;
	int ans=search(0,n-1,r);
	cout<<"ans"<<ans<<endl;
	fin.open("fixedIndexing.txt");
	fin.seekg(ans,ios::beg);
	return 0;
}

