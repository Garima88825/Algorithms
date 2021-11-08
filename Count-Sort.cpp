#include<iostream>
using namespace std;

void Count_Sort(int A[],int n,int min,int max,int B[])
{
	int t=max-min+1;
	int C[t];
	
	for(int i=0;i<t;i++)
		C[i]=0;
	
	for(int j=0;j<n;j++)
		C[A[j]-min]=C[A[j]-min]+1;
		
	for(int j=1;j<t;j++)
		C[j]=C[j-1]+C[j];
		
	for(int i=n-1;i>=0;i--)
	{
		B[C[A[i]-min]-1]=A[i];
		C[A[i]-min]--;		
	}
}

int main()
{
	int n, min, max, *A, *B;
	cout<<"\n ENTER THE SIZE OF ARRAY : ";
	cin>>n;
	cout<<"\n ENTER THE MINIMUM VALUE OF ELEMENT : ";
	cin>>min;
	cout<<"\n ENTER THE MAXIMUM VALUE OF ELEMENT : ";
	cin>>max;
	cout<<"\n THE RANGE OF ARRAY : "<<min<<" to "<<max<<endl;
	
	A=new int[n];
	B=new int[n];
	cout<<"\n ENTER THE ARRAY ELEMENTS : ";
	
	for(int i=0;i<n;i++)
		cin>>A[i];
		
	Count_Sort(A,n,min,max,B);
	cout<<"\n THE SORTED ARRAY : ";
	for(int i=0;i<n;i++)
		cout<<B[i]<<" ";
	 
	return 0;
}

