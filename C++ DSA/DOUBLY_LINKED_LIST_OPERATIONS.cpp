#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		Node(int data)
		{
			this->data=data;
			this->prev=nullptr;
			this->next=nullptr;
		}
};

class doubly_linked_list
{
	private:
		Node* head;
		Node* tail;
		
	public:
		doubly_linked_list()
		{
			head=nullptr;
			tail=nullptr;
		}
		
		void insert_first(int data)
		{
			Node* newNode= new Node(data);
			if(head==nullptr)
			{
				head=tail=newNode;
				
			}
			else{
			
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
		}
		
		void insert_last(int data)
		{
			Node* newNode= new Node(data);
			if(tail==nullptr)
			{
				head=tail=nullptr;
			}
			else{
			newNode->prev=tail;
			tail->next=newNode;
			tail=newNode;	
		}
		}
		
		void insert_middle(int data,int pos)
		{
			Node* newNode = new Node(data);
			if(pos==0)
			{
				insert_first(data);
				return;
			}
			Node* temp=head;
			for(int i=0;i<pos-1 && temp!=nullptr;++i)
			{
				temp=temp->next;
			}
			if(temp==nullptr)
			{
				cout << "Index out of bounds";
				return;
			}
			newNode->prev=temp;
			newNode->next=temp->next;
			if(temp->next!=nullptr)
			{
			temp->next->prev=newNode;
			}
			temp->next=newNode;
			if(newNode->next==nullptr)
			{
				tail=newNode;
				return;
			}
			
			
		}
		
		void delete_first()
		{
			if(head==nullptr)
			{
				cout << "List is empty";
			}
			Node* temp=head;
			head=head->next;
			head->prev=nullptr;
			delete temp;
		}
		
		void delete_last()
		{
			if(tail==nullptr)
			{
				cout << "List is empty";
			}
			Node* temp=tail;
			
			tail=tail->prev;
			if(tail!=nullptr){
			
			tail->next=nullptr;
			}
			else
			{
			head=nullptr;
			}
			
			delete temp;
		}
		
		void delete_middle(int pos)
		{
			if(pos==0)
			{
				delete_first();
				return;
			}
			Node* temp=head;
			for(int i=0;i<pos && temp!=nullptr;++i)
			{
				temp=temp->next;
			}
			if(temp==nullptr)
			{
				cout << "Index is out of bounds";
				return;
			}
			if(temp->prev!=nullptr)
			{
				temp->prev->next=temp->next;
			}
			if(temp->next!=nullptr)
			{
				temp->next->prev=temp->prev;
			}
			if(temp==head)
			{
				head=temp->next;
			}
			if(temp==tail)
			{
				tail=temp->prev;
			}
			
			delete temp;
		}
		
		
		void search_list(int data)
		{
			Node* temp=head;
			int i=0;
			while(temp!=nullptr)
			{
				if(temp->data==data)
				{
					cout << "Found at " << i <<endl;
				}
				temp=temp->next;
				i++;
			}
			
		}
		
		void sort()
		{
			
			if(head==nullptr || head->next==nullptr)
			{
				return;
			}
			bool swapped;
			do
			{
				swapped=false;
				Node*temp=head;
				while(temp->next!=nullptr)
				{
					if(temp->data>temp->next->data)
					{
						swap(temp->data,temp->next->data);
						swapped=true;
					}
					temp=temp->next;
					
				}
				
			}while(swapped);
		}
		
		
		
		void print_list()
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
	doubly_linked_list dll;
	
	
	
	
	dll.insert_first(1);
	dll.insert_first(2);
	dll.insert_first(3);
	dll.insert_first(4);
	dll.insert_first(5);
	dll.print_list();
	
	dll.insert_last(7);
	
	dll.print_list();
	
	dll.insert_last(6);
	dll.print_list();
	
	dll.insert_middle(8,7);
	dll.print_list();
	
	dll.delete_first();
	dll.print_list();
	
	dll.delete_last();
	dll.print_list();
	
	dll.delete_middle(3);
	dll.print_list();
	
	dll.search_list(3);
	dll.sort();
	dll.print_list();
	return 0;
	
}
