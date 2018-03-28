#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define no_of_items 10
#define thresholdvalue 20
#define partitionfactor 0.1
using namespace std;
int make_it_number(string s)
{
	int i,no=0;
	//cout<<"s= "<<s<<endl;
	for(i=0;i<s.size();i++)
	{
		//cout<<"s[i]= "<<s[i]<<endl;
		if(s[i]<=57&&s[i]>=48)
		no=no*10+(s[i]-'0');
	}
	return no;
}
int hashfunc(int x,int y)
{
	return (x*10+y)%7;
}
void hashbased()
{
	vector< vector< pair<int,int>  > > v;
	vector<pair<int,int > > curr;
		vector<int  > cur;

	for(int i=0;i<7;i++)
	{
		v.push_back(curr);
	}
	string s;
	ifstream fin;
	fin.open("first.txt");
	getline(fin,s);
	getline(fin,s);
	while(!fin.eof())
	{
		s.clear();
			cur.clear();
			getline(fin,s);
			int i=1;
			int len=s.length();
			while(s[i]!=' '&&i<len)
			{
		
					i++;
			}
			while(s[i]==' '&&i<len)
			{
				i++;
			}
			while(i<len)
			{
			string temp="";
		 	while(s[i]!=','&&i<s.size())
		 	{
		 		temp=temp+s[i];
		 		i++;
		 	}
		 	int itemid=make_it_number(temp);
			cur.push_back(itemid);
			i++;
			}
			
			for(int i1=0;i1<cur.size();i1++)
			{
				for(int j1=i1+1;j1<cur.size();j1++)
				{
					int h=hashfunc(cur[i1],cur[j1]);
					v[h].push_back({cur[i1],cur[j1]});
				}
			}
			
	}
	for(int i=0;i<7;i++)
	{
	
		for(int j=0;j<v[i].size();j++)
		{
				cout<<"{ ";
			cout<<v[i][j].first<<" "<<v[i][j].second<<" ";
				cout<<" }";
		}
		cout<<endl;
	
	}
	
}
vector<int> getdata(string s)// it will read data from file and then convert that into number and push into vector and then return
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
vector< vector< int > >  myvec;
void generateall(vector< int > v,vector<int >  &curr,int pos,int  r)// it will generate  all subsets of size r from n size
{
	int i;
	if(curr.size()==r)
	{
		myvec.push_back(curr);
		return ;
	}
	for(i=pos;i<v.size();i++)
	{
		curr.push_back(v[i]);
		generateall(v,curr,i+1,r);
		curr.pop_back();
	}
	
}
bool checkit(vector<int> &v,vector< vector<int > > &ch)	// it will check for the pruning step 
{
	myvec.clear();
	vector<int> curr;
	curr.clear();
	int check;int j;
	generateall(v,curr,0,ch[0].size());
	for(int k=0;k<myvec.size();k++)
	{
		check=0;
		for(int i=0;i<ch.size();i++)
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
	if(v1.size()==1)
	{
		return true;
	}
	if(v1[v1.size()-2]!=v2[v2.size()-2])
	{
		return false;
	}
	return true;
}
void findlocalfrequent(vector< vector <int> > v)
{
	
	
	cout<<"HII EVERYONE WELCOME TO NITW\n";
		map<vector<int> ,int> ma;
		ofstream fout;
		vector<int > mytemp;
		fout.open("partition.txt",ios::app);
		
		int i,j;
		for(i=0;i<v.size();i++)
		{
			for(j=0;j<v[i].size();j++)
			{
				vector<int> temp;
				temp.push_back(v[i][j]);
				if(ma.find(temp)==ma.end())
				ma[temp]=1;
				else
				ma[temp]++;
			}
		}
		auto it=ma.begin();
		vector< vector<int> > cur ;
		for(; it!=ma.end();it++)
		{
				cout<<"it->first ="<<it->first[0]<<endl;
				cout<<"Count = "<<it->second<<endl;
			if(it->second<thresholdvalue*partitionfactor)
			{
				vector<int> temp;
				temp.push_back(it->first[0]);
				ma.erase(temp);
			}
			else
			{
				vector<int> temp;
				temp.push_back(it->first[0]);
				cur.push_back(temp);
			
				ma.erase(temp);
			}
		}
		vector<int> kelement;
		 vector< vector<int> > finalcurr;
		int r;
	while(true)
	{
		ma.clear();
		cout<<"Printing k's\n";
		for(i=0;i<cur.size();i++)
		{
			
			for(j=i+1;j<cur.size();j++)
			{
				if(!checkcount(cur[i],cur[j]))
				{
					break;
				}
				kelement.clear();
				for(r=0;r<cur[i].size()-1;r++)
				{
					kelement.push_back(cur[i][r]);
				}
					kelement.push_back(cur[i][r]);
					kelement.push_back(cur[j][r]);
					
					 
					
	                if(checkit(kelement,cur))
	                {
	              	 //for(int i1=0;i1<kelement.size();i1++)
	                //  cout<<kelement[i1]<<" ";cout<<endl;
						finalcurr.push_back(kelement);
					
					}
			}
			
		}
			cout<<"hii\n";
		     bool t[finalcurr[0].size()];int tr;
			 for( int i1=0;i1<finalcurr.size();i1++)
			 {	 	
			 	for(int in=0;in<finalcurr[i1].size();in++) t[in]=false;
			 	
			 	
			 	for(int j1=0;j1<v.size();j1++)
			 	{
			 		for(int k1=0;k1<v[j1].size();k1++)
			 		{
			 				for(int tr=0;tr<finalcurr[i1].size();tr++)
						 	{
						 		if(finalcurr[i1][tr]==v[j1][k1])
						 		{
						 				t[tr]=true;
							 			break;
								 }
							}
					}
						 int tr1;
			 for(tr1=0;tr1<finalcurr[i1].size();tr1++)
			 {
			 	if(t[tr1]==false)
			 	{
			 		break;
			 	}
			 }
			 if(tr1==finalcurr[i1].size())
			 {
		//	 cout<<"Gonna Increase\n";
		 	 ma[finalcurr[i1]]++;
		 	}
				 }
			 
		
		 }
		 	 cout<<"Bye\n";
		 	 
		fout<<"Item id            No of transaction it went through \n";
	    fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
	    it=ma.begin();
	    cur.clear();
	    	cout<<"Hello MAN\n";
	 while(it!=ma.end())
	 {
	 	int index=0;
	 //	cout<<"{";
	 	while(index<it->first.size())
	 	{
//		 	if(index==it->first.size()-1)
//		 	cout<<it->first[index]<<" ";
//		 	else
//		 	cout<<it->first[index]<<",";
		 	index++;
		 }	
	//	cout<<"}          ";
	 //	cout<<it->second;
	 	it++;
	 //	cout<<endl;
	}
	cout<<"Hello Brother\n";
	    it=ma.begin();
	 	fout<<"Item id            No of transaction it went through \n";
	    fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
	 while(it!=ma.end())
	 {
		 	mytemp.clear();
		 	if(it->second>=thresholdvalue*partitionfactor)
		 	{
		 	int index=0;
		 	fout<<"{";
		 	while(index<it->first.size())
		 	{
		 		if(index==it->first.size()-1)
		 		fout<<it->first[index]<<" ";
		 		else
			 	fout<<it->first[index]<<",";
			 	mytemp.push_back(it->first[index]);
			 	index++;
			 }	
			fout<<"}           ";
			cur.push_back(mytemp);
			fout<<"               ";
		 	fout<<it->second;
		 	fout<<endl;
		 	}
	 		it++;
	 }
	 cout<<"Hello Sister\n";
	 cout<<"Cur size = "<<cur.size()<<endl;
	 if(cur.size()==0)
	 {
	 	break;
	 }
	 finalcurr.clear();

	}
	
	

}
void getdataandcount(string s,int r)
{
	
}
int main()
{
	int transaction_count;
	ifstream fin;
	int choice ;
	cout<<"Enter one for hash  based else 0\n";
	cin>>choice;
	if(choice==1)
	{
	
	hashbased();
	return 0;
	}
	fin.open("first.txt");
	ofstream fout;
	fout.open("partiton.txt");
	fout<<" ";
	fout.close();
	fout<<"Item id            No of transaction it went through \n";
	fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
    string s;
    getline(fin,s);
    getline(fin,s);
   	map<vector<int> ,int> m,cur;
   	vector< vector<int> >local;
   	int i;
   	int counter=0;
   	vector<int> localone;
   	while(!fin.eof())
   	{
   		counter=0;
   		local.clear();
		while(!fin.eof())
		{
			localone.clear();
			counter++;
			if(counter>10)
			break;
			char ch;
			 getline(fin,s);
			 i=1;
			 string temp="";
			 while(s[i]!=' ')
			 {
			 	temp=temp+s[i];
			 	i++;
			 }
			// localone.push_back(make_it_number(temp));
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
			 	localone.push_back(itemid);
			 	vector<int> tempvec;
			 	tempvec.push_back(itemid);
			 	if(m.find(tempvec)==m.end())
			 	{
			 		m[tempvec]=1;
			 	}
			 	else
			 	{
			 		m[tempvec]++;
			 	}
			 	i++;
			 }
			 local.push_back(localone);
		}
		
		
		findlocalfrequent(local);
	}
	fin.close();
//	 auto it=m.begin();
//	 it=m.begin();
//	 while(it!=m.end())
//	 {
//	 	int index=0;
//	 	fout<<"{ ";
//	 	while(index<it->first.size())
//	 	{
//	 	fout<<it->first[index]<<" ";
//	 	index++;
//		 }
//		 	fout<<" }            ";	
//	 	fout<<it->second;
//	 	it++;
//	 	fout<<endl;
//	 }
//	 	 it=m.begin();
//		vector<vector<int > >curr;
//		vector<int> mytemp;
//	 	fout<<"Item id            No of transaction it went through \n";
//	    fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
//	 while(it!=m.end())
//	 {
//	 	mytemp.clear();
//	 	if(it->second>=thresholdvalue)
//	 	{
//	 	
//	 	int index=0;
//	 	fout<<"{ ";
//	 	while(index<it->first.size())
//	 	{
//	 	fout<<it->first[index]<<" ";
//		mytemp.push_back(it->first[index]);
//	 	index++;
//		 }	
//		 fout<<"}                 ";
//		curr.push_back(mytemp);
//	 	fout<<it->second;
//	 	it++;
//	 	fout<<endl;
//	 	}
//	 	else
//	 	{
//	 		m.erase(it->first);
//	 	}
//	 }
//	 vector< vector<int> > finalcurr;
//	 map<vector<int > ,int > ma;
//	 fin.close();
//	vector<int> kelement;
//	fin.open("first.txt");
//	int j,r;
//	cout<<"printting cur\n";
//	for(int i1=0;i1<curr.size();i1++)
//	{
//		for(int j1=0;j1<curr[i1].size();j1++)
//		{
//			cout<<curr[i1][j1]<<" ";
//		}
//		cout<<endl;
//	}
//	fin.close();
//	int count1=0;
//	while(true)
//	{
//		
//		ma.clear();
//		cout<<"Printing k's\n";
//		for(i=0;i<curr.size();i++)
//		{
//			
//			for(j=i+1;j<curr.size();j++)
//			{
//				if(!checkcount(curr[i],curr[j]))
//				{
//					break;
//				}
//				kelement.clear();
//				for( r=0;r<curr[i].size()-1;r++)
//				{
//					kelement.push_back(curr[i][r]);
//				}
//					kelement.push_back(curr[i][r]);
//					kelement.push_back(curr[j][r]);
//					
//					 
//					
//	                if(checkit(kelement,curr))
//	                {
//	               for(int i1=0;i1<kelement.size();i1++)
//	                 cout<<kelement[i1]<<" ";cout<<endl;
//	                 
//	                 
//	                ma[kelement]++;
//					finalcurr.push_back(kelement);
//					
//					}
//			}
//			
//		}
//		fin.open("first.txt");
//		 getline(fin,s);
//    	getline(fin,s);
//	     while(!fin.eof())
//		{
//		 getline(fin,s);
//		 i=1;
//		 string temp="";
//		 while(s[i]!=' ')
//		 {
//		 	temp=temp+s[i];
//		 	i++;
//		 }
//		 int id=make_it_number(temp);
//		 while(s[i]==' ')
//		 {
//		 	i++;
//		 }
//		 vector<int> myvec;
//		 while(i<s.size())
//		 {
//		 	temp="";
//		 	while(s[i]!=','&&i<s.size())
//		 	{
//		 		temp=temp+s[i];
//		 		i++;
//		 	}
//		 	int itemid=make_it_number(temp);
//		 	myvec.push_back(itemid);
//		 	
//		 	i++;
//		 }
//		bool  t[finalcurr[0].size() ];
//		 for( int i1=0;i1<finalcurr.size();i1++)
//		 {	 	
//		 	for(int in=0;in<finalcurr[i1].size();in++) t[in]=false;
//		 	for(int tr=0;tr<finalcurr[i1].size();tr++)
//		 	{
//			for(int p=0;p<myvec.size();p++)
//		 	{
//		 		if(finalcurr[i1][tr]==myvec[p])
//		 		{
//		 			t[tr]=true;
//		 			break;
//				 }
//			 }
//			
//		}
//			 int tr1;
//		     for( tr1=0;tr1<finalcurr[i1].size();tr1++)
//			 {
//			 	if(t[tr1]==false)
//			 	{
//			 		break;
//			 	}
//			 }
//			 if(tr1==finalcurr[i1].size())
//		 	 ma[finalcurr[i1]]++;
//
//		 }
//	}
//	fin.close();
//	curr.clear();
//	vector<int> mytemp;
//	    auto it=ma.begin();
//		fout<<"Item id            No of transaction it went through \n";
//	    fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
//	 while(it!=ma.end())
//	 {
//	 	
//	 	int index=0;
//	 	fout<<"{";
//	 	while(index<it->first.size())
//	 	{
//	 	if(index==it->first.size()-1)
//	 	fout<<it->first[index]<<" ";
//	 	else
//	 	fout<<it->first[index]<<",";
//	 	index++;
//		 }	
//		fout<<"}          ";
//	 	fout<<it->second;
//	 	it++;
//	 	fout<<endl;
//	 	}
//	 it=ma.begin();
//	 	fout<<"Item id            No of transaction it went through \n";
//	    fout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
//	 while(it!=ma.end())
//	 {
//	 	mytemp.clear();
//	 	if(it->second>=thresholdvalue)
//	 	{
//	 	int index=0;
//	 	fout<<"{";
//	 	while(index<it->first.size())
//	 	{
//	 		if(index==it->first.size()-1)
//	 		fout<<it->first[index]<<" ";
//	 		else
//	 	fout<<it->first[index]<<",";
//	 	mytemp.push_back(it->first[index]);
//	 	index++;
//		 }	
//		 fout<<"}           ";
//		  curr.push_back(mytemp);
//		  fout<<"               ";
//	 	fout<<it->second;
//	 
//	 	fout<<endl;
//	 	}
//	 	else
//	 	{
//	 	}
//	 		it++;
//	 }
//	for(int i1=0;i1<curr.size();i1++)
//	{
//		for(int j1=0;j1<curr[i1].size();j1++)
//		{
//			cout<<curr[i1][j1]<<" ";
//		}
//		cout<<endl;
//	}
//	finalcurr.clear();
//	if(curr.size()==0)
//	break;
//	}
	

}
