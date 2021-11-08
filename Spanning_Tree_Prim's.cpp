#include<iostream>
using namespace std;

class PriorityHeap
{
	int **A;
	int heapSize=0;

	public:
		
		PriorityHeap(int v)
		{
			A=new int* [v];
			
			for(int i=0;i < v;i++)
				A[i]=new int[2];			
		}
		
		void decrease_key(int vertex,int key)
		{
			A[vertex][1]=key;
			
			int t;
			if(vertex%2 == 0)
				t=vertex/2-1;
			else
				t=vertex/2;
				
			while(vertex > 0 && A[t][1]>A[vertex][1])
			{
				swap(A[vertex],A[t]);
				vertex=t;
				
				if(vertex%2==0)
					t=vertex/2-1;
				else
					t=vertex/2;
			}
		}
		void insert(int vertex,int key)
		{
			
			A[heapSize][0]=vertex;
			A[heapSize][1]=key;
			
			heapSize++;
			
			int i=heapSize-1;
			
			int t;
			if(i%2==0)
				t=i/2-1;
			else
				t=i/2;
				
			while(i>0 && A[t][1]>A[i][1])
			{
				swap(A[i],A[t]);
				i=t;
				if(i%2==0)
					t=i/2-1;
				else
					t=i/2;
			}
		}
				
		int return_size()
		{
			return heapSize;
		}
		
		int findIndex(int vertex)
		{
			for(int i=0;i<heapSize;i++)
			{
				if(A[i][0]==vertex)
				return i;
			}
			return -1;
		}
		
		int extract_min()
		{
			if(heapSize==0)
				return 0;
				
			int min = A[0][0];
			A[0] = A[heapSize-1];
			heapSize--;
	
			min_heapify(0);
			return min;
		}
		
		void min_heapify(int i)
		{
			int smallest;
			int l=2*i+1;
			int r=2*i+2;
			
			if(l<heapSize && A[l][1]<A[i][1])
				smallest=l;
			else 
				smallest=i;
				
			if(r<heapSize && A[r][1]<A[smallest][1])
				smallest=r;
			if(smallest!=i)
			{
				swap(A[smallest],A[i]);
				min_heapify(smallest);
			}
		}
};

class node
{
		int data;
		int cost;
		node* next;
		public:
		node(int a=0,int c=0,node* ptr=0)
		{
			data=a;
			cost=c;
			next=ptr;			
		}
		node(int a=0,node* ptr=0)
		{
			data=a;
			next=ptr;			
		}
	friend class sll;
	friend class adj_list;
};

class sll
{
    node* head;
    
	public:
		
	sll()
	{
		head=0;
	}
	
	~sll()
	{
		node* current=head;
		while(current != 0)
		{
			node* next=current->next;
			delete current;
			current=next;
		}
		head=0;
	}	
	
	void insertend(int v,int weight)
		{
			head=new node(v,weight,head);
		}
		
	void insertend(int v)
		{
			head=new node(v,head);
		}
	
	void print()
	{
		node* temp= head;
		while(temp->next != 0)
		{
			cout<<" --> "<<temp->data<<","<<temp->cost;
			temp=temp->next;
		}		
	}
	friend class adj_list;
		   		
};

class adj_list
{
	sll* obj;
	int v;
	int* key;
	int* parent;
	public:
		adj_list(int n)
		{
			obj = new sll[n];
			v=n;
			for(int i=0;i<n;i++)
			{
				obj[i].insertend(i+1);
			}
		}
		int vertices()
		{
			return v;
		}
		
		void input()
		{
			for(int i=0;i<v;i++)
			{
				int x;				
				cout<<"\n ENTER THE NO. OF NODES CONNECTED TO '"<<i+1<<"' : ";
				cin>>x;
				
				int v,w;
				cout<<" ENTER THE NODES CONNECTED TO IT ALONG WITH THE WEIGHT : \n";
				for(int k=0;k<x;k++)
				{
					cin>>v>>w;
					obj[i].insertend(v,w);
				}
			}
		}
		
		void display()
		{
			cout<<"\n\n ADJACENCY LIST";
		
			for(int i=0;i<v;i++)
			{
				cout<<"\n "<<i+1<<" ";
				obj[i].print();		
			}
		}
		
		void printMST()
		{
			cout<<"\n\n MINIMUM SPANNING TREE";
			cout<<"\n ----------------------";
			cout<<"\n  EDGE \t    WEIGHT";
			for(int i = 1; i < v ; i++)
				cout<<"\n "<<parent[i]+1<<" to "<<i+1<<"\t\t"<<key[i]<<endl;
				
			int weight = 0;
			for(int i=1;i<v;i++)
				weight+=key[i];
			cout<<"\n\nTotal cost: "<<weight;
		}
		
		void prim_run()
		{
			int s;
			parent=new int[v];
			key=new int[v];
			
			for(int i=0;i<v;i++)
			{
				key[i]=INT_MAX;
				parent[i]=0;
			}
			
			key[0]=0;
			PriorityHeap Q(v);
			
			for(int i=0;i<v;i++)
				Q.insert(i,key[i]);
				
			while(Q.return_size() != 0)
			{
				s=Q.extract_min();
				node *temp = obj[s].head; 
				
				while(temp!=0)
				{
					int d=temp->data - 1;
					if(Q.findIndex(d) >= 0 && (temp->cost < key[d]))
					{
						int t = Q.findIndex(d);
						parent[d]=s;
						key[d]=temp->cost;
						Q.decrease_key(t,key[d]);
					}
					
					temp = temp->next;
				}
			}
			printMST();
		}
};

int main()
{
	int n;
	cout<<" ENTER THE NUMBER OF VERTICES IN THE GRAPH : ";
	cin>>n;
	cout<<" THE VERTICES ARE  : ";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" ";
	}
	cout<<endl;
	adj_list obj(n);
	obj.input();
	obj.display();
	obj.prim_run();
	
	return 0;
}

