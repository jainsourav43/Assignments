#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	int rno;
	char name[10];
	int mark;
};
int main()
{
	int i,j,k,n;
	student s[20];
	cout<<"Enter the no of students u wanna enter \n";
	cin>>n;
	ofstream fout;
	fout.open("INDEXING.txt");
	for(i=0;i<n;i++)
	{
		cout<<"Enter the name of students  :";
		cin>>s[i].name;
		fout<<s[i].name<<"|";
 		cout<<"Enter the Roll no of student   :";
        cin>>s[i].rno;
	    fout<<s[i].rno<<"|";
	    cout<<"Enter the Marks of the student\n";
	    cin>>s[i].mark;
	    fout<<s[i].mark<<"#";
	}
	int temp[n][2];
	
}

