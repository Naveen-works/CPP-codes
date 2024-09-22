/*
LINEAR QUEUE

//ARRAY QUEUE

#include <iostream>
#define SIZE 100

class LinearQueueArray {
    int items[SIZE];
    int front, rear;

public:
    LinearQueueArray() : front(-1), rear(-1) {}

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;  // First element insertion
        items[++rear] = element;
        std::cout << "Enqueued: " << element << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return items[front++];
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return items[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << items[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LinearQueueArray queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    return 0;
}

//LINKED LIST

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinearQueueLinkedList {
    Node* front;
    Node* rear;

public:
    LinearQueueLinkedList() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int element) {
        Node* newNode = new Node(element);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued: " << element << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinearQueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    return 0;
}
*/


/*CIRCULAR QUEUE

//ARRAY

#include <iostream>
#define SIZE 5

class CircularQueueArray {
    int items[SIZE];
    int front, rear;

public:
    CircularQueueArray() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }

        if (front == -1) { // Insert first element
            front = rear = 0;
        } else if (rear == SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        items[rear] = element;
        std::cout << "Enqueued: " << element << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }

        int data = items[front];
        items[front] = -1;
        if (front == rear) {
            front = rear = -1; // Queue is empty after dequeue
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return data;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return items[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        std::cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                std::cout << items[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularQueueArray queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.enqueue(60);

    queue.display();

    return 0;
}


// LINKED LIST

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueueLinkedList {
    Node* front;
    Node* rear;

public:
    CircularQueueLinkedList() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        std::cout << "Enqueued: " << element << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }

        int value;
        if (front == rear) {
            value = front->data;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            value = front->data;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        std::cout << "Queue elements: ";
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        std::cout << std::endl;
    }
};

int main() {
    CircularQueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.enqueue(60);

    queue.display();

    return 0;
}
*/

/*
PRIORITY QUEUE

A priority queue is an abstract data type similar to a regular queue or stack data structure,
 but where each element has a priority. 
 In a priority queue, an element with high priority is served before an element with low priority. 
 If two elements have the same priority, they are served according to their order in the queue.

Key Characteristics
Priority-based: Each element is associated with a priority.
Dynamic Order: The order of elements is determined by their priority.
Flexible: Can be implemented using different underlying data structures such as arrays, linked lists, heaps, or binary search trees.



//ARRAY

#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueueArray {
    std::vector<std::pair<int, int>> items; // (priority, value)

public:
    void enqueue(int priority, int value) {
        items.push_back({priority, value});
        std::sort(items.begin(), items.end(), [](auto &a, auto &b) { return a.first > b.first; });
        std::cout << "Enqueued: " << value << " with priority: " << priority << std::endl;
    }

    int dequeue() {
        if (items.empty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int value = items.back().second;
        items.pop_back();
        return value;
    }

    int peek() {
        if (items.empty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return items.back().second;
    }

    void display() {
        if (items.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (auto &item : items) {
            std::cout << "[" << item.second << ", " << item.first << "] ";
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueueArray queue;

    queue.enqueue(1, 10);
    queue.enqueue(3, 30);
    queue.enqueue(2, 20);
    queue.enqueue(5, 50);

    queue.display();

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    return 0;
}


//LINKED LIST

#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) : data(d), priority(p), next(nullptr) {}
};

class PriorityQueueLinkedList {
    Node* front;

public:
    PriorityQueueLinkedList() : front(nullptr) {}

    void enqueue(int priority, int value) {
        Node* newNode = new Node(value, priority);
        if (front == nullptr || front->priority < priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        std::cout << "Enqueued: " << value << " with priority: " << priority << std::endl;
    }

    int dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        Node* temp = front;
        front = front->next;
        int value = temp->data;
        delete temp;
        return value;
    }

    int peek() {
        if (front == nullptr) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (front == nullptr) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != nullptr) {
            std::cout << "[" << temp->data << ", " << temp->priority << "] ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueueLinkedList queue;

    queue.enqueue(1, 10);
    queue.enqueue(3, 30);
    queue.enqueue(2, 20);
    queue.enqueue(5, 50);

    queue.display();

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    return 0;
}


*/

/*
DE-QUEUE

//ARRAY

#include <iostream>
#define SIZE 5

class DequeArray {
    int items[SIZE];
    int front, rear;

public:
    DequeArray() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int element) {
        if (isFull()) {
            std::cout << "Deque is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        items[front] = element;
        std::cout << "Inserted " << element << " at front\n";
    }

    void insertRear(int element) {
        if (isFull()) {
            std::cout << "Deque is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        items[rear] = element;
        std::cout << "Inserted " << element << " at rear\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        int element = items[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return element;
    }

    int deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        int element = items[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
        return element;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return items[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return items[rear];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return;
        }
        std::cout << "Deque elements: ";
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                std::cout << items[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    DequeArray deque;

    deque.insertRear(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.insertRear(30);
    deque.insertFront(2);

    deque.display();

    std::cout << "Deleted from front: " << deque.deleteFront() << std::endl;
    deque.display();

    std::cout << "Deleted from rear: " << deque.deleteRear() << std::endl;
    deque.display();

    std::cout << "Front element: " << deque.getFront() << std::endl;
    std::cout << "Rear element: " << deque.getRear() << std::endl;

    return 0;
}

//LINKED LIST

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DequeLinkedList {
    Node* front;
    Node* rear;

public:
    DequeLinkedList() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        std::cout << "Inserted " << element << " at front\n";
    }

    void insertRear(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Inserted " << element << " at rear\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        int element = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        return element;
    }

    int deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        int element = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        return element;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return rear->data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        std::cout << "Deque elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DequeLinkedList deque;

    deque.insertRear(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.insertRear(30);
    deque.insertFront(2);

    deque.display();

    std::cout << "Deleted from front: " << deque.deleteFront() << std::endl;
    deque.display();

    std::cout << "Deleted from rear: " << deque.deleteRear() << std::endl;
    deque.display();

    std::cout << "Front element: " << deque.getFront() << std::endl;
    std::cout << "Rear element: " << deque.getRear() << std::endl;

    return 0;
}

*/

/* INPUT AND OUPUT RESTRICTED QUEUE
Input-Restricted Queue and Output-Restricted Queue are variations of the double-ended queue (deque). These queues limit the operations that can be performed at one or both ends.

Input-Restricted Queue
Insertion: Allowed only at one end (typically the rear).
Deletion: Allowed at both ends (front and rear).
Output-Restricted Queue
Insertion: Allowed at both ends (front and rear).
Deletion: Allowed only at one end (typically the front).


INPUT RESTRICTED

//ARRAY

#include <iostream>
#define SIZE 5

class InputRestrictedQueueArray {
    int items[SIZE];
    int front, rear;

public:
    InputRestrictedQueueArray() : front(-1), rear(-1) {}

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertRear(int element) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        items[rear] = element;
        std::cout << "Inserted " << element << " at rear\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int element = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return element;
    }

    int deleteRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int element = items[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "Queue elements: ";
        int i = front;
        while (true) {
            std::cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        std::cout << std::endl;
    }
};

int main() {
    InputRestrictedQueueArray queue;

    queue.insertRear(10);
    queue.insertRear(20);
    queue.insertRear(30);
    queue.insertRear(40);
    queue.insertRear(50);

    queue.display();

    std::cout << "Deleted from front: " << queue.deleteFront() << std::endl;

    queue.display();

    std::cout << "Deleted from rear: " << queue.deleteRear() << std::endl;

    queue.display();

    return 0;
}


//LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class InputRestrictedQueueLinkedList {
    Node* front;
    Node* rear;

public:
    InputRestrictedQueueLinkedList() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void insertRear(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        std::cout << "Inserted " << element << " at rear\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int element = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        return element;
    }

    int deleteRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int element = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        return element;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    InputRestrictedQueueLinkedList queue;

    queue.insertRear(10);
    queue.insertRear(20);
    queue.insertRear(30);
    queue.insertRear(40);
    queue.insertRear(50);

    queue.display();

    std::cout << "Deleted from front: " << queue.deleteFront() << std::endl;

    queue.display();

    std::cout << "Deleted from rear: " << queue.deleteRear() << std::endl;

    queue.display();

    return 0;
}

//OUTPUT RESTRICTED

//ARRAY
#include <iostream>
#define SIZE 5

class OutputRestrictedQueueArray {
    int items[SIZE];
    int front, rear;

public:
    OutputRestrictedQueueArray() : front(-1), rear(-1) {}

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int element) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        items[front] = element;
        std::cout << "Inserted " << element << " at front\n";
    }

    void insertRear(int element) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        items[rear] = element;
        std::cout << "Inserted " << element << " at rear\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int element = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "Queue elements: ";
        int i = front;
        while (true) {
            std::cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        std::cout << std::endl;
    }
};

int main() {
    OutputRestrictedQueueArray queue;

    queue.insertRear(10);
    queue.insertRear(20);
    queue.insertFront(5);
    queue.insertRear(30);
    queue.insertFront(2);

    queue.display();

    std::cout << "Deleted from front: " << queue.deleteFront() << std::endl;

    queue.display();

    return 0;
}

//LINKED LIST

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class OutputRestrictedQueueLinkedList {
    Node* front;
    Node* rear;

public:
    OutputRestrictedQueueLinkedList() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        std::cout << "Inserted " << element << " at front\n";
    }

    void insertRear(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        std::cout << "Inserted " << element << " at rear\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int element = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        return element;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    OutputRestrictedQueueLinkedList queue;

    queue.insertRear(10);
    queue.insertRear(20);
    queue.insertFront(5);
    queue.insertRear(30);
    queue.insertFront(2);

    queue.display();

    std::cout << "Deleted from front: " << queue.deleteFront() << std::endl;

    queue.display();

    return 0;
}


*/

/*DE PRIORITY QUEUE

A Double-Ended Priority Queue (DEPQ) is a special type of priority queue where you can:

Insert elements with priority.
Delete the element with the highest priority.
Delete the element with the lowest priority.
Retrieve (peek) the highest and lowest priority elements without removing them.
This means a DEPQ supports the following operations:

Insert (element, priority): Adds an element with a specified priority.
DeleteMin: Removes the element with the lowest priority.
DeleteMax: Removes the element with the highest priority.
GetMin: Retrieves the element with the lowest priority without removing it.
GetMax: Retrieves the element with the highest priority without removing it.
isEmpty: Checks if the queue is empty.


//ARRAY

#include <iostream>
#include <vector>
#include <algorithm>

class DEPQArray {
    std::vector<std::pair<int, int>> items; // pair<element, priority>

public:
    bool isEmpty() {
        return items.empty();
    }

    void insert(int element, int priority) {
        items.push_back({element, priority});
        std::sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a.second < b.second; // sort by priority
        });
        std::cout << "Inserted element: " << element << " with priority: " << priority << std::endl;
    }

    std::pair<int, int> getMin() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return {-1, -1};
        }
        return items.front();
    }

    std::pair<int, int> getMax() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return {-1, -1};
        }
        return items.back();
    }

    void deleteMin() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return;
        }
        auto minElement = items.front();
        items.erase(items.begin());
        std::cout << "Deleted element with min priority: " << minElement.first << std::endl;
    }

    void deleteMax() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return;
        }
        auto maxElement = items.back();
        items.pop_back();
        std::cout << "Deleted element with max priority: " << maxElement.first << std::endl;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return;
        }
        std::cout << "DEPQ elements: ";
        for (auto &item : items) {
            std::cout << "{" << item.first << ", " << item.second << "} ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DEPQArray depq;

    depq.insert(10, 3);
    depq.insert(20, 2);
    depq.insert(30, 5);
    depq.insert(40, 1);
    depq.insert(50, 4);

    depq.display();

    std::cout << "Min element: " << depq.getMin().first << std::endl;
    std::cout << "Max element: " << depq.getMax().first << std::endl;

    depq.deleteMin();
    depq.display();

    depq.deleteMax();
    depq.display();

    return 0;
}


//LINKED LIST

#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;
    Node* prev;
    Node(int d, int p) : data(d), priority(p), next(nullptr), prev(nullptr) {}
};

class DEPQLinkedList {
    Node* head;
    Node* tail;

public:
    DEPQLinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(int element, int priority) {
        Node* newNode = new Node(element, priority);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            Node* current = head;
            while (current != nullptr && current->priority <= priority) {
                current = current->next;
            }
            if (current == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (current == nullptr) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
        std::cout << "Inserted element: " << element << " with priority: " << priority << std::endl;
    }

    Node* getMin() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return nullptr;
        }
        return head;
    }

    Node* getMax() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return nullptr;
        }
        return tail;
    }

    void deleteMin() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        std::cout << "Deleted element with min priority: " << temp->data << std::endl;
        delete temp;
    }

    void deleteMax() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        std::cout << "Deleted element with max priority: " << temp->data << std::endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "DEPQ is empty\n";
            return;
        }
        Node* temp = head;
        std::cout << "DEPQ elements: ";
        while (temp != nullptr) {
            std::cout << "{" << temp->data << ", " << temp->priority << "} ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DEPQLinkedList depq;

    depq.insert(10, 3);
    depq.insert(20, 2);
    depq.insert(30, 5);
    depq.insert(40, 1);
    depq.insert(50, 4);

    depq.display();

    if (auto min = depq.getMin())
        std::cout << "Min element: " << min->data << std::endl;
    
    if (auto max = depq.getMax())
        std::cout << "Max element: " << max->data << std::endl;

    depq.deleteMin();
    depq.display();

    depq.deleteMax();
    depq.display();

    return 0;
}

*/




