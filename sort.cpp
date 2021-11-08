#include<iostream>
using namespace std;
template <typename T>
class Sorting
{		T size;
		T *array;
	public:
		Sorting(T arr[], int sz);
		void input();
		void show();
		void bubbleSort();
		void selectionSort();
		void insertionSort();
};

template <typename T>
Sorting<T>::Sorting(T arr[], int sz) 
{
	array= new T[sz];
	size= sz;
	for(int i=0;i<size;i++)
	array[i]= arr[i];
	
}

template <typename T>
void Sorting<T>::input() 
{
cout<<" ENTER THE ELEMENTS TO BE SORTED: ";
	for(int i = 0; i<size; i++)	
	{
		cin>>array[i];
	}
}
template <typename T>
void Sorting<T>::show() 
{
	cout<<" [";
   for(int i = 0; i<size; i++){
   		cout <<array[i] <<", ";
	}
	cout<<"\b\b]";
}

template <typename T>
void Sorting<T>::selectionSort() 
{
int c=0;
T temp;
for(int i=0;i<size;i++)
{
  for(int j=i+1;j<size;j++)
  {
  	
	c++;
	if(array[i]>array[j])
	{
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
	}
  }
}
cout<<"\n The no. of comparisons : "<<c<<endl;
}
template <typename T>
void Sorting<T>:: insertionSort()
{
	int c=0;
	T key;
int i, j;  
    for (i = 1; i < size; i++) 
    {  
        key = array[i];  
        j = i - 1;  
  
        c++;
        while (j >= 0 && array[j] > key) 
        {  if(array[j] > key)
        	c++;
        	
            array[j + 1] = array[j];  
            j = j - 1;  
        }  
        array[j + 1] = key;  
    } 
	cout<<"\n\n The no. of comparisons : "<<c<<endl; 
}

template <typename T>
void Sorting<T>:: bubbleSort() 
{	int c=0;
T temp;
for(int i=0;i<size;i++)
{
  for(int j=0;j<size-i-1;j++)
  {
  	c++;
	if(array[j]>array[j+1])
	{
		temp=array[j];
		array[j]=array[j+1];
		array[j+1]=temp;
	}
  }
}
cout<<"\n\n The no. of comparisons : "<<c<<endl;
} 

int main()
{
	int choice, size;
	int* arr;
	cout<<"\n ---------SORTING PROGRAM---------\n\n";

	char ch;	
    do
    {	cout<<" --------------------------------"<<endl;
        cout<<" 1) INSERTION SORT"<<endl;
        cout<<" 2) SELECTION SORT"<<endl;
        cout<<" 3) BUBBLE SORT "<<endl;
        cout<<" 4) EXIT"<<endl;
        cout<<" --------------------------------"<<endl;
        cout<<" ENTER YOUR CHOICE: ";
        cin>>choice;
         
        if(choice == 1)
        {
        	cout<<"\n ENTER THE SIZE OF THE ARRAY:  ";
  			cin>>size;
  			arr= new int[size];
			Sorting<int>obj(arr,size);
			obj.input();
			cout <<"\n ARRAY BEFORE SORTING: ";
   			obj.show();
    	    obj.insertionSort();
  			cout <<"\n ARRAY AFTER INSERTION SORT: "<<endl;
   			obj.show();
   			cout<<"\n"<<endl;
		}
        else if(choice == 2)
        {
        	cout<<"\n ENTER THE SIZE OF THE ARRAY:  ";
  			cin>>size;
  			arr= new int[size];
			Sorting<int>obj(arr,size);
			obj.input();
			cout <<"\n ARRAY BEFORE SORTING: ";
   			obj.show();
			obj.bubbleSort();
   			cout <<"\n ARRAY AFTER SELECTION SORT: ";
   			obj.show();
   			cout<<"\n"<<endl;
		}
             
        else if (choice == 3)
        {
        	cout<<"\n ENTER THE SIZE OF THE ARRAY:  ";
  			cin>>size;
  			arr= new int[size];
			Sorting<int>obj(arr,size);
			obj.input();
			cout <<"\n ARRAY BEFORE SORTING: ";
   		    obj.show();
			obj.bubbleSort();
  			cout <<"\n ARRAY AFTER BUBBLE SORT: ";
   			obj.show();
   			cout<<"\n"<<endl;
		}
   			
   		else
   		{
   			cout<<"EXITING...";
   			exit(0);
		}            
         
        cout<<"\n DO YOU WANT TO CONTINUE (Y/N) : ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
 
    return 0;
} 

