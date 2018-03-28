#include<iostream>
#define minsupportcount 2
#include<bits/stdc++.h>
using namespace std;
typedef 
struct fpnode
{
	int data;
	int count;
	fpnode* next;
	fpnode* parent;
	vector<fpnode*>  child;
	fpnode* aux;
}*fpptr;
struct table
{
	int data;
	int count;
	fpptr head;
};
struct conode
{
	fpptr tr;
	int data;
	vector<table> headers;
};
vector<conode> conditional;
vector<table> header;
vector<fpptr> link[1001];//link of all the same data horizontally
vector<pair<int ,int> > vec;
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
	}	
	return temp;
		
}
fpptr search(fpptr t,int key)
{
	if(t==NULL)
	{
		return  NULL;
	}
	for(int i=0;i<t->child.size();i++)
	{
		if(t->child[i]->data==key)
		{
			return t->child[i];
		}
	}
	return NULL;
	
}
void print(fpptr t)
{
	if(!t)
	{
		return ;
	}
	queue<fpptr> q;
	q.push(t);
	q.push(NULL);
	while(!q.empty())
	{
		while(q.front()!=NULL)
		{
			fpptr temp=q.front();
			q.pop();
			cout<<"( "<<temp->data<<" , "<<temp->count<<" ) ";
			for(int i=0;i<temp->child.size();i++)
			{
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
void printFP(fpptr t,map<int,int> &m)
{
	if(!t)
	{
		return ;
	}
	queue<fpptr> q;
	q.push(t);
	q.push(NULL);
	while(!q.empty())
	{
		while(q.front()!=NULL)
		{
			fpptr temp=q.front();
			q.pop();
			if(temp->count!=-1)
			m[temp->data]+=temp->count;
			cout<<"( "<<temp->data<<" , "<<temp->count<<" ) ";
			for(int i=0;i<temp->child.size();i++)
			{
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
vector<table> condiheader;
vector<fpptr>condilink[100];
void linkallnextcondi(fpptr &t)
{
	int i,j;
	for(i=1;i<100;i++)
	{
		if(condilink[i].size()==0)
		continue;
		for(j=0;j<condilink[i].size()-1;j++)
		{
				condilink[i][j]->next=condilink[i][j+1];
		}
		if(condilink[i].size()>0)
		condilink[i][j]->next=NULL;
	}
	//cout<<"HI Buddy\n";
	for(i=0;i<vec.size();i++)
	{
		table to;
		to.data=vec[i].first;
		to.count=vec[i].second;
		to.head=condilink[vec[i].first][0];
		condiheader.push_back(to);
	}
	cout<<"Printing Through condilinks\n";
	for(i=0;i<condiheader.size();i++)
	{
		fpptr tmp=condiheader[i].head;
		while(tmp)
		{
			cout<<"( "<<tmp->data<<", "<<tmp->count<<" )"<<" ";
			tmp=tmp->next;
			
		}
		cout<<endl;
	}
	
	
	
}
void linkallnext(fpptr &t)
{
	int i,j;
	for(i=1;i<1000;i++)
	{
		if(link[i].size()==0)
		continue;
		for(j=0;j<link[i].size()-1;j++)
		{
				link[i][j]->next=link[i][j+1];
		}
		if(link[i].size()>0)
		link[i][j]->next=NULL;
	}
	cout<<"HI Buddy\n";
	for(i=0;i<vec.size();i++)
	{
		table to;
		to.data=vec[i].first;
		to.count=vec[i].second;
		to.head=link[vec[i].first][0];
		header.push_back(to);
	}
	cout<<"Printing Through Links\n";
	for(i=0;i<header.size();i++)
	{
		fpptr tmp=header[i].head;
		while(tmp)
		{
			cout<<"( "<<tmp->data<<", "<<tmp->count<<" )"<<" ";
			tmp=tmp->next;
			
		}
		cout<<endl;
	}
	
	
	
}
void create(fpptr &t,vector<int> temp,int index)
{
	if(index==temp.size())
	{
		return ;
	}
	fpptr s=search(t,temp[index]);
	if(!s)
	{
		fpptr tem=	new fpnode();
		tem->data=temp[index];
		link[temp[index]].push_back(tem);
		tem->count=1;
		tem->parent=t;
		tem->next=NULL;
		t->child.push_back(tem);
		create(t->child[t->child.size()-1],temp,index+1);
	}
	else
	{
		s->count++;
		create(s,temp,index+1);
	}
}

void createconditree(fpptr &t,vector<pair<int,int >> temp,int index)// creatring tree for each cointional base
{
	if(index==temp.size())
	{
		return ;
	}
	fpptr s=search(t,temp[index].first);
	if(!s)
	{
		fpptr tem=	new fpnode();
		tem->data=temp[index].first;
		condilink[temp[index].first].push_back(tem);
		tem->count=temp[index].second;
		tem->parent=t;
		tem->next=NULL;
		t->child.push_back(tem);
		createconditree(t->child[t->child.size()-1],temp,index+1);
	}
	else
	{
		s->count+=temp[index].second;
		createconditree(s,temp,index+1);
	}
}

fpptr  createcondi(table tr)
{
	vector<fpptr> v;
	fpptr t=NULL;
	t=new fpnode;
	t->data=tr.head->data;
	t->parent=NULL;
	t->count=-1;
	fpptr h=tr.head,temp;
	//cout<<"Creating condi\n";
	cout<<"Creating Conditional Pattern Base for  ";
	cout<<h->data<<endl;
	vector<pair<int,int> >p;
	int mincountofbranch=h->count;
	fpptr temph=h;
	while(temph)
	{
	p.clear();
	h=temph;
	mincountofbranch=h->count;
//	cout<<"H dta ="<<h->data<<endl;
//	cout<<"MIN COUNT OF BRAnch= "<<mincountofbranch<<endl;
	while(h->parent->parent)
	{
//		temp=h->next;
//		v.clear();
//		while(h->parent->parent)
//		{
//			v.push_back(h);
//			h=h->parent;
//		}
//	//	create(t,v,0);
//		cout<<endl;
//		h=temp;
		h=h->parent;
	p.push_back({h->data,mincountofbranch});
	

	} 
	reverse(p.begin(),p.end());
	createconditree(t,p,0);
	temph=temph->next;
}
	
	return t;
	
}
void remove_less_than_min(fpptr &tree)
{
	if(!tree)
	{
		return;
	}
//	cout<<"Tree -> Data ="<<tree->data<<endl;
	for(int i=0;i<tree->child.size();i++)
	{
		if(tree->child[i]->count<minsupportcount)
		{
			tree->child[i]=NULL;
			if(tree->child.size()==1)
			{
				tree->child.clear();
			}
		}
		else
		{
			remove_less_than_min(tree->child[i]);	
		}
		
	}
}
bool comp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second>p2.second;
}
void linkallnextinfp(fpptr tree,map<int,int> m)
{
	int i;
	auto it=m.begin();
	vec.clear();
	for(;it!=m.end();it++)
	{
		vec.push_back({it->first,it->second});
	}
	sort(vec.begin(),vec.end(),comp);
//	for(i=0;i<vec.size();i++)
//	{
//	//	cout<<"vec->data = "<<vec[i].first<< "  "<<vec[i].second<<endl;
//	}
	
	linkallnextcondi(tree);

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
void conditionalbase(fpptr t);
void frequentpattern(fpptr tree)
{
	vector<int> v;
	int i;
	myvec.clear();
	int root=tree->data;
	cout<<"Frequent Patterns For "<<root<<" are \n";
	if(tree->child.size()==1)
	{
		while(tree->child.size()>0)
		{
			v.push_back(tree->child[0]->data);
			tree=tree->child[0];
		}
	vector<int> cur;
	generateall(v,cur,0,0);
	for(i=0;i<myvec.size();i++)
	{
		cout<<"{ "<<root<<" ,";
		for(int j=0;j<myvec[i].size();j++)
		{
			cout<<myvec[i][j]<<",";
		}
		cout<<"}";
		cout<<endl;
	}
	cout<<endl<<endl;
	
		
	}
	
	else
	{
		//conditionalbase(tree);
	}
//	for(i=0;i<v.size();i++)
//	{
//		cout<<v[i]<<" ";
//	}

	
	
	
	
}
void conditionalbase(fpptr t)
{
	int i;
	
	for(i=header.size()-1;i>0;i--)
	{
		for(int j=0;j<100;j++)
		condilink[j].clear();
		
		condiheader.clear();
		
		fpptr tree=NULL;
		tree=createcondi(header[i]);
		cout<<"Conitional Pattern Base \n";
		cout<<endl;
		print(tree);
		remove_less_than_min(tree);
		cout<<"Conditional FP Tree\n";
		map<int,int> uniquekey;
		printFP(tree,uniquekey);
		cout<<endl;
		linkallnextinfp(tree,uniquekey);
		frequentpattern(tree);
	//	cout<<"MEET ME LATER\n";
	//	createheader();
	//conditional.push_back(tmp);
	}
}

void sortonsecond(vector<int> &temp)//Sorting the Transaction on the basis of the frequency of items
{
	map<int,int> m;
	int i;
	for(i=0;i<vec.size();i++)
	{
		m[temp[i]]=1;
	}
	auto it=m.begin();
	int j=0;
	for(i=0;i<vec.size();i++)
	{
		if(m.find(vec[i].first)!=m.end())
		{
			temp[j++]=vec[i].first;
		}
	}
	for(i=0;i<temp.size();i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<endl;
	
}
int main()
{
	ifstream fin;
	fin.open("f1.txt");
	string s;
	getline(fin,s);
	map<int,int> m;
	while(!fin.eof())
	{
		getline(fin,s);
		vector<int> temp;
		temp=getdata(s);
		for(int i=0;i<temp.size();i++)
		{
			m[temp[i]]++;
		}
	}
	fin.close();
	auto it=m.begin();
	while(it!=m.end())
	{
		vec.push_back({it->first,it->second});
		it++;
	}
	sort(vec.begin(),vec.end(),comp);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
	fpptr root= new fpnode;
	root->data=-1;
	root->parent=NULL;
	root->count=0;
	fin.open("f1.txt");
	getline(fin,s);
	while(!fin.eof())
	{
		getline(fin,s);
		vector<int> temp;
		temp=getdata(s);
		sortonsecond(temp);
		create(root,temp,0);
	}
	print(root);
	linkallnext(root);
	conditionalbase(root);
	
	
	
	
	
	
	
	
	
	
}
