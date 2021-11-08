#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int random(int p,int r)
{
	int x=( rand() % (r-p) ) + p;
	return x;
}

int partition(int ar[],int p,int r,int &comp)
{
	int x;
	x=ar[r];
	int i=p-1;
	int j;
	int count=0;
	for(j=p;j<r;j++)
	{
		count++;
		if(ar[j] <= x)
		{
			i=i+1;
			swap(ar[i],ar[j]);
		}
	}
	swap(ar[i+1],ar[r]);
	
	comp=comp+count;
	return (i+1);
}

int random_partition(int ar[],int p,int r,int &comp)
{
	int i = random(p,r);
	swap(ar[r],ar[i]);
	
	return partition(ar,p,r,comp);
}

void random_quicksort(int ar[],int p,int r,int &comp)
{
	int q;
	if(p<r)
	{
		q=random_partition(ar,p,r,comp);
		random_quicksort(ar,p,q-1,comp);
		random_quicksort(ar,q+1,r,comp);
	}
	
}

void display(int ar[],int n,int &comp)
{
	cout<<"\n Sorted array : ";
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
		
	cout<<"\n\n Total no. of comparisons  : "<<comp;
}

int main()
{		
		ofstream fout;
		fout.open("quick.txt",ios::out);
		int comp;
		int n;
		int *ar;
		
		for(int i=0;i<100;i++)
		{
			comp=0;
			n=30 + rand()%970;
			ar=new int[n];
			
			for(int j=0;j<n;j++)
			{
				ar[j]=rand()%200;
			}
			
			random_quicksort(ar,0,n-1,comp);
			delete ar;
			fout<<n<<"\t"<<comp<<endl;
			cout<<n<<"\t"<<comp<<endl;
		}
		
		fout.close();
	    return 0;
}
