/*
//ARRAY IMPLEMENTATION

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Priority_queue
{
private:
    vector<pair<int, int>> items;

public:
    void enqueue(int priority, int value)
    {
        auto it = items.begin();
		while (it != items.end() && it->first>priority) {
            ++it;
        }
        items.insert(it, {priority, value});
        cout << "Enqueued: " << value << " with priority: " << priority << endl;
    }

    int dequeue()
    {
        if (items.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int value = items.back().second;
        items.pop_back();
        return value;
    }

    int peek()
    {
        if (items.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return items.back().second;
    }

    void print_queue()
    {
        if (items.empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        for (auto &item : items)
        {
            cout << "| [" << item.first << ',' << item.second << "] | ";
        }

        cout << "\nPeek => " << peek() << endl;
    }
};

int main()
{
    Priority_queue pq;
    pq.enqueue(1, 10);
    pq.print_queue();
    
	pq.enqueue(5, 20);
    pq.print_queue();
    
    pq.enqueue(4, 30);
    pq.print_queue();

    cout << "Dequeued: " << pq.dequeue() << endl;

    pq.print_queue();

    

    return 0;
}

*/


/*
//LINKED LIST IMPLEMETATION

#include <iostream>
using namespace std;

class Node
{
	public:
		int value;
		int priority;
		Node* next;
		
		Node(int priority,int value)
		{
			this->priority=priority;
			this->value=value;
			this->next=nullptr;
		}
};

class Priority_queue
{
	private:
		Node* front;
		
	public:
		Priority_queue()
		{
			front=nullptr;
		}
		bool isempty()
		{
			return front==nullptr;
		}
		void enqueue(int priority,int value)
		{
			Node* newNode=new Node(priority,value);
			if(front==nullptr || front->priority >priority)
			{
				newNode->next=front;
				front=newNode;
			}
			else
			{
				Node* temp =front;
				while(temp->next!=nullptr && temp->priority <=priority)
				{
					temp=temp->next;
				}
				temp->next=newNode;
			}
			
			cout << "Enqueued : " << value <<endl;
			
		}
		
		int dequeue()
		{
			if(isempty())
			{
				cout << "Queue is empty " << endl;
				return -1;
			}
			Node* temp=front;
			int value =temp->value;
			front=front->next;
			delete temp;
			return value;
		}
		
		void print_queue()
		{
			if(isempty())
			{
				cout << "Queue is empty " << endl;
				return ;
			}
			Node* temp=front;
			while(temp!=nullptr)
			{
				cout << "| [" << temp->priority << ',' << temp->value << "] |-";
				temp=temp->next;
			}
			cout << "Peek => " << front->value <<endl; 
			
		}
};

int main()
{
	Priority_queue pq;
	pq.enqueue(5,1);
	pq.print_queue();
	
	pq.enqueue(4,2);
	pq.print_queue();
	
	
	pq.enqueue(6,3);
	pq.print_queue();
	
	pq.dequeue();
	pq.print_queue();
	
	return 0;
}



*/
