#include<bits/stdc++.h>
using namespace std;
typedef struct dnode
{
	vector<dnode*> child;
	string attribute;
	int attri;
	string Class="";
	vector<string> branches;
	
	
}*dptr;
	vector<string> Attributes;

void printVector(vector<string >v )
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
}

int gain(vector<bool> attributes,vector <vector<string> > input) 
{
	
	cout<<"Welcome to  Gain\n";
	double infod;
	map<string,int>  m;
	int i,j,k;
	double gain=INT_MIN;
	for(i=0;i<input.size();i++)
	{
		m[input[i][input[i].size()-1]]++;
	}
	auto it=m.begin();
	cout<<"m.size() = "<<m.size()<<endl;
	for(i=0;i<m.size();i++)
	{
		double p=(double)it->second*1.0/input.size();
	//	cout<<"p = "<<p<<endl;
		infod=infod+(-p*log2(p));
	//	cout<<"Infod= "<<infod<<endl;
		it++;
	}
	
	int ans;
//	cout<<"After\n";
	for(i=1;i<attributes.size()-1;i++)
	{
		if(attributes[i])
		{
		
		map<string,int> category;
		map<pair <string,string> ,int>	subClasses;
		double infoa=0,inner=0;
		for(j=0;j<input.size();j++)
		{
			category[input[j][i]]++;
			subClasses[make_pair(input[j][i],input[j][input[j].size()-1])]++;
		}
		auto it=category.begin();
	//	cout<<"No of Categories = "<<category.size()<<endl;
		for(j=0;j<category.size();j++)
		{
			inner =0;
			auto it1=subClasses.begin();
			while(it1!=subClasses.end())
			{
				if(it1->first.first==it->first)
				{
					cout<<it1->first.first<<"  "<<it->first<<endl;
		        	double p= ((double)it1->second/category[it->first]);
		    //    	cout<<"p= "<<p<<endl;
					inner=inner+(-p*log2(p));
				//	cout<<"LOg= "<<-p*log2(p)<<endl;
		//			
				}
				it1++;
			
			}
		//	cout<<"inner= "<<inner<<endl;
			infoa=infoa+(double)((double)it->second/input.size())*inner;	
		//	cout<<"MUL= "<<(double)it->second/input.size()<<endl;
			it++;
		}
		
		cout<<"infoa= "<<infoa<<endl;
		cout<<"Gain = "<<infod-infoa<<endl;
		if(gain<infod-infoa)
		{
			gain=infod-infoa;
			ans=i;
		}
		
	}
		
	}
//	for(i=0;i<attributes.size();i++)
//	{
//		if(attributes[i])
//		{
//			
//		}
//	}
return ans;
}
bool allSame(vector<vector<string> >input)
{
	map<string ,int> m;
	int i;
	for(i=0;i<input.size();i++)
	{
		m[input[i][input[i].size()-1]]++;
	}
	if(m.size()==1)
	{
	    cout<<"Returning From All Same \n";
		return 1;
	}
	
	return 0;
}
bool allAttributeDone(vector<bool> attributes)
{
	for(int i=1;i<attributes.size();i++)
	{
		if(attributes[i])
		{
			return 0;
		}
	}
	cout<<"returning from all attributes done\n";
	return 1;
}
string majorityClass(vector< vector<string > > input)
{
	map<string,int> m;
	for(int i=0;i<input.size();i++)
	{
		m[input[i][input[i].size()-1]]++;
	}
	auto it=m.begin();
	int i=0,ans,maj=INT_MIN;
	while(it!=m.end())
	{
		if(maj<it->second)
		{
			maj=it->second;
			ans=i;
		}
		it++;
		i++;
	}
	i=0;
	it=m.begin();
	while(i<ans)
	{
		it++;
		i++;
	}
	return it->first;
}
void printTree(dptr t)
{
	cout<<"\n\n\nPrinting Tree \n\n\n\n\n";
	queue<dptr> q;
	q.push(t);
	q.push(NULL);
	while(!q.empty())
	{
		int i=0;
		while(q.front()!=NULL)
		{
			
			dptr temp=q.front();
			q.pop();
			cout<<"( ";
			if(temp->attri!=-1)
			{
				cout<<Attributes[temp->attri]<<" ";
			}
			else
			{
				cout<<temp->attri<<" ";
			}
			if(temp->attri ==-1)
			cout<< ", "<<temp->Class <<" )";
			else
			{
				cout<<") ";
			}
			
			for(int i=0;i<temp->child.size();i++)
			{
			//	cout<<temp->branches[i]<<" ";
				q.push(temp->child[i]);
			}
		}
		cout<<endl;
		q.pop();
		if(!q.empty())
		{
			q.push(NULL);
		}
	}
	
}
vector< vector <vector <string > > > splitData(vector< vector< string> > input,int category	,vector<string> &branch)
{
		map<string,vector< vector<string> > > m;
		for(int i=0;i<input.size();i++)
		{
			m[input[i][category]].push_back(input[i]);
		}
		vector< vector <vector <string > > > split;
		auto it=m.begin();
		while(it!=m.end())
		{
			branch.push_back(it->first);
			split.push_back(it->second);
			it++;
		}
		return split;
}
dptr decisionTree(vector<bool> &attributes, vector<vector<string> >input )
{
	cout<<"Welcome\n";
	dptr temp=new dnode;
	if(allSame(input))
	{
		cout<<" Inside All Same  \n";
		temp->Class =input[0][input[0].size()-1];
		temp->attri=-1;
		return temp;
	}
	 else if(allAttributeDone(attributes))
	 {
	 	cout<<"Inside All Attribute Done\n";
	 	temp->Class =majorityClass(input);
	 	temp->attri=-1;
	 	return temp;
	 }
	 vector< vector <vector <string> > > split;
	 int splitAttribute = gain(attributes,input);
	 cout<<"SplitAttribute = "<<splitAttribute<<endl;
	 attributes[splitAttribute]=false;
	 vector<string>branch;
	 split=splitData(input,splitAttribute,branch);
	 temp->attri = splitAttribute;
	 for(int i=0;i<split.size();i++)
	 {
	 	temp->branches.push_back(branch[i]);
	 	temp->child.push_back(decisionTree(attributes,split[i]));
	 }
	 return temp;
	 
	 
}
void classify(dptr t,vector<string> test,int index)
{
	if(t->attri==-1)
	{
		cout<<"Class is = "<<t->Class<<endl;
	}
	else
	{
		int i=0;
		for(i=0;i<t->child.size();i++)
		{
			if(test[t->attri-1]==t->branches[i])
			{
				classify(t->child[i],test,index);
			}
		}
	}
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
			cur.push_back(temp);
			i++;
		}
		
		noOfAttributes=cur.size();
		input.push_back(cur);
		
	}
	vector<bool> attributes(noOfAttributes,true);
	for(int j=0;j<input.size();j++)
	{
		printVector(input[j]);
	}
	dptr root =NULL;
	map<string,int>  m;
	for(i=0;i<input.size();i++)
	{
		m[input[i][input[i].size()-1]]++;
	}
	
	int noofClasses=m.size();
	cout<<"No of classes  = "<<noofClasses<<endl;
	root =	decisionTree(attributes,input);
	printTree(root);
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
	classify(root,test,0);
	
	
}
