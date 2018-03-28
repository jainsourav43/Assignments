#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define no_of_items 100
using namespace std;
int main()
{
	int transaction_count;
	srand(time(NULL));
	cout<<"Enter the no of Transaction\n";
	ofstream fout;
	fout.open("First.txt");
	cin>>transaction_count;
	fout<<"TID                                  List of item IDs\n";
	fout<<"-----------------------------------------------------------------------------------------------------------\n";
	int i;
	set<int> s;
	string id;
	for(i=1;i<=transaction_count;i++)
	{
		id='T'+to_string(i);
		s.clear();
		int items_purchased=rand()%10;
		if(items_purchased==0)
		continue;
		for(;s.size()<items_purchased ; )
		{
			s.insert(rand()%10);
		}
		fout<<id<<"      ";
		auto it=s.begin();
		for(int j=0;j<items_purchased-1;j++)
		{
			fout<<*it<<",";
			it++;
		}
		fout<<*it<<endl;
	}
	fout.close();

	
	
}
