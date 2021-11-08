#include<iostream>
#include<vector>
using namespace std;

class Knapsack_01
{
	int W;
	int n;
	int* weight;
	int* value;
	int** M;
	vector<int> vect;
	
	public:
		Knapsack_01(int size,int WW)
		{
			W=WW;
			n=size;
			
			M = new int* [n+1];
			for(int i=0;i <= n;i++)
				M[i]=new int[W+1];
				
			weight=new int[n];
			value=new int[n];
		}
		
		void input()
		{
			cout<<"\n\n ENTER THE WEIGHTS AND VALUES OF EACH ITEM\n";
			for(int i=0;i<n;i++)
			{
				cout<<" ENTER WEIGHT FOR ITEM "<<i+1<<" : ";
				cin>>weight[i];
				cout<<" ENTER VALUE FOR ITEM "<<i+1<<" : ";
				cin>>value[i];
				cout<<endl;
			}	
		}
		
		int SubsetSum()
		{
			for(int i=0;i<=W;i++)
				M[0][i]=0;
				
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=W;j++)
				{
					if(j<weight[i-1])
						M[i][j] = M[i-1][j];
					else
						M[i][j] = max( M[i-1][j] , value[i-1]+M[i-1][j-weight[i-1]] );
				}
			}
			return M[n][W];
		}
		
		void FindSolution(int i,int j)
		{
			if(i==0 || j==0)
				return;
			else
			{
				if(j<weight[i-1])
					FindSolution(i-1,j);	
				else
				{
					if(M[i-1][j] >= value[i-1]+M[i-1][j-weight[i-1]])
					{
						//vect.push_back(i-1);
						FindSolution(i-1,j);	
					}
					else
					{
						vect.push_back(i);
						FindSolution(i-1,j-weight[i-1]);
					}
					
				}
			}			
		}
		
		void display()
		{			
			for(int i=vect.size()-1;i>=0;i--)
				cout<<" ITEM-"<<vect[i]<<"  ";
			cout<<endl;
		}
};

int main()
{
	int n;
	cout<<"\n ENTER THE NUMBER OF ITEMS : ";
	cin>>n;
	cout<<"\n ITEMS ARE : ";
	for(int i=0;i<n;i++)
		cout<<"I"<<i+1<<" ";
	int W;
	cout<<"\n ENTER THE BOUND : ";
		cin>>W;
	Knapsack_01 obj(n,W);
	obj.input();
	int ans = obj.SubsetSum();
	cout<<"\n\n ANSWER = "<<ans;
	obj.FindSolution(n,W);
	cout<<"\n SOLUTIONS : ";
	obj.display();
		
	return 0;	
}

