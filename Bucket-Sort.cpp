#include<iostream>
#include<math.h>
using namespace std;

// node class
class node
{
	node* prev;
	int val;
	node* next;
	
	public:
		node(node* ptr=0,int a=0,node* ptr1=0)
		{
			prev=ptr;
			val=a;
			next=ptr1;
		}
		friend class DLL;
		friend class BucketSort;
};

// DLL class
class DLL
{
	node* head;
	node* tail;
	
	public:
		// DLL constructor
		DLL()
		{
			head = new node(0,0,tail);
			tail= new node(head,0,0);
			head->next = tail;
		}
		
		// is list empty?
		bool empty() const
		{
			return(head->next == tail); 
		}
		
		// to display the numbers in each bucket
		void display()
		{
			node *curr;
			for(curr=head->next;curr!=tail;curr=curr->next)
				cout<<curr->val<<" ";
		}
		
		// inserting at tail 
		void add(node* ptr,int a)
		{
			node* current=ptr->prev;
			current->next=ptr->prev=new node(current,a,ptr);
			return;
		}
		
		void addToTail(int a)
		{
			add(tail,a);
			return;
		}
		
		node* returnHead()
		{
			return head;
		}
		
		node* returnTail()
		{
			return tail;
		}
		
		friend class BucketSort;
};

// BucketSort class
class BucketSort
{
	int *ar;
	DLL *B;
	int n;
	float max=INT_MIN;
	
	public:
		
		// constructor
		BucketSort(int size)
		{
			n=size;
			ar=new int[n];
			B=new DLL[n];
		}
		
		// destructor
		~BucketSort()
		{
			delete ar;
		}
		
		// input function to take the array elements
		void input()
		{
			cout<<"\n ENTER THE ARRAY ELEMENTS : ";
			for(int i=0;i<n;i++)
				cin>>ar[i];
		}
		
		// finding the maximum element in the array
		void findMax()
		{
			for(int i=0;i<n;i++)
			{
				if(ar[i]>max)
					max=ar[i];
			}			
		}
		
		// sorting the numbers in each bucket using insertion sort
		void ListSort(DLL& list)
		{
			if(list.empty())       // if bucket is empty
				return;
				
			node* temp;
			int key;
			temp=list.returnHead()->next;
			
			if(temp->next == list.returnTail())    // if bucket has only single element so it is already sorted
				return;
				
			else                                   // if bucket has more than one element
			{
				temp=temp->next;
				do
				{
					key=temp->val;
					node *curr=temp->prev;
					while(curr != list.returnHead() && curr->val>key)
					{
						curr->next->val=curr->val;
						curr=curr->prev;
					}
					curr->next->val=key;
					temp=temp->next;
				}
				while(temp != list.returnTail());
				
	
			} 			
			return;								
		}
		
		// to display the buckets
		void print(DLL B[])
		{
			cout<<"\n";
			for(int i=0;i<n;i++)
			{
				cout<<" "<<i<<"-> ";
				B[i].display();
				cout<<"\n";	
			}
		}
		
		// to concat the sorted numbers in each bucket
		void concat()
		{
			int* result = new int[n];
			int x = 0;
			
			for(int i=0;i<n;i++)
			{
				if(B[i].empty())        // if list is empty
					continue;
				
				else
				{
					node* current=B[i].returnHead()->next;
					while(current != B[i].returnTail()) // traversing each bucket and storing its numbers in an array
					{
						result[x++] = current -> val;
						//cout<<current->val<<" ";
						current=current->next;
					}
				}				
			}
			
			// displaying the sorted array
			cout<<"\n THE SORTED ARRAY : ";
			for(int i=0;i<n;i++)
			{
				cout<<result[i]<<" ";
			}
		}
		
		// bucket sort function		
		void bucketSort_run()
		{
			findMax();      // maximum element
			
			float range;
			int j;
			range=ceil((max+1)/n);       // finding range of each bucket
			
			for(int i=0;i<n;i++)         // inserting elements in the bucket
			{
				j=floor(ar[i]/range);
				B[j].addToTail(ar[i]);
			}
			cout<<"\n BUCKETS BEFORE SORTING : \n";	
			print(B);
			
			// sorting the numbers in bucket by calling ListSort function
			for(int i=0;i<n;i++)
			{
				ListSort(B[i]);
			}
			cout<<"\n BUCKETS AFTER SORTING : \n";
			print(B);	
					
			concat();	      // concatenating the buckets			
		}
};

// main method
int main()
{
	int n;
	cout<<"\n ENTER THE SIZE OF ARRAY : ";
	cin>>n;
	
	BucketSort obj(n);
	
	obj.input();
	obj.bucketSort_run();
	
	return 0;
}

// 78 17 39 26 72 94 21 12 23 68
// 4 7 6 1 11 9 10 3 8 2
