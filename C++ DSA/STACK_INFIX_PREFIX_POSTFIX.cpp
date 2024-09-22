/*
INFIX TO POSTFIX

//ARRAY STACK

#include <iostream>
#include <stack>
#include <string>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infixToPostfix(const std::string &infix) {
    std::stack<char> stack;
    std::string postfix;
    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int main() {
    std::string infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::cout << "Postfix: " << infixToPostfix(infix) << std::endl;
    return 0;
}


//LINKED LIST STACK

#include <iostream>
#include <string>

class StackNode {
public:
    char data;
    StackNode* next;
    StackNode(char d) : data(d), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;
    Stack() : top(nullptr) {}
    void push(char data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (top == nullptr) return '\0';
        char data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    char peek() {
        if (top == nullptr) return '\0';
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

std::string infixToPostfix(const std::string &infix) {
    Stack stack;
    std::string postfix;
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

int main() {
    std::string infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::cout << "Postfix: " << infixToPostfix(infix) << std::endl;
    return 0;
}

*/



/*
INFIX TO PREFIX

//ARRAY STACK

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infixToPrefix(const std::string &infix) {
    std::stack<char> operators;
    std::stack<std::string> operands;
    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) {
            operands.push(std::string(1, ch));
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                std::string operand1 = operands.top();
                operands.pop();
                std::string operand2 = operands.top();
                operands.pop();
                operands.push(op + operand2 + operand1);
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                char op = operators.top();
                operators.pop();
                std::string operand1 = operands.top();
                operands.pop();
                std::string operand2 = operands.top();
                operands.pop();
                operands.push(op + operand2 + operand1);
            }
            operators.push(ch);
        }
    }
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        std::string operand1 = operands.top();
        operands.pop();
        std::string operand2 = operands.top();
        operands.pop();
        operands.push(op + operand2 + operand1);
    }
    return operands.top();
}

int main() {
    std::string infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    std::string prefix = infixToPrefix(infix);
    std::reverse(prefix.begin(), prefix.end());
    std::cout << "Prefix: " << prefix << std::endl;
    return 0;
}


//LINKED LIST

#include <iostream>
#include <string>
#include <algorithm>

class StackNode {
public:
    char data;
    StackNode* next;
    StackNode(char d) : data(d), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;
    Stack() : top(nullptr) {}
    void push(char data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (top == nullptr) return '\0';
        char data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    char peek() {
        if (top == nullptr) return '\0';
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

std::string infixToPrefix(const std::string &infix) {
    Stack operators;
    Stack operands;
    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) {
            operands.push(ch);
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                char op = operators.pop();
                char operand1 = operands.pop();
                char operand2 = operands.pop();
                operands.push(op);
                operands.push(operand2);
                operands.push(operand1);
            }
            operators.pop();
        } else {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(ch)) {
                char op = operators.pop();
                char operand1 = operands.pop();
                char operand2 = operands.pop();
                operands.push(op);
                operands.push(operand2);
                operands.push(operand1);
            }
            operators.push(ch);
        }
    }
    while (!operators.isEmpty()) {
        char op = operators.pop();
        char operand1 = operands.pop();
        char operand2 = operands.pop();
        operands.push(op);
        operands.push(operand2);
        operands.push(operand1);
    }
    std::string prefix;
    while (!operands.isEmpty()) {
        prefix += operands.pop();
    }
    return prefix;
}

int main() {
    std::string infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    std::string prefix = infixToPrefix(infix);
    std::reverse(prefix.begin(), prefix.end());
    std::cout << "Prefix: " << prefix << std::endl;
    return 0;
}
*/

/*
PREFIX TO POSTFIX

//ARRAY STACK

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

std::string prefixToPostfix(const std::string &prefix) {
    std::stack<std::string> stack;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand1 = stack.top();
            stack.pop();
            std::string operand2 = stack.top();
            stack.pop();
            stack.push(operand1 + operand2 + ch);
        }
    }
    return stack.top();
}

int main() {
    std::string prefix = "-+a*b^cd^e*+fghi";
    std::cout << "Postfix: " << prefixToPostfix(prefix) << std::endl;
    return 0;
}

//LINKED LIST
#include <iostream>
#include <string>

class StackNode {
public:
    std::string data;
    StackNode* next;
    StackNode(std::string d) : data(d), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;
    Stack() : top(nullptr) {}
    void push(std::string data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    std::string pop() {
        if (top == nullptr) return "";
        std::string data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

std::string prefixToPostfix(const std::string &prefix) {
    Stack stack;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand1 = stack.pop();
            std::string operand2 = stack.pop();
            stack.push(operand1 + operand2 + ch);
        }
    }
    return stack.pop();
}

int main() {
    std::string prefix = "-+a*b^cd^e*+fghi";
    std::cout << "Postfix: " << prefixToPostfix(prefix) << std::endl;
    return 0;
}

*/

/*
PREFIX TO INFIX

//ARRAY STACK

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

std::string prefixToInfix(const std::string &prefix) {
    std::stack<std::string> stack;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand1 = stack.top();
            stack.pop();
            std::string operand2 = stack.top();
            stack.pop();
            stack.push("(" + operand1 + ch + operand2 + ")");
        }
    }
    return stack.top();
}

int main() {
    std::string prefix = "-+a*b^cd^e*+fghi";
    std::cout << "Infix: " << prefixToInfix(prefix) << std::endl;
    return 0;
}

//LINKED LIST


#include <iostream>
#include <string>

class StackNode {
public:
    std::string data;
    StackNode* next;
    StackNode(std::string d) : data(d), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;
    Stack() : top(nullptr) {}
    void push(std::string data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    std::string pop() {
        if (top == nullptr) return "";
        std::string data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

std::string prefixToInfix(const std::string &prefix) {
    Stack stack;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand1 = stack.pop();
            std::string operand2 = stack.pop();
            stack.push("(" + operand1 + ch + operand2 + ")");
        }
    }
    return stack.pop();
}

int main() {
    std::string prefix = "-+a*b^cd^e*+fghi";
    std::cout << "Infix: " << prefixToInfix(prefix) << std::endl;
    return 0;
}

*/



/*
POSTFIX TO INFIX

//ARRAY STACK

#include <iostream>
#include <stack>
#include <string>

std::string postfixToInfix(const std::string &postfix) {
    std::stack<std::string> stack;
    for (char ch : postfix) {
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand2 = stack.top();
            stack.pop();
            std::string operand1 = stack.top();
            stack.pop();
            stack.push("(" + operand1 + ch + operand2 + ")");
        }
    }
    return stack.top();
}

int main() {
    std::string postfix = "abcd^e-fgh*+^*+i-";
    std::cout << "Infix: " << postfixToInfix(postfix) << std::endl;
    return 0;
}

//LINKED LIST

#include <iostream>
#include <string>

class StackNode {
public:
    std::string data;
    StackNode* next;
    StackNode(std::string d) : data(d), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;
    Stack() : top(nullptr) {}
    void push(std::string data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    std::string pop() {
        if (top == nullptr) return "";
        std::string data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

std::string postfixToInfix(const std::string &postfix) {
    Stack stack;
    for (char ch : postfix) {
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand2 = stack.pop();
            std::string operand1 = stack.pop();
            stack.push("(" + operand1 + ch + operand2 + ")");
        }
    }
    return stack.pop();
}

int main() {
    std::string postfix = "abcd^e-fgh*+^*+i-";
    std::cout << "Infix: " << postfixToInfix(postfix) << std::endl;
    return 0;
}


*/

/* POSTFIX TO PREFIX

//ARRAY STACK

#include <iostream>
#include <stack>
#include <string>

std::string postfixToPrefix(const std::string &postfix) {
    std::stack<std::string> stack;
    for (char ch : postfix) {
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand2 = stack.top();
            stack.pop();
            std::string operand1 = stack.top();
            stack.pop();
            stack.push(ch + operand1 + operand2);
        }
    }
    return stack.top();
}

int main() {
    std::string postfix = "abcd^e-fgh*+^*+i-";
    std::cout << "Prefix: " << postfixToPrefix(postfix) << std::endl;
    return 0;
}


//LINKED LIST
#include <iostream>
#include <string>

class StackNode {
public:
    std::string data;
    StackNode* next;
    StackNode(std::string d) : data(d), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;
    Stack() : top(nullptr) {}
    void push(std::string data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    std::string pop() {
        if (top == nullptr) return "";
        std::string data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

std::string postfixToPrefix(const std::string &postfix) {
    Stack stack;
    for (char ch : postfix) {
        if (isdigit(ch) || isalpha(ch)) {
            stack.push(std::string(1, ch));
        } else {
            std::string operand2 = stack.pop();
            std::string operand1 = stack.pop();
            stack.push(ch + operand1 + operand2);
        }
    }
    return stack.pop();
}

int main() {
    std::string postfix = "abcd^e-fgh*+^*+i-";
    std::cout << "Prefix: " << postfixToPrefix(postfix) << std::endl;
    return 0;
}
*/
























