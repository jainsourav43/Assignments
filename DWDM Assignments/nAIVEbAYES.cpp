#include<bits/stdc++.h>
using namespace std;
void printVector(vector<string >v )
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
}
vector<string> Attributes;



void NaiveBayesModel(vector< vector<string>> &input, map<pair<string,string> , int> &m)
{
	int i,j;
	map<string,int>categories;
	for(i=0;i<input.size();i++)
	{
		categories[input[i][input[i].size()-1]]++;
	}
	int noOfClasses = categories.size();
	
	
	
	for(i=0;i<input.size();i++)
	{
		for(j=0;j<input[i].size()-1;j++)
		{
			m[make_pair(input[i][j],input[i][input[i].size()-1])]++;
		}
	}
	
	
	auto it= m.begin();
	while(it!=m.end())
	{
		cout<<it->first.first<<" "<<it->first.second<<"    : "<<it->second<<endl;
		it++;
	}
	
	
	
}

void classify(vector< vector<string>> &input,vector<string>test,map<pair<string,string> ,int> m)
{
	int i,j;
	map<string,int>categories;
	for(i=0;i<input.size();i++)
	{
		categories[input[i][input[i].size()-1]]++;
	}
	int noOfRows=input.size();
	int noOfClasses=categories.size();
	auto it=categories.begin();
	double maxProb=(double)INT_MIN;
	string ansClass;
	for(i=0;i<noOfClasses;i++)
	{
		double classprob= (double)it->second/(double)noOfRows;
		double probability =classprob;
		for(j=0;j<test.size();j++)
		{
			//cout<<"m[make_pair(test[i],it->first)] ,it->second= "<<m[make_pair(test[j],it->first)]<<" "<<it->second<<endl;
			probability=probability*((double)m[make_pair(test[j],it->first)]/(double)it->second);
		}
		probability=probability;
		cout<<it->first<<"  "<<probability<<endl;
		
		if(maxProb<probability)
		{
			maxProb=probability;
			ansClass=it->first;
		}
	//	cout<<"Maxprob= "<<maxProb<<endl;
		it++;
	}
	cout<<"Class Of the Tupple is  = "<<ansClass<<endl;
}
int main()
{
	ifstream fin;
	string s;
	fin.open("DecisionTreeInput.txt");
	getline(fin,s);
	vector< vector< string > > input;
	int noOfAttributes;
	string temp;
	int i=0;
	while(i<s.length())
	{
		temp="";
		while(i<s.length()&&s[i]!=' ')
		{
			temp=temp+s[i];
			i++;
		}
		if(temp!="")
		Attributes.push_back(temp);
		i++;
	}
	printVector(Attributes);
	while(!fin.eof())
	{
		getline(fin,s);
		vector<string> cur;
		string temp;
		int i=0,first=0;
		while(i<s.length())
		{
			temp="";
			first++;
			while(i<s.length()&&s[i]!=' ')
			{
				temp=temp+s[i];
				i++;
			}
			if(first!=1)
			if(temp!="")
			cur.push_back(temp);
			i++;
		}
		
		noOfAttributes=cur.size();
		input.push_back(cur);
		
	}
	for(int j=0;j<input.size();j++)
	{
		printVector(input[j]);
	}
	map<pair<string,string>,int > m;
	NaiveBayesModel(input,m);
	int n;
	cout<<"enter the Number of attributes\n";
	cin>>n;
	cout<<"Enter the  Row to classify age income student credit rating \n";
	vector<string>test;
	for(i=0;i<n;i++)
	{
		string temp;
		cin>>temp;
		test.push_back(temp);
	}
	classify(input,test,m);
}
