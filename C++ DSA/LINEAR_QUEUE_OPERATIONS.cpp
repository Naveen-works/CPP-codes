/*
#include <iostream>
#define SIZE 100
using namespace std;

class Linear_queue
{
	private:
		int items[SIZE];
		int front ;
		int rear;
	
	public:
		Linear_queue()
		{
			front=-1;
			rear=-1;
		}
		
		bool isempty()
		{
			return front==-1 || front >rear;
		}
		
		bool isfull()
		{
			 return rear==SIZE-1;
		}
		
		void enqueue(int data)
		{
			if(isfull())
			{
				cout << "Queue is full" << endl;
				return;
			}
			if(front==-1)
			{
				front =0;
			}
			items[++rear]=data;
			cout << "Enqueued: "<<data <<endl;
		}
		
		int dequeue()
		{
			if(isempty())
			{
				cout << "Queue is empty" <<endl;
				return -1;
			}
			return items[front++];
		}
		
		void print_queue()
		{
			if (isempty()) {
            std::cout << "Queue is empty\n";
            return;
        	}
			cout <<"Front <--";
			for(int i=front;i<=rear;++i)
			{
				cout << '|'<< items[i] <<'|';
			}
			cout << "-->Rear" <<endl;
			cout << "Front => " << items[front] <<"\t" << "Rear => " <<items[rear] <<endl;
			
		}
	
};

int main()
{
	Linear_queue lq;
	lq.enqueue(5);
	lq.print_queue();
	lq.enqueue(6);
	lq.print_queue();
	lq.enqueue(7);
	lq.print_queue();
	lq.dequeue();
	lq.print_queue();
	
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
			this->data= data;
			this->next=nullptr;
			
		}
};

class Linear_queue
{
	private:
		Node* front;
		Node* rear;
		
	public:
		Linear_queue()
		{
			front=nullptr;
			rear=nullptr;
		}
		
		bool isempty()
		{
			return front==nullptr;
		}
		
		void enqueue(int data)
		{
			Node* newNode= new Node(data);
			if(rear==nullptr)
			{
				front=rear=newNode;
				
			}
			else
			{
				rear->next=newNode;
				rear=newNode;	
			}
			cout << "Enqueued: " <<data <<endl;
			
		}
		
		int dequeue()
		{
			if(front==nullptr)
			{
				cout << "Queue is empty"<<endl;
				return -1;
			}
			int value =front->data;
			Node* temp=front;
			front =front->next;
			if (front == nullptr) 
			{
            rear = nullptr;
        	}
			delete temp;
			return value;
			
		}
		
		void print_queue()
		{
			Node* temp =front;
			cout <<"Front <--";
			while(temp!=nullptr)
			{
				cout << '|'<<temp->data <<'|';
				temp=temp->next;
			}
			cout<<" -->Rear" << endl;
			
			cout << "Front => " << front->data <<"\t" <<"Rear => " << rear->data << endl <<endl;
		}
};

int main()
{
	Linear_queue lq;
	lq.enqueue(5);
	lq.enqueue(6);
	lq.enqueue(7);
	lq.print_queue();
	lq.dequeue();
	lq.print_queue();
	
	return 0;
}

