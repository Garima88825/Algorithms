#include<iostream>
#include<queue>
using namespace std;
class node
{
		int data;
		node* next;
	public:
		node(int a=0,node* ptr=0)
		{
			data=a;
			next=ptr;			
		}
	friend class sll;
	friend class topological_sort;
};
class sll
{
    node* head;
    node* tail;
    
	public:
		
	sll()
	{
		head=0;
		tail=0;
	}
	
	node* return_head()
	{
		return head;
	}
	void insertend(int val)
	{
		if(head==0)
		{
			head=new node(val,0);
			tail=head;			
		}
		else
		{
			node* current=new node(val,0);
			tail->next=current;
			tail=tail->next;
		}
	}
	
	void print()
	{
		node* temp= head->next;
		while(temp!=0)
		{
			cout<<" --> "<<temp->data;
			temp=temp->next;
		}		
	}
		   		
};

class topological_sort
{
	int* indegree;
	int* order;
	sll* obj;
	int v;
	
	public:	
		topological_sort(int n)
		{
			indegree=new int[n];
			order=new int[n];
			obj = new sll[n];
			v=n;
			for(int i=0;i<n;i++)
			{
				obj[i].insertend(i+1);
			}
		}		
		
		void input()
		{
			int conn=1;
			for(int i=0;i<v;i++)
			{
				int x;
				
				cout<<"\n ENTER THE NO. OF NODES CONNECTED TO '"<<conn<<"' : ";
				cin>>x;
				int str[x];
				
				if(x != 0)
					cout<<" ENTER THE NODES CONNECTED TO IT : ";
					
				for(int k=0;k<x;k++)
					cin>>str[k];
				conn++;
				
				for(int j=0;j<x;j++)
				{					
					obj[i].insertend(str[j]);
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
		
		void topo_sort_run()
		{
			int index=0;
			for(int i=0;i<v;i++)
				indegree[i]=0;
			
			for(int i=0;i<v;i++)
				{
					node* temp = obj[i].return_head();
					cout<<"\n value of obj[i] ka head : "<<temp->data<<endl;
					
					temp=temp->next;
					
					
					while(temp != 0)
					{
						
						int y=temp->data;
						indegree[y-1]++;
						temp=temp->next;
					}
				}
				int j;
				int flag=0;
				for(j=0;j<v;j++)
				{
					for(int k=0;k<v;k++)
					{
						if(indegree[k]==0)
						{
							order[j]=k+1;
							node* curr=obj[k].return_head();
							curr=curr->next;
							while(curr!=0)
							{
								int z=curr->data;
								indegree[z-1]--;
								curr=curr->next;
							}
							indegree[k]=-1;
							flag=1;
							break;
						}
					}
					if(flag==0)
						break;
				}

			cout<<"\n\n THE TOPOLOGICAL ORDERING : ";
			for(int i=0;i<v;i++)
				cout<<order[i]<<" ";
		}		
};

int main()
{
	cout<<" <------------TOPOLOGICAL SORT------------>\n";
	int n;
	cout<<" ENTER THE NUMBER OF VERTICES IN THE GRAPH : ";
	cin>>n;
	cout<<" THE VERTICES ARE  : ";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" ";
	}
	cout<<endl;
	topological_sort tg(n);
	
	tg.input();
	tg.display();
	tg.topo_sort_run();
	
}
