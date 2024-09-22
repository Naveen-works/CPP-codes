/*
//Array implementation

#include <iostream>
#include <algorithm>
using namespace std; 

int binary_search(int arr[],int value)
{
	
	int length=sizeof(arr)/sizeof(arr[0]);
	int left=0;
	int right=length-1;
	
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		cout <<"Middle element: " <<mid<< endl;
		
		if(arr[mid]==value)
		{
			return mid;
		}
		if(arr[mid]<value)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return -1;
	
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11};
	int value=3;
	
	int result=binary_search(arr,value);
	result!=-1?cout<< "Found": cout<<"Not found";
	return 0;
}
*/




#include <iostream>
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
			Node* newNode=new Node(data);
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
		
		int length()
		{
			Node* temp=head;
			int length=0;
			while(temp!=nullptr)
				{
					temp=temp->next;
					length++;
				}
				return length;
		}
		
		int Set_middle(int mid)
		{
			Node*temp=head;
			int count=0;
			while(temp!=nullptr)
			{
				if(count==mid)
				{
					return temp->data;
				}
				temp=temp->next;
				count++;
			}
		}
		
		int binary_search(int value)
		{
			int left=0;
			int right=length()-1;
			
			while(left<=right)
			{
				int mid=left+(right-left)/2;
				int midval=Set_middle(mid);
				cout << "Middle: "<<mid << endl;
				if(midval==value)
				{
					return mid;
				}
				if(midval<value)
				{
					left=mid+1;
				}
				else
				{
					right=mid-1;
				}
				
			}
			return -1;
			
		}
		
		void display()
		{
			Node* temp=head;
			while(temp!=nullptr)
			{
				cout << temp->data << "->";
				temp=temp->next;	
			}
			cout <<"NULL"<< endl;
		}
		
		
	
};




int main()
{
	Singly_linked_list sll;
	cout << "--Insertion--"<< endl;
	
	while(true)
	{
		int data;
		cin >> data;
		if(data==0)
		{
			break;
		}
		else
		{
			sll.insert(data);
		}
	}
	
	
	
	
	sll.display();
	
	
	int result=sll.binary_search(10);
	
	result!=-1?cout <<"Found at "<< result : cout << "Not found";
	
	return 0;
}





