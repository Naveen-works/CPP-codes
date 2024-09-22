
//ARRAY IMPLEMENTATION
#include<iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int precedance(char ch)
{
	if(ch=='+'||ch=='-')return 1;
	if(ch=='*'||ch=='/')return 2;
	return 0;
	
}

string infix_to_prefix(string infix)
{
	stack<char> operators;
	stack<string> operands;
	for(char ch:infix)
	{
		if(isdigit(ch)||isalpha(ch))
		{
			operands.push(string(1,ch));
		 } 
		 else if(ch=='(')
		 {
		 	operators.push(ch);
		 }
		 else if(ch==')')
		 {
		 	while(!operators.empty() && operators.top()!='(')
			 {
			 	char op=operators.top();
			 	operators.pop();
			 	string op1=operands.top();
			 	operands.pop();
			 	string op2=operands.top();
			 	operands.pop();
			 	operands.push(op+op1+op2);
			 	
			}
			operators.pop();	
		 }
		else
		{
			while(!operators.empty() && precedance(operators.top()) >= precedance(ch) )
			{
				char op=operators.top();
				operators.pop();
				string op1=operands.top();
				operands.pop();
				string op2=operands.top();
				operands.pop();
				operands.push(op+op1+op2);
			}
			operators.push(ch);
		}
	}
	while(!operators.empty() )
			{
				char op=operators.top();
				operators.pop();
				string op1=operands.top();
				operands.pop();
				string op2=operands.top();
				operands.pop();
				operands.push(op+op1+op2);
			}
			return operands.top();
	
}

int main()
{
	string infix="a+b*(c^d-e)^(f+g*h)-i ";
	reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    string prefix=infix_to_prefix(infix);
    
    cout <<"Prefix: " <<prefix <<endl;
	return 0;

}



//LINKED LIST IMPLEMENTAION







