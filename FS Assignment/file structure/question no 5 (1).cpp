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
	int i,j,k;char delim;
	ifstream fin,fin2;

    student s;
    
    fin2.open("FILE2.txt");
    cout<<"Enter the no of times you want to read the no from file2\n";
    cin>>k;
    while(k--)
    {
	fin2>>i;fin.open("FILE1.txt");
	for(j=0;j<i;j++)
	{
		fin.getline(s.name,10,'|');
		cout<<"The name of the student is   "<<s.name<<endl;
		fin>>s.rno>>delim;
		cout<<"The roll no. of the student is   "<<s.rno<<endl;
		fin>>s.mark>>delim;
		cout<<"The marks of the student is   "<<s.mark<<endl;
	}
	cout<<".......\n";
		fin.close();
	}

	fin2.close();
}
