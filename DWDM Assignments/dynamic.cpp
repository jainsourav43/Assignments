#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define minsupport 2
//Dynamic Matching

vector<int> getdata(string s)// it will read data from file and then convert that into number and push into vector and then return
{
	int i=0,num;
	vector<int> temp;
	while(s[i]!=' ')
	{
		i++;
	}
	while(s[i]==' ')
	{
		i++;
	}
	int n=0;
	while(i<s.length())
	{
		n=0;
		while(i<s.length()&&s[i]!=',')
		{
			n=n*10+s[i]-'0';
			i++;
		}
		i++;
		temp.push_back(n);
		cout<<"n= "<<n<<endl;
	}	
	return temp;
		
}
vector< vector< int > >  myvec;
void generateall(vector< int > v,vector<int >  &curr,int pos,int  r)// it will generate  all subsets
{
	int i;
	if(curr.size()>0)
	myvec.push_back(curr);
	for(i=pos;i<v.size();i++)
	{
		curr.push_back(v[i]);
		generateall(v,curr,i+1,r);
		curr.pop_back();
	}
	
}
void printdata()// Printing the data of vector myvec 
{
		for(int i=0;i<myvec.size();i++)
		{
			for(int j=0;j<myvec[i].size();j++)
			{
				cout<<myvec[i][j]<<" ";
			}
			cout<<endl;
		}
		
}
bool check(vector<int> v1,vector< int > v2)// Checking whether k-1 items are same or not 
{
	int i;
	for(i=0;i<v1.size();i++)
	{
		if(v1[i]!=v2[i])
		{
			break;
		}
	}
	if(i<v1.size()-1)
	{
		return false;
	}
	return true;
}
void pushdata(vector<int> v1,vector< int > v2,vector<int> &c)// Copying elements from both the vector into one
{
	int i;
	for(i=0;i<v1.size()-1;i++)
	{
		c.push_back(v1[i]);
	}
	c.push_back(v1[i]);
	c.push_back(v2[i]);
//	cout<<"Printing c \n";
//	for(i=0;i<c.size();i++)
//	{
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
	return;
}
void printmap(map<vector<int > ,int> m)// Printing the Map
{
	auto it=m.begin();
	for(; it!=m.end();it++)
	{
		int i=0;
		for(i=0;i<it->first.size();i++)
		{
			cout<<it->first[i]<<" ";
		}
		cout<<"      "<<it->second<<endl;
	}
}
void print(vector<int> v1,vector<int > v2)// Printing the vectors 
{
	int i;
	for(i=0;i<v1.size();i++)
	{
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	cout<<endl;
}
int  main()
{
	ifstream fin;
	string s;
	map<vector< int > ,int> m;
	m.clear();
	vector<int > temp;
	getline(fin,s);
	int i;
	
	int count=0;
	while(true)
	{
		count++;
		if(count>3)
		break;
		fin.open("f1.txt");
		getline(fin,s);
		while(!fin.eof())
		{
			getline(fin,s);
			temp=getdata(s);
			vector< int> cur;
			myvec.clear();
			generateall(temp,cur,0,i);
			for(i=0;i<myvec.size();i++)
			{
				if(myvec[i].size()==1)
				{
					if(m[myvec[i]]<minsupport)
					{
						m[myvec[i]]++;
					}
				}
			}
			printmap(m);
			auto it=m.begin(),it2=m.begin();
			for( ;it!=m.end();it++)
			{
				it2=it;
				it2++;
				for(; it2!=m.end();it2++)
				{
					if(it->first.size()==it2->first.size()&&it->second>=minsupport&&it2->second>=minsupport)
					{
						if(check(it->first,it2->first))
						{
							vector< int > c;
							pushdata(it->first,it2->first,c);
							if(m.find(c)==m.end())
							{
							m[c]=0;
							}
						}
					}
				}
			}
			for(i=0;i<myvec.size();i++)
			{
				if(m.find(myvec[i])!=m.end())
				{
					if(m[myvec[i]]<minsupport&&myvec[i].size()>=count)
					m[myvec[i]]++;
				}
			}
				
			cout<<"AT the end Printing Map\n";
			printmap(m);
		}
		fin.close();
	}
	
}
