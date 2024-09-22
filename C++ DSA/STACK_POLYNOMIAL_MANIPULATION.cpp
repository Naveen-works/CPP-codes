#include <iostream>
using namespace std;

class Node
{
	public:
		int coeff;
		int exp;
		Node* next;
		
		Node(int coeff,int exp)
			{
			this->coeff=coeff;
			this->exp=exp;
			this->next=nullptr;
			}
		
};

class Polynomial{
	private:
		Node* head;
		
		
	public:
		polynomial()
			{
			head=nullptr;
			}
		void insert_term(int coeff,int exp)
		{
			Node* newNode=new Node(coeff,exp);
			if(head==nullptr || head->exp < exp)
			{
				newNode->next=head;
				head=newNode;
			}
			else
			{
				Node* temp=head;
				while(temp->next !=nullptr && temp->next->exp>exp)
				{
					temp=temp->next;
				}
				if(temp->exp==exp)
				{
					temp->coeff+=coeff;
				}
				else
				{
					newNode->next=temp->next;
					temp->next=newNode;
				}
			}
			
		}
	
		
		
		Polynomial add(Polynomial& p)
		{
			Polynomial result;
       	 	Node* temp1 = head;
        	Node* temp2 = p.head;
			while (temp1 && temp2) {
            if (temp1->exp > temp2->exp) {
                result.insert_term(temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            } else if (temp1->exp < temp2->exp) {
                result.insert_term(temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            } else {
                result.insert_term(temp1->coeff + temp2->coeff, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        while (temp1) {
            result.insert_term(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }

        while (temp2) {
            result.insert_term(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }

        return result;
		}
		
		Polynomial multiply(Polynomial& p) {
        Polynomial result;
        for (Node* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            Polynomial tempPoly;
            for (Node* temp2 = p.head; temp2 != nullptr; temp2 = temp2->next) {
                tempPoly.insert_term(temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
            }
            result = result.add(tempPoly);
        }
        return result;
    }
		
		void display()
		{
			if(head==nullptr)
			{
				cout << "Expression is empty";
				return;
			}
			Node* temp=head;
			while(temp!=nullptr)
			{
				cout << '('<<temp->coeff <<"x)^" <<temp->exp;
				if(temp->next!=nullptr)
				{
					cout <<"+";
				}
				temp=temp->next;
			}
			cout << endl;
		}
	
};

int main()
{	Polynomial p1;
	p1.insert_term(5,2);
	
	p1.insert_term(6,3);
	
	Polynomial p2;
	p2.insert_term(7,2);
	
	p2.insert_term(8,3);
	
	
	p1.display();
	p2.display();
	
	
	Polynomial sum=p1.add(p2);
	sum.display();
	
	Polynomial mul=p1.multiply(p2);
	mul.display();
	
	
	return 0;
}
