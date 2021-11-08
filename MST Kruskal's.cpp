#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
	
	node* return_head()
	{
		return head;
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

class Disjoint
{
	int v;
	int* v_set;
	int* size;
	
	public:
		
		Disjoint(int vertex)
		{
			v=vertex;
			size=new int[v];
			for(int i=0;i<v;i++)
				size[i]=1;
				
			cout<<"\n\n size START : ";
			for(int i=0;i<v;i++)
				cout<<size[i]<<" ";
			cout<<endl;
			
			v_set=new int[v];			
		}
		
		void makeSet()
		{
			for(int i=0;i<v;i++)
				v_set[i]=i+1;
			cout<<"\n v_set START : ";
			for(int i=0;i<v;i++)
				cout<<v_set[i]<<" ";
			cout<<endl;
		}
		
		
		int findSet(int vertex)
		{
			return v_set[vertex-1];
		}
		
		int findSize(int vertex)
		{
			return size[vertex-1];
		}
		
		void setUnion(int s,int d)
		{			
			int sset=findSet(s);
			int dset=findSet(d);
			
			if(findSize(sset) <= findSize(dset))
			{
				for(int i=0;i<v;i++)
				{
					if(v_set[i] == sset)
					{
						v_set[i]=dset;
						size[dset-1]++;
					}
				}		
			}
			else
			{
				for(int i=0;i<v;i++)
				{
					if(v_set[i] == dset)
					{
						v_set[i]=sset;
						size[sset-1]++;
					}
				}
			}
		}	
};

class adj_list
{
	sll* obj;
	int v;
	int edge;
	
	public:
		adj_list(int n)
		{
			obj = new sll[n];
			v=n;
			edge=0;
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
				edge+=x;
				
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
			cout<<"\n\n TOTAL NUMBER OF EDGES IN THE GRAPH : "<<edge<<endl;
		}
		
		void displayMST(vector<vector<int>> A)
		{
			cout<<"\n MINIMUM SPANNING TREE";
			cout<<"\n ----------------------";
			cout<<"\n\n  EDGE\t\tCOST\n ----------------------\n";
			int weight_sum=0;
			for(int i=0;i<A.size();i++)
			{
				weight_sum+=A[i][1];
				cout<<"\n "<<A[i][0]<<" to "<<A[i][2]<<"\t\t  "<<A[i][1]<<endl;
			}
			cout<<"\n\n TOTAL COST : "<<weight_sum;
		}
		
		void mst_kruskal()
		{
			Disjoint Ob(v);
			Ob.makeSet();
			vector<vector<int>> A;
			vector<vector<int>> vect;
			
			for(int i=0;i<v;i++)
			{
				vector<int> vv;
				node* curr=obj[i].return_head();
				
				while(curr)
				{					
					if(curr->data > i+1)         // 1 -->2,3 -->3,4
					{
						vv.push_back(i+1);
						vv.push_back(curr->cost);
						vv.push_back(curr->data);
						vect.push_back(vv);				
					}
					vv.resize(0);
					curr=curr->next;
				}				
			}
			cout<<"\n EDGE SET BEFORE SORTING";
			cout<<"\n\n SOURCE\t COST\tDESTINATION\n ---------------------------\n";
			
			for(int i=0;i<vect.size();i++)
			{
				for(int j=0;j<3;j++)
					cout<<"  "<<vect[i][j]<<"\t";
				cout<<endl;
			}
			
			sort(vect.begin(),vect.end(),[](const vector<int>& v1,const vector<int>& v2)
			{
				return v1[1] < v2[1];
			});	
			
			cout<<"\n EDGE SET AFTER SORTING";
			cout<<"\n\n SOURCE\t COST\tDESTINATION\n ---------------------------\n";
			
			for(int i=0;i<vect.size();i++)
			{
				for(int j=0;j<3;j++)
					cout<<"  "<<vect[i][j]<<"\t";
				cout<<endl;
			}
			
			int s,d;
			for(int i=0;i<vect.size();i++)
			{
				s=vect[i][0];
				d=vect[i][2];
				vector<int> B;
				
				if(Ob.findSet(s) != Ob.findSet(d))
				{
					B.push_back(s);
					B.push_back(vect[i][1]);
					B.push_back(d);
					A.push_back(B);
					Ob.setUnion(s,d);
				}
				B.resize(0);
			}
			
			displayMST(A);			
		}
		
		friend class Disjoint;
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
	obj.mst_kruskal();
	
	return 0;
}


