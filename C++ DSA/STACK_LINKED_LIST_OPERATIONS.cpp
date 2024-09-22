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

class stack
{
	private:
		Node* top;
		
	public: 
		stack()
		{
			top=nullptr;
		}
		
	void push(int data)
	{
		Node* newNode =new Node(data);
		
		newNode->next=top;
		top=newNode;
	}
	
	int pop()
	{
		if(top==nullptr)
		{
			cout << "Stack underflow" << endl;
			return -1;
		}
		Node* temp=top;
		top=top->next;
		delete temp;
		
	}
	
	
	bool search_stack(int data) {
        Node* temp = top;
        int s=0;
        while (temp != nullptr) {
            if (temp->data == data) {
            	cout <<"Found" <<endl;
            	s=1;
                return true;
            }
            temp = temp->next;
        }
        if(s!=1)
        {
        	cout << "Not Found"<< endl;
		}
        return false;
    }
    
    void sort_stack()
    {
    	if(top==nullptr && top->next==nullptr)
    	{
    		return;
		}
    	Node* temp=top;
    
    	for(Node* i=temp;i->next!=nullptr;i=i->next)
    	{
    		for(Node* j=i->next;j!=nullptr;j=j->next)
    		{
    			if(i->data>j->data)
    			{
    				swap(i->data,j->data);
				}
			}
		}
	}




	void print_stack()
	{
		if(top==nullptr)
		{
			cout << "Stack under flow" <<endl;
			return;
		}
		Node*temp=top;
		cout << "<--" ;
		while(temp!=nullptr)
		{
			cout << "|"<< temp->data<< "|" ;
			temp=temp->next;
		}
		
		cout  << endl<<"TOP => " << top->data<<endl <<endl;
	}
};


int main()
{
	stack st;
	st.print_stack();
	
	st.push(3);
	st.print_stack();
	
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.print_stack();
	
	
	
	
	
	st.search_stack(3);
	
	st.sort_stack();
	st.print_stack();
	return 0;
}
