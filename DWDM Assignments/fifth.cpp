#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define no_of_items 100
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
		

}vector< vector< int > >  myvec;

void generateall(vector< int > v,vector<int >  &curr,int pos,int  stop)
{
	int i;
	if(curr.size()==stop)
	{
		myvec.push_back(curr);
		return ;
	}
	for(i=pos;i<v.size();i++)
	{
		curr.push_back(v[i]);
		generateall(v,curr,i+1,stop);
		curr.pop_back();
	}
	
}
bool checkit(vector<int> &v,vector< vector<int > > &ch)	
{
	myvec.clear();
	vector<int> curr;
	curr.clear();
	int check;int j;
	generateall(v,curr,0,ch[0].size());
	for(int k=0;k<myvec.size();k++)
	{
		check=0;
		for(int i=0;i<ch.size()-1;i++)
		{
			for(j=0;j<ch[i].size();j++)
			{
				if(myvec[k][j]!=ch[i][j])
				{
					break;
				}
			}
		
		if(j==ch[i].size())
		{
			check=1;
			break;
		}
		}
		if(check==0)
		{
			return false;
		}
}
return true;
}
bool checkcount(vector<int> v1,vector<int> v2)
{
	if(v1[v1.size()-2]!=v2[v2.size()-2])
	{
		return false;
	}
	return true;
}
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
	fout.open("fifth.txt");
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
cout<<" Please Enter Threshold Value\n ";
int th;
cin>>th;
vector<int> kelement;
vector< vector<int > > curr;
vector< vector<int > > finalcurr;
vector<int> temp,temp1;
auto it=m1.begin();
map<pair <int, pair< int ,int > > ,int > ma;
while(it!=m1.end())
{
	if(it->second>=th)
	fout<<"{"<<it->first.first<<","<<it->first.second<<"}"<<"                    "<<it->second<<endl;
	it++;
}

		 fout.close();
		 fin.close();
	 
	 	fin.open("fifth.txt");
	    getline(fin,s);
        getline(fin,s);
        while(!fin.eof())
        {
        	getline(fin,s);
        	temp=getdata(s);
			curr.push_back(temp);
		}
		int r;
		for(i=0;i<curr.size()-1;i++)
		{
			
			for(j=i+1;j<curr.size()-1;j++)
			{
				if(!checkcount(curr[i],curr[j]))
				{
					break;
				}
				kelement.clear();
				for( r=0;r<curr[i].size()-1;r++)
				{
					kelement.push_back(curr[i][r]);
				}
					kelement.push_back(curr[i][r]);
					kelement.push_back(curr[j][r]);
					
					 for(int i1=0;i1<kelement.size();i1++)
	                cout<<kelement[i1]<<" ";cout<<endl;
					
	                if(checkit(kelement,curr))
	                {
	               
	                ma[make_pair(kelement[0],make_pair(kelement[1],kelement[2]))]=0;
					finalcurr.push_back(kelement);
					
					}
			}
			
		}
	fin.close();
	fin.open("first.txt");
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
	 	bool  t[finalcurr[0].size() ];
	 for( int i1=0;i1<finalcurr.size();i1++)
	 {	 	
	 
	 	for(int in=0;in<finalcurr[i1].size();in++) t[in]=false;
	 	for(int tr=0;tr<finalcurr[i1].size();tr++)
	 	{
		for(int p=0;p<myvec.size();p++)
	 	{
	 		if(finalcurr[i1][tr]==myvec[p])
	 		{
	 			t[tr]=true;
	 			break;
			 }
		 }
		
	}
	 int tr1;
	     for( tr1=0;tr1<finalcurr[i1].size();tr1++)
		 {
		 	if(t[tr1]==false)
		 	{
		 		break;
		 	}
		 }
		 if(tr1==finalcurr[i1].size())
		  ma[make_pair(finalcurr[i1][0],make_pair(finalcurr[i1][1],finalcurr[i1][2]))]++;
	 }
}
auto ti=ma.begin();
cout<<"first second Count \n";
ofstream fout1;
fout1.open("six.txt");
fout1<<"Item id"<<"      "<< "No of transaction it went through "<<endl;
while(ti!=ma.end())
{
	if(ti->second>=th)
	fout1<<"{ "<<ti->first.first<<","<<ti->first.second.first<<","<<ti->first.second.second<<"}   "<<ti->second<<endl;
	ti++;
}			 
	 m1.clear();
	
	
}
