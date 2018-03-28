#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
	ifstream inf1,inf2;
	ofstream of1,of2;
	char s[100],s1[100];
	of1.open("sourav.txt");
	cout<<"Enter the line to be inserted\n";
	cin.getline(s,100);
	of1.write(s,100);
	of1.close();
	inf1.open("sourav.txt");
	inf1.getline(s1,100);
	cout<<s1<<endl;
	return 0;	
}

