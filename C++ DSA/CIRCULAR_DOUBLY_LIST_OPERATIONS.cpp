#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(int data)
		{
			this->data=data;
			this->next=nullptr;
			this->prev=nullptr;
		}
};

class Circular_doubly_list
{
	private:
		Node* head;
		
	public:
		Circular_doubly_list()
		{
			head=nullptr;
		}
		
		void insert_first(int data)
		{
			Node* newNode = new Node(data);
			if(head==nullptr)
			{
				head=newNode;
				head->next=head;
				head->prev=head;
			}
			else
			{
				newNode->next=head;
				newNode->prev=head->prev;
				head->prev->next=newNode;
				head->prev=newNode;
				head=newNode;
			}
		}
		
		void insert_last(int data)
		{
			Node* newNode =new Node(data);
			if(head==nullptr){
				head=newNode;
				head->next=head;
				head->prev=head;
			}
			else
			{
				newNode->prev=head->prev;
				newNode->next=head;
				head->prev->next=newNode;
				head->prev=newNode;
			}
		}
		
		void insert_middle(int data,int pos)
		{
			Node* newNode= new Node(data);
			if(pos==0)
			{
				cout << "Position should be greater than 0" << endl;
				return;
			}
			if(pos==1)
			{
				insert_first(data);
				return;
			}
			else
			{
				Node*temp=head;
				int count=0;
				while(temp->next!=head && count < pos-1)
				{
					temp=temp->next;
					count++;
				}
				
				if(temp->next==head && count !=pos-1)
				{
					cout << "postion is out of bounds" << endl;
					return;
				}
				newNode->next=temp->next;
				newNode->prev=temp;
				temp->next->prev=newNode;
				temp->next=newNode;
				}
			
		}
		
		
	void delete_first()
	{
		if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
		Node* temp=head;
		head->prev->next=head->next;
		head->next->prev=head->prev;
		head=head->next;
		delete temp;
	}	
	void delete_last()
	{
		if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        
		Node*temp=head->prev;
		temp->prev->next=head;
		head->prev=temp->prev;
		delete temp;
		
	}	
	
	void delete_middle(int pos)
	{
		Node* temp=head;
		int count=0;
		if(pos==0)
		{
			delete_first();
			return;
		}
		while(temp->next!=head && count <pos-1)
		{
			temp=temp->next;
			count++;
		}
		if(temp->next==head && count !=pos-1)
		{
			cout << "postion is out of bounds" <<endl;
			return;
		}
		Node* del_node=temp->next;
		temp->next=del_node->next;
		del_node->next->prev=temp;
		delete del_node;
		
		
	}	
	
	void search_list(int data)
	{
		Node* temp=head;
		int i=0,s=0;
		do
		{
			if(temp->data==data)
			{
				cout << "Found at "<< i<< endl;
				s=1;
				return;
			}
			
			temp=temp->next;
			i++;
		
		}while(temp!=head);
		if(s!=1)
		{
			cout << "Not found"<< endl;
			
		}
	}
		
	void print_list()
	{
		if(head==nullptr)
		{
			cout << "List is empty"<< endl;
			return;
		}
		Node* temp=head;
		do
		{
			cout << temp->data <<"<->";
			temp=temp->next;
			
		}while(temp!=head);
		cout << "HEAD"<< endl;
		cout << "Head = "<<head->data <<endl <<endl;
		
		
	}
		
};






int main()
{
	Circular_doubly_list cdl;
	cdl.print_list();
	
	cdl.insert_first(4);
	cdl.print_list();
	
	cdl.insert_first(3);
	cdl.print_list();
	
	cdl.insert_last(5);
	cdl.print_list();
	
	cdl.insert_last(6);
	cdl.print_list();
	
	cdl.insert_last(7);
	cdl.print_list();
	
	cdl.insert_middle(9,5);
	cdl.print_list();
	
	
	cdl.delete_first();
	cdl.print_list();
	
	cdl.delete_last();
	cdl.print_list();
	
	cdl.delete_middle(0);
	cdl.print_list();
	
	cdl.search_list(9);
	return 0;
}
