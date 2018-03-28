#include <iostream>
#include<bits/stdc++.h>
#define NO_OF_Attributes 3
using namespace std;

int main()
{
	ifstream fin;
	fin.open("DataCleaning.txt");
	ofstream fout;
	fout.open("DataCleaningOutput.txt");
	string s;
	while(!fin.eof())
	{
		s="";
		getline(fin,s);
		int i=0;
		int count=0;
		for(i=0;i<s.length();)
		{
			if(s[i]==' ')
			{
				s[i]='X';
			}
			while(s[i]!=' ')
			{
				
				i++;
			}
			count++;
			i++;
		}
		cout<<count<<endl;
		if(count<3)
		{
			//s.push_back('');
			s.push_back('X');
		}
		fout<<s<<endl;
	}
	fin.close();
	fout.close();
	
}
