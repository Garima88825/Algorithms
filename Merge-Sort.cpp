#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void merge(int arr[], int p, int q, int r,int &comp)
{
    int n1 = q - p + 1;
    int n2 = r - q;
 
    int* L=new int[n1+1];
	int* R=new int[n2+1];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
 
    int i = 0;
    int j = 0;
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    int k = p;
 	
 	for( ;k<=r;k++)
 	{
 		comp++;
 		if(L[i]<=R[j])
 		{
 			arr[k]=L[i];
 			i=i+1;
		}
		else
		{
			arr[k]=R[j];
			j=j+1;
		}
	}
	delete L;
	delete R;
}
 
void mergeSort(int arr[],int p,int r,int &comp){
    if(p<r)
    {
	    int q =p+ (r-p)/2;
	    mergeSort(arr,p,q,comp);
	    mergeSort(arr,q+1,r,comp);
	    merge(arr,p,q,r,comp);
	}
}
 
 

int main()
{		
		ofstream fout;
		fout.open("merge.txt",ios::out);
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
			
			mergeSort(ar,0,n-1,comp);
			delete ar;
			fout<<n<<"\t"<<comp<<endl;
			cout<<n<<"\t"<<comp<<endl;
		}
		
		fout.close();
	    return 0;
}
