
/*
//ARRAY IMPLEMENTATION

#include <iostream>
#define SIZE 5
using namespace std;

class Circular_queue
{
	private:
		int items[SIZE];
		int front;
		int rear;
		
	public:
		Circular_queue()
		{
			front=-1;
			rear=-1;
		}
		
		bool isfull()
		{
			return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
		}
		
		bool isempty()
		{
			return front==-1;
		}
		
		void enqueue(int data)
		{
			if(isfull())
			{
				cout << "Queue is full" <<endl;
				return;
			}
			if(front==-1)
			{
				front=rear=0;
			}
			else if(rear==SIZE-1 && front!=0)
			{
				rear=0;
			}
			else
			{
				rear++;
				
			}
			
			items[rear] =data;
			cout << "Enqueued : " << data <<endl;
		}
		
		int dequeue()
		{
			int data= items[front];
			items[front]=-1	;
			if(front==SIZE-1)
			{
				front=0;
			}
			else if(front==rear)
			{
				front =rear=-1;
			}
			else
			{
				front++;
			}
			return data;
		}
		
		void print_queue()
		{
			if (isempty()) 
			{
            std::cout << "Queue is empty\n";
            return;
        	}
        	
			if(rear>=front)
			{
				cout << "Front <--";
				for(int i=front;i<=rear;++i)
				{
					cout <<'|'<< items[i] <<'|';
				}
				cout << "--> Rear ";
				cout <<endl;
			}
			
			else
			{
				
				for(int i=0;i<=rear;++i)
				{
					if(i==rear)
					{
						cout << "Rear <--";
					}
					
					cout <<'|'<< items[i] <<'|';	
				}
				
				for(int i=front;i<SIZE;++i)
				{
					cout <<'|'<< items[i] <<'|';
					if(i==front)
					{
						cout << "--> Front";
					}
						
						
				}
				cout <<endl;
				
			}
			
			cout << "Front => "<<items[front]<<'\t' << "Rear => " <<items[rear] <<endl;
		}
					
};

int main()
{
	Circular_queue cq;
	cq.print_queue();
	
	cq.enqueue(5);
	cq.enqueue(6);
	cq.enqueue(7);
	cq.enqueue(8);
	cq.enqueue(9);
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	cq.enqueue(10);
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	cq.enqueue(11);
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	cq.enqueue(12);
	cq.print_queue();
	cq.enqueue(13);
	cq.print_queue();
	cq.enqueue(14);
	cq.print_queue();
	cq.enqueue(15);
	cq.print_queue();
	return 0;
}*/


/*
//LINKED LIST IMPLEMENTATION
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

class Circular_queue
{
	private:
		Node* front;
		Node* rear;
		
	public:
		Circular_queue()
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
		if(front==nullptr)
		{
			front=rear=newNode;
			rear->next=front;
		}
		else
		{
			rear->next=newNode;
			rear=newNode;
			rear->next=front;
		}
	}
	
	int dequeue()
	{
		if(isempty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		int value=front->data;
		if(front ==rear)
		{
			 delete front;
			front=rear=nullptr;
		}
		else
		{
			Node* temp=front;
		front=front->next;
		rear->next=front;
		delete temp;
		}
		return value;
		
		
	}
	
	void print_queue()
	{
		if(isempty())
		{
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Front <--";
		Node* temp=front;
		do{
			cout <<'|'<< temp->data<<'|' ;
			temp=temp->next;
		}while(temp!=front);
		
		cout <<"-->Rear" <<'\n';
		cout << "Front => "<< front->data <<'\t' << "Rear => "<< rear->data<< endl;
		
		cout <<"Rear=>next: "<< rear->next->data <<endl;
		
		
	}
		
};



int main()
{
	Circular_queue cq;
	cq.isempty();
	
	cq.print_queue();
	
	cq.enqueue(5);
	cq.print_queue();
	
	cq.enqueue(6);
	cq.enqueue(7);
	cq.enqueue(8);
	cq.enqueue(9);
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	cq.dequeue();
	cq.print_queue();
	
	return 0;
}


*/
