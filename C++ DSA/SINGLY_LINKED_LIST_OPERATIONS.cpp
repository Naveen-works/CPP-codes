#include <iostream>
using namespace std;

class Node{      						//STRUCTURE OF A NODE                    
	public:
		int data;
		Node* next;
		
	Node(int data)						//CONSTRUCTION OF NODE
		{
			this->data=data;
			this->next=nullptr;
			
		}
};
class singly_linked_list{					//SINGLY LINKED LIST CLASS
	private:
		Node* head;
		int size;
	
	public:										//CONSTRUCTION
		singly_linked_list()
		{
			head=nullptr;
			
		}
		
		void insert_first(int data)            //INSERTION AT FIRST
		{
			Node* newNode= new Node(data);
			newNode->next=head;
			head=newNode;
			
		}
		
		void insert_last(int data)					//INSERTION AT LAST
		{
			Node* newNode=new Node(data);
			if(head==nullptr)
			{
			head=newNode;
			}
			Node* temp=head;
			
			while(temp->next!=nullptr)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->next=nullptr;
			
	}
	
	void insert_middle(int data,int pos)			//INSERTION AT MIDDLE
	{
		if(pos==0)
		{
			insert_first(data);
			return;
		}
		Node* newNode= new Node(data);
		Node* temp=head;
		for(int i=0;i<pos-1;++i)
		{
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
		
	}
	
	void delete_first()							//DELETION AT FIRST
	{
		if(head==nullptr)
		{
			cout << "List is empty";
		}
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	
	void delete_last()					//DELETION AT LAST
	{
		if(head==nullptr)
		{
			cout << "List is empty";
		}
		if(head->next==nullptr)
		{
			delete head;
			head=nullptr;
			return;
		}
		Node* temp=head;
		while(temp->next->next!=nullptr)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=nullptr;
		
		
	}
	
	void delete_middle(int pos)				//DELETION AT MIDDLE
	{
		if(head==nullptr)
		{
			cout << "List is empty";
			return;
		}
		Node* temp=head;
		for(int i=0;i<pos-1&& temp!=nullptr;++i)
		{
			temp=temp->next;
		}
		
		if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* del_node=temp->next;
		temp->next=temp->next->next;
		delete del_node;
	}
	
	int search_list(int data)						//LINEAR SEARCHING
	{
		Node* temp=head;
		int i=0;
		while(temp!=nullptr)
		{
			if(temp->data==data)
			{
				cout << "Found at "<< i <<endl;
				return i;
				break;
			}
			temp=temp->next;
			i++;
			
			
		}
	}
	
	void sort_list()									//BUBBLE SORTING
	{
		if(head==nullptr || head->next ==nullptr)
		{
			return;
		}
		bool swapped;
		
		do{
			swapped=false;
			Node* temp=head;
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
			Node* temp =head;
			while(temp!=nullptr)
			{
				cout << temp->data <<"->";
				temp=temp->next;
			}
			cout << "NULL" << endl;
		}
		
		
};

int main()
{
	singly_linked_list sll;       //OBJECT FOR THE CLASS
	
	
	sll.insert_last(1);
	sll.insert_last(2);
	sll.insert_last(3);
	sll.insert_last(4);
	sll.insert_last(5);
	sll.insert_last(6);
	sll.insert_last(8);
	sll.print_list();
	
	sll.insert_middle(9,2);
	sll.print_list();
	sll.insert_middle(8,1);
	sll.print_list();
	
	sll.delete_first();
	sll.print_list();
	
	sll.delete_last();
	sll.print_list();
	
	sll.delete_middle(3);
	sll.print_list();
	
  sll.search_list(6);
  
  sll.sort_list();
  sll.print_list();
  
	return 0;
}
