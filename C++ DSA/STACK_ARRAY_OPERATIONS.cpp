#include <iostream>
#include <algorithm>
using namespace std;

class stack
{
	private:
		int top;
		int* arr;
		int capacity;		
		
	public:
		stack(int size)
		{
			capacity=size;
			arr=new int(size);
			top=-1;
		}
		
		~stack()
		{
			delete[] arr;
		}
		
		
		void push(int data)
		{
			if(top==capacity-1)
			{
				cout << "Stack overflow"<<endl;
				return;
			}
			arr[++top]=data;
		}
		int pop()
		{
			if(top==-1)
			{
				cout << "stack underflow" << endl;
				return -1;
			}
			return arr[top--];
		}
		
		void sort_stack()
		{
			sort(arr,arr+top+1);
			return;
		}
		
		void print_stack()
		{
			if(top==-1)
			{
				cout << "Stack is empty";
				return ;
				
			}
			for(int i=0;i<=top;++i)
			{
				
				cout << "|"<< arr[i] << "|" ;
				
			}
			cout << "-->" <<endl;
			cout  <<"TOP => " << arr[top]<<endl <<endl;
		}
};



int main()
{
	stack st(5);
	st.push(10);
	st.push(9);
	st.push(8);
	st.push(7);
	st.push(6);
	st.print_stack();
	
	
	
	st.sort_stack();
	st.print_stack();
	
	st.pop();
	st.print_stack();
	
	
	return 0;
}
