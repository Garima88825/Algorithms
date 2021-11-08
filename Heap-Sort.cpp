#include<iostream>
#include<fstream>
using namespace std;

class HeapSort
{
	private:
		int n;
		int comp;
		int heapsize;
		int *A;
	
	public:
		//constructor
		HeapSort(int size)
		{
			n=size;
			A=new int[n];
			comp=0;
			heapsize=n;
		}
		
		//destructor
		~HeapSort()
		{
			delete A;
		}
		
		//input function
		void input()
		{
			for(int i=0;i<n;i++)
				A[i]=rand()%200;			
		}
		
		//max heapify
		void max_heapify(int i)
		{
			int largest=i;
			int left=2*i+1;
			int right=2*i+2;
			if(left<heapsize)
			{
				comp++;
				if(A[left]>A[i])
					largest=left;
			}
			
			if(right<heapsize)
			{
				comp++;
				if(A[right]>A[largest])
					largest=right;
			}
			if(largest!=i)
			{
				swap(A[i],A[largest]);
				max_heapify(largest);
			}
		}
		
		//build max heap
		void build_maxheap()
		{
			int x;
			
			if(n%2==0)
				x=n/2;
			else
				x=n/2-1;
				
			for(int i=x;i>=0;i--)
				max_heapify(i);
		}
		
		//heapsort function
		void HeapSort_run()
		{	
			build_maxheap();
			while(heapsize>1)
			{
				swap(A[0],A[heapsize-1]);
				heapsize--;
				max_heapify(0);	
			}
		}
		
		//function to return no. of comparisons
		int return_comp()
		{
			return comp;
		}
};

//driver code
int main()
{
	ofstream fout;
	fout.open("Heap.txt",ios::out);
	int size;
	for(int i=0;i<100;i++)
	{
		size=rand()%970+30;
		HeapSort obj(size);
		obj.input();
		obj.HeapSort_run();
		fout<<size<<"\t"<<obj.return_comp()<<"\n";
		cout<<size<<"\t"<<obj.return_comp()<<"\n";
	}
	fout.close();
	
	return 0;
}

