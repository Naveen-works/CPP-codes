
/*
//ARRAY

#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;++j)
		{
			if(arr[j]>arr[j+1])
			{
				cout << arr[j] <<"->"<<arr[j+1] <<endl;
				swap(arr[j],arr[j+1]);
			}
			count++;
		}
		
	}
	cout <<"Total moves: "<< count<<endl;
	
	
}

int main()
{
	int arr[]={9,10,7,6,2,12,18,24,19};
	int length=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,length);
	for(int num:arr)
	{
		cout << '|' <<num <<'|';
	}
	cout <<endl;
	
	return 0;
}

*/


/*
//Linked list
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
	
		Node(int data)
		{
		this->data=data;
		this->next=nullptr;		
		}
	
};

class Singly_linked_list
{
	private:
		Node* head;
		
	public:
		Singly_linked_list()
		{
			head=nullptr;
		}
		
		void insert(int data)
		{
			Node* newNode= new Node(data);
			
			if(head==nullptr)
			{
				head=newNode;
				newNode->next=nullptr;
			}
			else
			{
				Node* temp=head;
				while(temp->next!=nullptr)
				{
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->next=nullptr;	
			}
		}
		
		void swap(Node* left,Node* right)
		{
			int temp=left->data;
			left->data=right->data;
			right->data=temp;
		}
		
		void bubble_sort()
		{
			if(head==nullptr)
			return;
			
			bool swapped;
			Node* ptr;
			Node* last_ptr=nullptr;
			int count=0;
			do
			{
				swapped=false;
				ptr=head;
				while(ptr->next!=last_ptr)
				{
					if(ptr->data>ptr->next->data)
					{
						cout << ptr->data <<"->"<<ptr->next->data <<endl;
						swap(ptr,ptr->next);
						swapped=true;
						
					}
					ptr=ptr->next;
					count++;
					
				}
				ptr=last_ptr;
				
				
			}while(swapped);
			cout <<"Total moves: "<< count<<endl;
		}
		
		void display()
		{
			Node* temp=head;
			while(temp!=nullptr)
			{
				cout <<'|'<<temp->data <<"|->";
				temp=temp->next;
			}
			cout << "NULL"<<endl;
		}
	
};


int main()
{
	Singly_linked_list sll;
	cout <<"--Insertion--"<<endl;
	while(true)
	{
		int data;
		cin >> data;
		if(data==0)
		{
			break;
		}
		sll.insert(data);
	}
	sll.display();
	sll.bubble_sort();
	sll.display();
	return 0;
}
*/













