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

class circular_singly_list
{
	private:
		Node* head;
		
	public:
		circular_singly_list()
		{
			head=nullptr;
		}
		
		
	void insert_first(int data)
	{
		Node* newNode= new Node(data);
		if(head==nullptr)
		{
			head=newNode;
			newNode->next=head;
		}
		Node* temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next= head;
		head=newNode;
	}
	void insert_last(int data)
	{
		Node* newNode=new Node(data);
		Node* temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=head;
	}
	
	void insert_middle(int data, int pos) {
        if (pos <= 0) {
            cout << "Position should be greater than 0" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (pos == 1) {
            insert_first(data);
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void delete_first()
    {
    	if(head==nullptr)
    	{
    		cout << "List is empty";
		}
		if(head->next==nullptr)
		{
			
			delete head;
			head=nullptr;
		}
    	Node* temp=head;
    	while(temp->next!=head)
    	{
    		temp=temp->next;
		}
		temp->next=head->next;
		Node* del_node=head;
		head=head->next;
		delete del_node;
	}
	
	 void delete_last() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }
	
	 void delete_middle(int pos) {
        if (head == nullptr || pos <= 0) {
            cout << "List is empty or position is invalid" << endl;
            return;
        }
        if (pos == 1) {
            delete_first();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;
        while (count < pos && temp->next != head) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (temp == head ) {
            cout << "Position out of bounds" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
	
	
	void search_list(int data)
	{
		Node* temp= head;
		int i=0,s=0;
		do
		{
			if(temp->data==data)
			{
				cout << "Found at "<<i << endl;
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
			cout << "List is empty" <<endl;
			return;
		}
		Node* temp=head;
		do{
			cout <<temp->data << "->" ;
			temp=temp->next;
		}while(temp!=head);
		cout << "HEAD" << endl;
		cout << head->data << endl;
		
		
	}
	
};





int main()
{
	circular_singly_list csl;
	csl.insert_first(5);
	
	csl.insert_first(4);
	
	csl.insert_last(6);
	csl.insert_last(8);
	csl.insert_last(2);
	csl.print_list();
	
	csl.insert_middle(7,5);
	csl.print_list();
	
	csl.delete_first();
	csl.print_list();
	
	
	
	csl.delete_middle(2);
	csl.print_list();
	
	csl.delete_last();
	csl.print_list();
	
	csl.search_list(7);
	return 0;
}
