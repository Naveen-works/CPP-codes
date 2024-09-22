
/*
//ARRAY IMPLEMENTATION
#include <iostream>
#define SIZE 5
using namespace std;

class Dequeue
{
	private:
		int items[SIZE];
		int front;
		int rear;
		
	public:
		Dequeue()
		{
			front=-1;
			rear=-1;
		}
		
	bool isfull()
	{
		return (front==0 && rear==SIZE-1) || (front ==rear+1);
	}
	
	bool isempty()
	{
		return front==-1;
	}
	
	void insert_front(int data)
	{
		if(isfull())
		{
			cout << "Queue is full\n";
			return;
		}
		 if(isempty())
		{
			front=rear=0;
		}
		else if(front==0)
		{
			front =SIZE-1;
		}
		else 
		{
			front--;
		}
		items[front]=data;
		cout << "Inserted at front : " <<data <<endl <<endl;
		print_queue();
		cout << endl;
		
	}
	
	void insert_rear(int data)
	{
		if(isfull())
		{
			cout << "Queue is full \n" ;
			return;
		}
		if(isempty())
		{
			front=rear=0;
		}
		else if(rear==SIZE-1)
		{
			rear=0;
		}
		else{
			rear++;
		}
		items[rear]=data;
		cout << "Inserted at rear : " <<data <<endl <<endl;
		print_queue();
		cout << endl;
		
	}
	
	int delete_front()
	{
		if(isempty())
		{
			cout << "Queue is empty\n";
			return -1;
		}
		int value=items[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else if(front==SIZE-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
		cout << "Deletion at front : " <<value <<endl;
		print_queue();
		cout << endl;
		return value;
		
		
	}
	
	int delete_rear()
	{
		if(isempty())
		{
		cout << "Queue is empty\n";
		return -1;
		}
		int value =items[rear];
		if(front==rear)
		{
			front=rear=-1;
		}
		else if(rear==0)
		{
			rear==SIZE-1;
		}
		else
		{
			rear--;
		}
		cout << "Deletion at rear : " <<value <<endl;
		print_queue();
		cout << endl;
		return value;
	}
	
	void print_queue()
	{
		if(isempty())
		{
			cout << "Queue is empty" <<endl;
			return;
		}
		if(front <=rear)
		{
			
			for(int i=front;i<=rear;++i)
			{
				cout << '|'<< items[i]	<<'|' ;
			}
			cout <<endl;
		
		}
		else
		{ 
			
			for(int i=front ;i<SIZE;++i)	
			{
				
				cout << '|'<< items[i]	<<'|' ;
				
			}
			
			for(int i=0 ;i<=rear;++i)	
			{
				
				cout << '|'<< items[i]	<<'|' ;
			}
			cout << endl;
		}
		cout << "Front => " << items[front] <<'\t' << "Rear => " << items[rear] << endl;
	}
		
	
};

int main()
{
	Dequeue dq;
	dq.insert_front(5);
	dq.insert_front(6);
	
	
	
	dq.insert_rear(4);
	
	
	dq.insert_rear(7);
	
	
	dq.insert_front(10);

	
	dq.delete_front();
	
	dq.delete_rear();
	return 0;
}

*/



/*
//LINKED LIST IMPLEMENTATION

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

class Dequeue
{
	private:
		Node* front;
		Node* rear;
		
	public:
		Dequeue()
		{
			front=nullptr;
			rear=nullptr;
		}
		
		bool isempty()
		{
			return front==nullptr;
		}
		
		void insert_front(int data)
		{
			Node* newNode= new Node(data);
			if(isempty())
			{
				front=rear=newNode;
			}
			else{
				newNode->next=front;
				front->prev=newNode;
				front=newNode;
			}
			cout << "Inserted " << data << " at front\n";
			 print_queue();
		}
		
		void insert_rear(int data)
		{
			Node* newNode= new Node(data);
			if(isempty())
			{
				front=rear=newNode;
			}
			else
			{
				rear->next=newNode;
				newNode->prev=rear;
				rear=newNode;
			}
			cout << "Inserted " << data << " at rear\n";
			print_queue();
			
		}
		
		int delete_front()
		{
			if(isempty())
			{
				cout << "Queue is empty\n";
				return -1;
			}
			Node* temp=front;
			int value=front->data;
			front=front->next;
			if(front==nullptr)
			{
				rear=nullptr;
			}
			else
			{
				front->prev=nullptr;
			}
			delete temp;
			cout << "Deleted " << value << " at front\n";
			print_queue();
			return value;
			
			
		}
		
		int delete_rear()
		{
			if(isempty())
			{
				cout << "Queue is empty\n";
				return -1;
			}
			
			Node* temp=rear;
			int value =rear->data;
			rear=rear->prev;
			if(rear==nullptr)
			{
				front=nullptr;
			}
			else
			{
				rear->next=nullptr;
			}
			delete temp;
			cout << "Deleted " << value << " at rear\n";
			print_queue();
			return value;
		}
		
		void print_queue()
		{
			if(isempty())
			{
				cout <<"Queue is empty\n";
				return;	
			}
			Node* temp=front;
			while(temp!=nullptr)
			{
				cout << '|' <<temp->data <<'|';
				temp=temp->next;
			}
			cout <<endl << "Front => " << front->data <<'\t'<< "Rear => " << rear->data <<endl;
		}
};


int main()
{
	Dequeue dq;
	
	
	dq.insert_front(5);
	dq.insert_front(4);
	
	dq.insert_rear(6);
	dq.insert_rear(7);
	
	dq.delete_front();
	
	dq.delete_rear();
	return 0;
}

*/












/*
if(isempty())
		{
			cout << "Queue is empty" <<endl;
			return;
		}
		if(front <=rear)
		{
			cout << "Front <--" ;
			for(int i=front;i<=rear;++i)
			{
				cout << '|'<< items[i]	<<'|' ;
			}
			cout << "--> Rear" <<endl;
		
		}
		else
		{ 
			
			for(int i=front ;i<SIZE;++i)	
			{
				
				cout << '|'<< items[i]	<<'|' ;
				if(i==front)
				{
					cout << "--> Front " ;
				}
			}
			
			for(int i=0 ;i<=rear;++i)	
			{
				if(i==rear)
				{
					cout << " Rear <--" ;
				}
				cout << '|'<< items[i]	<<'|' ;
			}
			cout << endl;
		}
		cout << "Front => " << items[front] <<'\t' << "Rear => " << items[rear] << endl;
		*/
