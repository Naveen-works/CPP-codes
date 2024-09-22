

//ARRAY IMPLEMENTAION

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int precedance(char ch)
{
	if(ch=='+'||ch=='-')return 1;
	if(ch=='*'||ch=='/')return 2;
	if(ch=='^')return 3;
	return 0;
}

string postfix(const string &infix)
{
	stack<int> stack;
	string postfix;
	for(char ch:infix)
	{
		if(isdigit(ch)||isalpha(ch))
		{
			postfix+=ch;
		}
		else if(ch=='(')
		{
			stack.push(ch);
		}
		else if (ch==')')
		{
			while(!stack.empty() && stack.top()!='(')
			{
				postfix+=stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else
		{
			while(!stack.empty() && precedance(stack.top())>=precedance(ch))
			{
				postfix+=stack.top();
				stack.pop();
			}
			stack.push(ch);
		}
	}
	while(!stack.empty())
	{
		postfix+=stack.top();
		stack.pop();
	}
	return postfix;
}

int main()
{
	string infix="a+b*(c^d-e)^(f+g*h)-i ";
	reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
	string result =postfix(infix);
	reverse(result.begin(), result.end());
	cout << result << endl;
	return 0;
}

//-+a*+b^-^cde*+fgh*i

/*
//LINKED LIST IMPLEMENTAION

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
		Node(char data)
		{
			this->data=data;
			this->next=nullptr;
		}
};

class char_stack
{
	private:
		Node* top;
		
	public:
		char_stack()
		{
			top=nullptr;
		}
		
		void push(char data)
		{
			Node* newNode= new Node(data);
			newNode->next=top;
			top=newNode;
		}
		
		char pop()
		{
		if (top == nullptr) return '\0';
        char data = top->data;
        Node* temp=top;
        top = top->next;
        delete temp;
        return data;
		}
		
		char peek()
		{
			if(top==nullptr) return '\0';
			return top->data;
		}
		bool isempty()
		{
			return top==nullptr;
		}
		
		void print_stack()
		{
			cout << "<--";
			Node* temp=top;
			while(temp!=nullptr)
			{
				cout << '|'<<temp->data <<'|';
				temp=temp->next;
			}
			cout << endl<<"TOP =>"<< top->data << endl;
		}
		
};

int precedance(char ch)
{
	if(ch=='+'||ch=='-')return 1;
	if(ch=='*'||ch=='/')return 2;
	return 0;
}

string infix_to_postfix(string infix)
{
	string postfix;
	char_stack st;
	for(char ch:infix)
	{
		if(isdigit(ch)||isalpha(ch))
		{
			postfix+=ch;
		}
		else if(ch=='(')
		{
			st.push(ch);
		}
		else if(ch==')')
		{
			while(!st.isempty() && st.peek()!='(')
			{
				postfix+=st.peek();
				st.pop();
			}
			st.pop();
		}
		else 
		{
			while(!st.isempty() && precedance(st.peek())>=precedance(ch))
			{
				postfix+=st.peek();
				st.pop();
			}
			st.push(ch);
			
		}
	}
	while(!st.isempty())
	{
		postfix+=st.peek();
		st.pop();
		
	}
	return postfix;
}


int main()
{
	
	string infix="2+3*3+2" ;
	string result =infix_to_postfix(infix);
	cout << result << endl;
	return 0;
}
*/
