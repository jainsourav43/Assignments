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
	fout.open("fourth.txt");
	fout<<"Item id            No of transaction it went through \n";
	fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
    string s;
    getline(fin,s);
     getline(fin,s);
   	int i,j;
   	map<pair<int,int> ,int>m1;
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
	 vector<int> myvec;
	 while(i<s.size())
	 {
	 	temp="";
	 	while(s[i]!=','&&i<s.size())
	 	{
	 		temp=temp+s[i];
	 		i++;
	 	}
	 	int itemid=make_it_number(temp);
	 	myvec.push_back(itemid);
	 	
	 	i++;
	 }
	 for(int i1=0;i1<myvec.size();i1++)
	 {
	 	for(int j1=i1+1;j1<myvec.size();j1++)
	 	{
	 		if(m1.find(make_pair(myvec[i1],myvec[j1]))==m1.end())
	 		m1[make_pair(myvec[i1],myvec[j1])]=1;
	 		else
	 		m1[make_pair(myvec[i1],myvec[j1])]++;
	 		
	 	}
	 }
	}
auto it=m1.begin();
while(it!=m1.end())
{
	
	fout<<"{"<<it->first.first<<","<<it->first.second<<"}"<<"                    "<<it->second<<endl;
	it++;
}
	 fout.close();
	 fin.close();
	 m1.clear();
	
	
}
