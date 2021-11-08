#include<iostream>
using namespace std;

class RadixSort
{
	int *arr;
	int n;
	int mx = INT_MIN;
	
	public:
		
		//constructor
		RadixSort(int size)
		{
			n = size;
			arr = new int[n];
		}
		
		//destructor
		~RadixSort()
		{
			delete[] arr;
		}
		
		//count sort run
		void countSort(int m)
		{
			int *temp, count[10];            //range of digit can be 0 to 9
			temp = new int[n];
			
			for(int i=0;i<10;i++)
				count[i]=0;
				
			for(int i = 0 ; i < n ; i++)     // frequency calculation
				count[(arr[i]/m)%10]++; 
				
			for(int i = 1; i < 10; i++)      // cumulative frequency
				count[i] += count[i-1];
				
			for(int i =n-1; i >=0 ; i--)     // inserting the elements at correct position in temp array
			{
				temp[count[(arr[i]/m)%10]-1]=arr[i];			
				count[(arr[i]/m)%10]--;  	
			}
			arr=temp;                        // copying elements of temp array to arr array
		}
		
		//radix sort input
		void _init_sort()
		{
			int temp;
			cout<<"\n ENTER THE ARRAY ELEMENTS : ";
			
			for(int i = 0; i < n ; i++)     // finding the maximum element
			{
				cin>>temp;
				arr[i] = temp;
				mx = mx > temp ? mx : temp;			
			}
						
			for(int i = 1; mx > 0 ; i*=10, mx/=10)    // loop will iterate the (maximum no of digits) times 
				countSort(i);
		}
		
		//function to display the sorted array
		void displayArray()
		{
			cout<<"\n THE SORTED ARRAY : ";
			for(int i = 0 ; i < n; i++)
				cout<<arr[i]<<" ";
		}		
};

//driver code
int main()
{
	int n;
	cout<<"\n ENTER THE SIZE OF ARRAY : ";
	cin>>n;
	
	RadixSort obj(n);
	obj._init_sort();
	obj.displayArray();
	
	return 0;
}
