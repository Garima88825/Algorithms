#include<iostream>
using namespace std;

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
			
			swap(ar[i],ar[j]);
		}
	}
	swap(ar[i+1],ar[r]);		
	
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

int randomized_select(int ar[],int p,int r,int i)
{
	if(p==r)
		return ar[p];
		
	int q = random_partition(ar,p,r);
	int k = q-p+1;
	
	if(i == k)
		return ar[q];
	
	else if (i < k)
		return randomized_select(ar,p,q-1,i);
	
	else
		return randomized_select(ar,q+1,r,i-k);		
			
}

int main()
{
	int n;
	int x;
	char ch;
	do
	{
		cout<<"\n ENTER THE SIZE OF ARRAY : ";
		cin>>n;
		int ar[n];
		
		cout<<" ENTER THE ELEMENTS : ";
		for(int i=0;i<n;i++)
			cin>>ar[i];
		cout<<endl;
		
		cout<<" WHICH SMALLEST ELEMENT YOU WANT TO FIND ( ENTER THE VALUE OF i ) : ";
		cin>>x;
		
		int result = randomized_select(ar,0,n-1,x);	
		cout<<" THE "<<x<<" th SMALLEST ELEMENT : "<<result<<endl;
		
		cout<<"\n DO YOU WANT TO CONTINUE : ";
		cin>>ch;
	}
	while(ch == 'Y' || ch == 'y');
	
	return 0;
}
