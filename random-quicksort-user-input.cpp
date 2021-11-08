#include<iostream>
using namespace std;

int total_comp;

int partition(int ar[],int p,int r)
{
	int x;
	x=ar[r];
	int i=p-1;
	int j;
	int c=0;
	for(j=p;j<r;j++)
	{
		c++;
		if(ar[j] <= x)
		{
			i=i+1;
			int temp;
			
			temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}
	int t;
			
	t=ar[i+1];
	ar[i+1]=ar[r];
	ar[r]=t;
	
	total_comp+=c;
	return (i+1);
}

int random(int p,int r)
{
	int x=( rand() % (r-p) ) + p;
	return x;
}

int random_partition(int ar[],int p,int r)
{
	int i = random(p,r);
	int t;
	t=ar[r];
	ar[r]=ar[i];
	ar[i]=t;
	
	return partition(ar,p,r);
}

void random_quicksort(int ar[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=random_partition(ar,p,r);
		random_quicksort(ar,p,q-1);
		random_quicksort(ar,q+1,r);
	}
	
}

void print(int ar[],int n)
{
	cout<<"\n THE SORTED ARRAY IS : ";
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
		
	cout<<"\n\n TOTAL NUMBER OF COMPARISONS  : "<<total_comp;
}

int main()
{
	int n;
	char ch;
	do
	{
		total_comp=0;
		cout<<"\n ENTER THE SIZE OF ARRAY : ";
		cin>>n;
		int ar[n];
		
		cout<<" ENTER THE ELEMENTS : ";
		for(int i=0;i<n;i++)
			cin>>ar[i];
		cout<<endl;
		
		random_quicksort(ar,0,n-1);	
		print(ar,n);
		
		cout<<"\n\n DO YOU WANT TO CONTINUE : ";
		cin>>ch;
	}
	while(ch == 'Y' || ch == 'y');
	
	return 0;
}
