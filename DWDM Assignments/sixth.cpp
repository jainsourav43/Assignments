#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define no_of_items 10
using namespace std;
vector<int> getdata(string s)
{
	int i=1,num;
	vector<int> temp;
	while(s[i]!='}'&&i<s.size())
	{
		num=0;
	while(s[i]!=','&&s[i]!='}'&&i<s.size())
	{
		num=num*10+(s[i]-'0');
		i++;
	}
	temp.push_back(num);
	if(s[i]=='}')
	break;
	i++;
	
	}
	
	return temp;
		
}

int main()
{
	ifstream fin;
	fin.open("six.txt");
	string s;
	 getline(fin,s);
     getline(fin,s);
     vector<int> temp;
     vector< vector<int > > finalcurr;
     while(!fin.eof())
     {
     		getline(fin,s);
        //	cout<<"S= "<<s<<endl;
        	temp=getdata(s);
//        	for(int i=0;i<temp.size();i++)
//        	{
//        		
//        		cout<<temp[i]<<" ";
//			}2

			finalcurr.push_back(temp);
     }
     fin.close();
}
