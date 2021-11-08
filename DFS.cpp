#include<iostream>
#include<stack>
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
	friend class dfs_graph;
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
	void insertend(char val)
	{
		if(head)
		{
			node* current;
			for(current=head; current->next != 0; current=current->next);
		
			current->next=new node(val,0);
		}
		else
			head=new node(val,0);
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

class dfs_graph
{
	bool* explored=new bool[v];
	int* parent=new int[v];
	int* distance=new int[v];
	sll* obj;
	int v;
	public:
		dfs_graph(int n)
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
			int conn=1;
			for(int i=0;i<v;i++)
			{
				int x;
				
				cout<<"\n ENTER THE NO. OF NODES CONNECTED TO '"<<conn<<"' : ";
				cin>>x;
				int str[x];
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

		void dfs_run(int s)
		{
			
			for(int i=0;i<v;i++)
			{
				explored[i]=false;
				parent[i]=1;
				distance[i]=-1;
			}
			stack<int> st;
			explored[s-1]=true;
			distance[s-1]=0;
			st.push(s);
			while(!(st.empty()))
			{
				int u=st.top();
				st.pop();
				
				if(explored[u-1]==false)
					explored[u-1]=true;
					
				node* temp=obj[u-1].return_head();
				for(;temp != 0;temp=temp->next)
				{
					int x=temp->data;
					if(explored[x-1] == false)
					{
						st.push(x);
						parent[x-1]=u;
						distance[x-1]=distance[u-1]+1;
					}
				}
			}
			cout<<"\n VERTEX         PARENT          DISTANCE\n";
			for(int i=0;i<v;i++)
			{
				cout<<"  "<<i+1<<"\t\t"<<parent[i]<<"\t\t"<<distance[i]<<endl;
			}
			
		}	
		
		void find_path(int a,int b)
		{
			if(explored[a-1]==false || explored[b-1]==false)
				cout<<"\n THERE IS NO PATH IN BETWEEN";
				
			else{
				int path[b-a+1];
				int z=0;
				int s=a;
				int t=b;
				do
				{
					path[z]=t;
					t=parent[t-1];
					z++;
				}
				while(t!=a);
		
				cout<<"\n PATH : "<<s;
				for(int k=z-1;k>=0;k--)
					cout<<" --> "<<path[k];
			}
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
	dfs_graph obj(n);
	
	cout<<endl<<" ---------------MENU---------------";
	cout<<"\n 1.INPUT A GRAPH AND REPRESENT VIA ADJACENCY LIST";
	cout<<"\n 2.DFS TRAVERSAL AND DISPLAY THE INFO";
	cout<<"\n 3.GIVE PATH BETWEEN TWO VERTICES\n";
	char c;
	
	int source;
	int start,end;
	int ch;
	do
	{
		cout<<"\n ENTER YOUR CHOICE : ";
		cin>>ch;
				
		switch(ch)
		{
			case 1:
				obj.input();
				obj.display();
				break;
				
			case 2:
				cout<<"\n ENTER THE VERTEX YOU WANT TO START DFS FROM : ";
				cin>>source;
				
				obj.dfs_run(source);
				break;
				
			case 3:
				cout<<"\n ENTER THE START AND END VERTICES : ";
				cin>>start>>end;
				obj.find_path(start,end);			
				break;
				
			default:
				cout<<"\n WRONG CHOICE !!";
		}
		cout<<"\n\n DO TOU WANT TO CONTINUE : ";
		cin>>c;
    }while(c=='Y' || c=='y');
	
}







