/*
//Array implementation
#include <iostream>
using namespace std;

void Insertion_sort(int arr[],int n)
{
	int c;
	for(int i=1;i<n;++i)
	{
		int k=arr[i];
		int j=i-1;
		while(arr[j]>k && j>=0)
		{
			arr[j+1]=arr[j];
			j=j-1;
			c++;
		}
		arr[j+1]=k;
	}
	cout <<"Count: "<<c <<endl;
}

int main()
{
	int arr[]={10,9,7,6,2,12,18,24,29};
	int n=sizeof(arr)/sizeof(arr[0]);
	Insertion_sort(arr,n);
	for(int num:arr)
	{
		cout <<'|'<< num<<'|';
	}
	return 0;
}

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() {
        this->head = nullptr;
    }
    
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void insertionSort() {
        if(!head ||  head->next==nullptr) return;
        Node* sorted=nullptr;
        Node* current=head;
        while(current)
        {
        	Node* then=current->next;
        	if(!sorted || sorted->data>=current->data)
        	{
        		current->next=sorted;
        		sorted=current;
			}
			else
			{
				Node* temp=sorted;
				while(temp->next && temp->next->data < current->data)
				{
					temp=temp->next;
				}
				current->next=temp->next;
				temp->next=current;
			}
			current=then;
			
		}
		head=sorted;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << '|' << temp->data << "|->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    int data;
    cout << "--Insertion--\n";
    while (true) {
        cin >> data;
        if (data == 0) {
            break;
        }
        sll.insert(data);
    }
    cout << "Before Sorting: ";
    sll.display();
    sll.insertionSort();
    cout << "After Sorting: ";
    sll.display();
    
    return 0;
}







