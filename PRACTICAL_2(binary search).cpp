#include<iostream>
using namespace std;

int binary_search(int ar[], int left, int right, int x, int &c) 
{ 
	int m;
	c=0;
	while(left <= right) 
	{ 
		c++;
		m = left + (right - left) / 2; 
		if (ar[m] == x) 
			return m; 
		if (ar[m] < x) 
			left = m + 1;  
		else
			right = m - 1; 
	} 
	return -1; 
} 
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
	int flag1;
	int flag2=1;
	for(int i=0;i<n;)
	{
		cout<<" ENTER THE ELEMENT AT INDEX "<<i<<" THE ARRAY : ";
		cin>>x;
		flag1=check(x,i,ar);
		if(i!=0 && x<ar[i-1])
			flag2=0;
		if(flag1==1 && flag2==1)	
			ar[i++]=x;
		else if(flag2==0)
			{
				cout<<"\n SORRY ! YOU ARE TRYING TO ENTER AN UNORDERED ELEMENT.KINDLY ENTER AN ORDERED NUMBER\n";
				flag2=1;
			}
		else
			cout<<"\n SORRY ! YOU ARE TRYING TO ENTER A DUPLICATE ELEMENT.KINDLY ENTER A DISTINCT NUMBER\n";	
	}
}

int main()
{
	int c=0;
	int n;
	cout<<" ENTER THE SIZE OF ARRAY : ";
	cin>>n;
	int *ar;
	ar=new int[n];
	input(ar,n);
	display(ar,n);
	int x;
	char ch;
	do{
		cout<<" ENTER THE ELEMENT YOU WANT TO SEARCH IN THE ARRAY : ";
		cin>>x;
		int result = binary_search(ar,0,n-1,x,c); 
		if(result == -1) 
			cout<<" SEARCH FAILED ! ELEMENT NOT FOUND";
		else
			{
				cout<<" ELEMENT FOUND AT INDEX POSITION :  " <<result;
				cout<<"\n THE NUMBER OF COMPARISONS : "<<c<<endl;
			}
			
			
		cout<<"\n\n DO YOU WANT TO CONTINUE AND SEARCH ANOTHER ELEMENT ( Y/N ) : ";
		cin>>ch;
	}
	while(ch=='Y' || ch=='y');
		
	return 0; 
	
}






