#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Interval
{
	int n;
	vector<vector<int>> vect;
	int *p, *m;
	
	public:
		Interval(int size)
		{
			n=size;
			p=new int[size+1];
			m=new int[size+1];
		}
		
		void input()
		{
			int start,end,value;
			
			for(int i=0;i<n;i++)
			{
				vector<int> v;
				cout<<"\n "<<i+1<<" th INTERVAL \n";
				cout<<"\n ENTER THE START TIME : ";
				cin>>start;
				v.push_back(start);
				cout<<" ENTER THE END TIME : ";
				cin>>end;
				v.push_back(end);
				cout<<" ENTER THE VALUE : ";
				cin>>value;
				v.push_back(value);
				vect.push_back(v);
				v.resize(0);		
			}
		}
		
		void schedule_sort()
		{
			sort(vect.begin(),vect.end(),[](const vector<int>& v1,const vector<int>& v2)
			{
				return v1[1] < v2[1];
			});
			
			cout<<"\n\n START\tEND\tWEIGHT\n";
			for(int i=0;i<n;i++)
			{
				cout<<" "<<vect[i][0]<<"\t"<<vect[i][1]<<"\t"<<vect[i][2]<<endl;
			}
		}
		
		void arrayP()
		{
			p[0]=0;
			for(int i=0;i<n;i++)
			{
				p[i+1]=0;
				for(int j=i-1;j>=0;j--)
				{
					if(vect[j][1] <= vect[i][0])
					{
						p[i+1]=j+1;
						break;
					}
				}
			}
			
			cout<<"\n\n Array p[j] : ";
			for(int i=0;i<n+1;i++)
				cout<<p[i]<<" ";
		}
		
		int compute_opt()
		{
			cout<<endl;
			m[0]=0;
			for(int i=1;i<=n;i++)
			{
				m[i]=max(vect[i-1][2] + m[p[i]], m[i-1]);
			}
			cout<<"\n Array M[ ] : ";
			for(int i=0;i<=n;i++)
			{
				cout<<m[i]<<" ";
			}
			cout<<endl;
			return m[n];
		}
		
		void find_solution(int j) 
		{
			if(j==0)
				return;
			else
			{
				if(vect[j-1][2] + m[p[j]] >= m[j-1])
				{
					cout<<" "<<vect[j-1][0]<<" TO "<<vect[j-1][1]<<" WITH WEIGHT : "<<vect[j-1][2]<<"\n";
					find_solution(p[j]);
				}
				else
					find_solution(j-1);
			}
		}				
};

int main()
{
	int n;
	cout<<"\n WEIGHTED INTERVAL SCHEDULING";
	cout<<"\n ----------------------------";
	cout<<"\n ENTER THE NUMBER OF INERVALS : ";
	cin>>n;
	
	Interval obj(n);
	obj.input();
	obj.schedule_sort();
	obj.arrayP();
	
	int maximum = obj.compute_opt();
	cout<<endl<<" MAXIMUM WEIGHT SUM : "<<maximum;
	cout<<endl<<"\n COMPATIBLE INTERVALS WHICH GIVE MAXIMUM SUM OF WEIGHTS : ";
	cout<<"\n ------------------------------------------------------\n";
	obj.find_solution(n);
		
	return 0;	
}
