#include<bits/stdc++.h>
#define null NULL
using namespace std;
typedef
struct bucket
{
	int keys[4];
	int count;
}*bptr;
bptr directory[2000];
int size,d;
void create(int key)
{
	
}
void insert(int key)
{
	char temp[10];int in,i;
	itoa(key,temp,2);
	k=strlen(temp);
	while(strlen(temp)!=size)
	{
	 for(i=0;i<strlen(temp);i++)
	 {
	 	temp[k+1]=temp[k];
	 	k--;
	 }
	}
	directory[temp[0]-48]->keys[0]=key;	
}
int main()
{
	int i,j,k;
	char temp[10];
	cout<<"Enter the initial value of d\n";
	cin>>d;
	cout<<"Enter the key to insert\n";
	cin>>k;
	size=pow(2,d);
	itoa(k,temp,2);
	bptr b1=new bucket;
	directory[0]=b1;
	directory[1]=b1;
	cout<<"b1 = "<<b1->count<<endl;
    insert(k);
}
