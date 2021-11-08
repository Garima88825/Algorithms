#include<iostream>
using namespace std;

void print(int A[],int n)
{
	cout<<" THE SORTED ARRAY : ";
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
}

void radix_sort_run(int A[],int n,int d, int b[])
{
	int num,x[n];
	int min,max;
	int z=1;
	
	for(int i=0;i<n;i++)
		b[i]=A[i];
					
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<n;j++)
			A[j]=b[j];
		
		z*=10;
		
		//inserting the digit at ith place in an array x				
		for(int j=0;j<n;j++)				
		{								
			num=b[j]%z;  	
			x[j]=num/(z/10);
		}		
				
		min=max=x[0];
		
		//finding the range						
		for(int k=1;k<n;k++)
		{
			if(x[k]>max)
				max=x[k];
				
			else if(x[k]<min)
				min=x[k];
		}
		
		//running count sort
		int y=max-min+1;
		int count[y]={0};
		
		for(int l=0;l<n;l++)					//counting number of occurences of elements of array x
			count[x[l]-min]=count[x[l]-min]+1;
			
		for(int l=1;l<y;l++)					//calculating cumulative frequency
			count[l]=count[l-1]+count[l];
			
		for(int k=n-1;k>=0;k--)                 //sorting and inserting in array b
		{		
			b[count[x[k]-min]-1]=A[k];
			count[x[k]-min]--;
		}
	}
	//calling the print function to display the sorted array
	print(b,n);
}

//function to count the maximum no of digits
int count_maxDigit(int A[],int n)
{
	int max=0;
	int num;
	int c;
	for(int i=0;i<n;i++)
	{
		c=0;
		num=A[i];
		
		while(num != 0)
		{
			c++;
			num=num/10;
		}
		
		if(c > max)
			max=c;		
	}
	return max;
}

//main function
int main()
{
	int n;
	char ch;
	do
	{
		cout<<"\n ENTER THE SIZE OF ARRAY : ";
		cin>>n;
		int A[n];
		int b[n];
		
		cout<<" ENTER THE ELEMENTS : ";
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<endl;
		
		int maxDigits = count_maxDigit(A,n);
		radix_sort_run(A,n,maxDigits,b);	
		
		cout<<"\n\n DO YOU WANT TO CONTINUE : ";
		cin>>ch;
	}
	while(ch == 'Y' || ch == 'y');
	
	return 0;
}

