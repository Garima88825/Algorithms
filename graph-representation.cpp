#include<iostream>
using namespace std;
class sll;
class node
{
		char data;
		node* next;
	public:
		node(char a='\0',node* ptr=0)
		{
			data=a;
			next=ptr;			
		}
	friend class sll;
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

class adj_list
{
	sll* obj;
	int v;
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
			char ch='A';
			for(int i=0;i<v;i++)
			{
				int x;
				
				cout<<"\n ENTER THE NO. OF NODES CONNECTED TO '"<<ch<<"' : ";
				cin>>x;
				char str[x];
				cout<<" ENTER THE NODES CONNECTED TO IT : ";
				for(int k=0;k<x;k++)
					cin>>str[k];
				ch++;
				
				for(int j=0;j<x;j++)
				{					
					obj[i].insertend(str[j]);
				}
			}
		}
		
		void display()
		{
			char ch='A';
			cout<<"\n\n ADJACENCY LIST";
		
			for(int i=0;i<v;i++)
			{
				cout<<"\n "<<ch<<" ";
				ch++;
				obj[i].print();		
			}
		}
};

int main()
{
	int n;
	cout<<" ENTER THE NUMBER OF VERTICES IN THE GRAPH : ";
	cin>>n;
	char ch='A';
	cout<<" THE VERTICES ARE  : ";
	for(int i=0;i<n;i++)
	{
		cout<<ch++<<" ";
	}
	cout<<endl;
	adj_list obj(n);
	obj.input();
	obj.display();
}







