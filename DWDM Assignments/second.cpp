#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define no_of_items 10
using namespace std;
int make_it_number(string s)
{
	int i,no=0;
	for(i=0;i<s.size();i++)
	{
		no=no*10+s[i]-'0';
	}
	return no;
}
struct transcation
{
	int no_of_transaction;
	vector<int> no_of_item;
};
int main()
{
	int transaction_count;
	ifstream fin;
	fin.open("first.txt");
	ofstream fout;
	fout.open("second.txt");
	fout<<"Item id                                List of Transaction\n";
	fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
    string s;
    getline(fin,s);
     getline(fin,s);
   	map<int,vector<string>> m;
   	int i;
	while(!fin.eof())
	{
	 char ch;
	 getline(fin,s);
	 i=1;
	 string temp="";
	 while(s[i]!=' ')
	 {
	 	temp=temp+s[i];
	 	i++;
	 }
	 int id=make_it_number(temp);
	 string id1='T'+to_string(id);
	 while(s[i]==' ')
	 {
	 	i++;
	 }
	 while(i<s.size())
	 {
	 	temp="";
	 	while(s[i]!=','&&i<s.size())
	 	{
	 		temp=temp+s[i];
	 		i++;
	 	}
	 	int itemid=make_it_number(temp);
	 	m[itemid].push_back(id1);
	 	i++;
	 }
	}
	 auto it=m.begin();
	 it=m.begin();
	 while(it!=m.end())
	 {
	 	fout<<it->first<<"                                  ";
	 	for(i=0;i<it->second.size()-1;i++)
	 	{
	 		fout<<it->second[i]<<",";
	 	}
	 	fout<<it->second[i];
	 	it++;
	 	fout<<endl;
	 }
	 fout.close();
	 fin.close();
		m.clear();
	
	
}
