/*
//Stack using array

#include <iostream>
#include <algorithm>
using namespace std;

class StackArray {
private:
    int top;
    int* arr;
    int capacity;

public:
    StackArray(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~StackArray() {
        delete[] arr;
    }

    void push(int data) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = data;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool search(int data) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == data) {
                return true;
            }
        }
        return false;
    }

    void sortStack() {
        sort(arr, arr + top + 1);
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Stack after push operations: ";
    stack.display();

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack after pop operation: ";
    stack.display();

    cout << "Searching for element 30: " << (stack.search(30) ? "Found" : "Not Found") << endl;

    stack.sortStack();
    cout << "Stack after sorting: ";
    stack.display();

    return 0;
}

*/

/*
//Stack using linked list

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

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    ~StackLinkedList() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool search(int data) {
        Node* temp = top;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void sortStack() {
        if (top == nullptr || top->next == nullptr) {
            return;
        }

        for (Node* i = top; i->next != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Stack after push operations: ";
    stack.display();

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack after pop operation: ";
    stack.display();

    cout << "Searching for element 30: " << (stack.search(30) ? "Found" : "Not Found") << endl;

    stack.sortStack();
    cout << "Stack after sorting: ";
    stack.display();

    return 0;
}

*/

/*
//Evaluation using array

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

#define MAX 100

class StackArray {
private:
    int top;
    char arr[MAX];

public:
    StackArray() {
        top = -1;
    }

    bool push(char x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
            return false;
        } else {
            arr[++top] = x;
            return true;
        }
    }

    char pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            char x = arr[top--];
            return x;
        }
    }

    char peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return 0;
        } else {
            char x = arr[top];
            return x;
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}

// Function to evaluate infix expression
int evaluate(string tokens) {
    int i;

    StackArray values;
    StackArray ops;

    for (i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

        else if (isdigit(tokens[i])) {
            int val = 0;

            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }

        else if (tokens[i] == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                int val2 = values.pop();
                int val1 = values.pop();
                char op = ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if (!ops.isEmpty())
                ops.pop();
        }

        else {
            while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(tokens[i])) {
                int val2 = values.pop();
                int val1 = values.pop();
                char op = ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.push(tokens[i]);
        }
    }

    while (!ops.isEmpty()) {
        int val2 = values.pop();
        int val1 = values.pop();
        char op = ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.pop();
}

string infixToPostfix(string infix) {
    StackArray stack;
    string postfix;
    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

string postfixToInfix(string postfix) {
    StackArray stack;
    for (char ch : postfix) {
        if (isdigit(ch) || isalpha(ch)) {
            string op(1, ch);
            stack.push(op[0]);
        } else {
            string op1(1, stack.pop());
            string op2(1, stack.pop());
            string expr = "(" + op2 + ch + op1 + ")";
            for (char c : expr) {
                stack.push(c);
            }
        }
    }

    string infix;
    while (!stack.isEmpty()) {
        infix = stack.pop() + infix;
    }

    return infix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string prefixToInfix(string prefix) {
    StackArray stack;
    reverse(prefix.begin(), prefix.end());
    for (char ch : prefix) {
        if (isdigit(ch) || isalpha(ch)) {
            string op(1, ch);
            stack.push(op[0]);
        } else {
            string op1(1, stack.pop());
            string op2(1, stack.pop());
            string expr = "(" + op1 + ch + op2 + ")";
            for (char c : expr) {
                stack.push(c);
            }
        }
    }

    string infix;
    while (!stack.isEmpty()) {
        infix = stack.pop() + infix;
    }

    return infix;
}

int main() {
    string infix = "(1+2)*(3/4)";
    cout << "Infix expression: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    string infixFromPostfix = postfixToInfix(postfix);
    cout << "Infix from Postfix expression: " << infixFromPostfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    string infixFromPrefix = prefixToInfix(prefix);
    cout << "Infix from Prefix expression: " << infixFromPrefix << endl;

    cout << "Evaluation of infix expression: " << evaluate(infix) << endl;

    return 0;
}

*/

/*
//Evaluation using linked list

#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        next = nullptr;
    }
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(char data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    char peek() {
        if (top == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}

int evaluate(string tokens) {
    StackLinkedList values;
    StackLinkedList ops;

    for (int i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ') continue;

        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

        else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }

        else if (tokens[i] == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                int val2 = values.pop();
                int val1 = values.pop();
                char op = ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.isEmpty()) ops.pop();
        }

        else {
            while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(tokens[i])) {
                int val2 = values.pop();
                int val1 = values.pop();
                char op = ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    while (!ops.isEmpty()) {
        int val2 = values.pop();
        int val1 = values.pop();
        char op = ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.pop();
}

string infixToPostfix(string infix) {
    StackLinkedList stack;
    string postfix;
    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

string postfixToInfix(string postfix) {
    StackLinkedList stack;
    for (char ch : postfix) {
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(ch);
        } else {
            string op1(1, stack.pop());
            string op2(1, stack.pop());
            string expr = "(" + op2 + ch + op1 + ")";
            for (char c : expr) {
                stack.push(c);
            }
        }
    }

    string infix;
    while (!stack.isEmpty()) {
        infix = stack.pop() + infix;
    }

    return infix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string prefixToInfix(string prefix) {
    StackLinkedList stack;
    reverse(prefix.begin(), prefix.end());
    for (char ch : prefix) {
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(ch);
        } else {
            string op1(1, stack.pop());
            string op2(1, stack.pop());
            string expr = "(" + op1 + ch + op2 + ")";
            for (char c : expr) {
                stack.push(c);
            }
        }
    }

    string infix;
    while (!stack.isEmpty()) {
        infix = stack.pop() + infix;
    }

    return infix;
}

int main() {
    string infix = "(1+2)*(3/4)";
    cout << "Infix expression: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    string infixFromPostfix = postfixToInfix(postfix);
    cout << "Infix from Postfix expression: " << infixFromPostfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    string infixFromPrefix = prefixToInfix(prefix);
    cout << "Infix from Prefix expression: " << infixFromPrefix << endl;

    cout << "Evaluation of infix expression: " << evaluate(infix) << endl;

    return 0;
}

*/

/*
Tower of hanoi in array
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

#define MAX 100

class StackArray {
private:
    int top;
    int arr[MAX];

public:
    StackArray() {
        top = -1;
    }

    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
            return false;
        } else {
            arr[++top] = x;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return 0;
        } else {
            int x = arr[top];
            return x;
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

void moveDisks(StackArray &src, StackArray &dest, char s, char d) {
    int pole1TopDisk = src.pop();
    int pole2TopDisk = dest.pop();

    if (pole1TopDisk == 0) {
        src.push(pole2TopDisk);
        cout << "Move disk " << pole2TopDisk << " from " << d << " to " << s << endl;
    } else if (pole2TopDisk == 0) {
        dest.push(pole1TopDisk);
        cout << "Move disk " << pole1TopDisk << " from " << s << " to " << d << endl;
    } else if (pole1TopDisk > pole2TopDisk) {
        src.push(pole1TopDisk);
        src.push(pole2TopDisk);
        cout << "Move disk " << pole2TopDisk << " from " << d << " to " << s << endl;
    } else {
        dest.push(pole2TopDisk);
        dest.push(pole1TopDisk);
        cout << "Move disk " << pole1TopDisk << " from " << s << " to " << d << endl;
    }
}

void towerOfHanoi(int num_of_disks, StackArray &src, StackArray &aux, StackArray &dest) {
    int total_num_of_moves = pow(2, num_of_disks) - 1;
    char s = 'S', d = 'D', a = 'A';

    if (num_of_disks % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    for (int i = num_of_disks; i >= 1; i--) {
        src.push(i);
    }

    for (int i = 1; i <= total_num_of_moves; i++) {
        if (i % 3 == 1) {
            moveDisks(src, dest, s, d);
        } else if (i % 3 == 2) {
            moveDisks(src, aux, s, a);
        } else if (i % 3 == 0) {
            moveDisks(aux, dest, a, d);
        }
    }
}

int main() {
    int num_of_disks = 3;
    StackArray src, dest, aux;

    towerOfHanoi(num_of_disks, src, aux, dest);

    return 0;
}

*/

/*
//Tower of hanoi in linked list
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

void moveDisks(StackLinkedList &src, StackLinkedList &dest, char s, char d) {
    int pole1TopDisk = src.pop();
    int pole2TopDisk = dest.pop();

    if (pole1TopDisk == -1) {
        src.push(pole2TopDisk);
        cout << "Move disk " << pole2TopDisk << " from " << d << " to " << s << endl;
    } else if (pole2TopDisk == -1) {
        dest.push(pole1TopDisk);
        cout << "Move disk " << pole1TopDisk << " from " << s << " to " << d << endl;
    } else if (pole1TopDisk > pole2TopDisk) {
        src.push(pole1TopDisk);
        src.push(pole2TopDisk);
        cout << "Move disk " << pole2TopDisk << " from " << d << " to " << s << endl;
    } else {
        dest.push(pole2TopDisk);
        dest.push(pole1TopDisk);
        cout << "Move disk " << pole1TopDisk << " from " << s << " to " << d << endl;
    }
}

void towerOfHanoi(int num_of_disks, StackLinkedList &src, StackLinkedList &aux, StackLinkedList &dest) {
    int total_num_of_moves = pow(2, num_of_disks) - 1;
    char s = 'S', d = 'D', a = 'A';

    if (num_of_disks % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    for (int i = num_of_disks; i >= 1; i--) {
        src.push(i);
    }

    for (int i = 1; i <= total_num_of_moves; i++) {
        if (i % 3 == 1) {
            moveDisks(src, dest, s, d);
        } else if (i % 3 == 2) {
            moveDisks(src, aux, s, a);
        } else if (i % 3 == 0) {
            moveDisks(aux, dest, a, d);
        }
    }
}

int main() {
    int num_of_disks = 3;
    StackLinkedList src, dest, aux;

    towerOfHanoi(num_of_disks, src, aux, dest);

    return 0;
}

*/
