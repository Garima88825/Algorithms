#include<iostream>
using namespace std;

void display(int ar[],int n)
{
	cout<<"\n THE FINAL ARRAY IS : ";
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
int check(int x,int j,int ar[])
{
	int f=1;
	for(int i=0;i<j;i++)
	{
		if(ar[i]==x)
		{
			f=0;
			break;
		}
	}
	return f;
}
void input(int ar[],int n)
{
	int x;
	int flag;
	for(int i=0;i<n;)
	{
		cout<<" ENTER THE ELEMENT AT INDEX "<<i<<" THE ARRAY : ";
		cin>>x;
		flag=check(x,i,ar);
		if(flag==1)	
			ar[i++]=x;
		else 
			cout<<"\n SORRY ! YOU ARE TRYING TO ENTER A DUPLICATE ELEMENT.KINDLY ENTER A DISTINCT NUMBER\n";	
	}
}
void find(int k,int n,int ar[])
{
	int c=0;
	int index;
	int f=0;
	for(int i=0;i<n;i++)
	{
		c++;
		if(ar[i]==k)
		{
			index=i;
			f=1;
			break;
		}
	}
	if(f==1)
		{
			cout<<"\n SUCCESSFUL SEARCH !!\n NUMBER IS FOUND AT INDEX POSITION "<<index<<endl;
			cout<<" THE NUMBER OF COMPARISONS MADE : "<<c<<endl;
		}
	else
		cout<<"\n SORRY ! THE SEARCH FAILED...NUMBER NOT FOUND";
}
int main()
{
	int n;
	cout<<" ENTER THE SIZE OF ARRAY : ";
	cin>>n;
	int *ar;
	ar=new int[n];
	input(ar,n);
	display(ar,n);
	int x;
	cout<<" ENTER THE ELEMENT YOU WANT TO SEARCH IN THE ARRAY : ";
	cin>>x;
	find(x,n,ar); 
	return 0; 
}
