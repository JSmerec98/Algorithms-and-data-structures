#include <iostream>

using namespace std;

// // NODE

struct Node
{
  Node * next;
  int data;
};

// LIST

class List
{
    public:

        Node* head;

        List();

        void add(int value);
        void remove(int x);
        void print();
};

// QUEUE

class Queue: public List
{       
    public:
        
        Node *tail;

        Queue();
        ~Queue();

        void enqueue(int v);
        void dequeue(void);  
};

// STACK

class Stack: public List
{
    public:

        Stack(); 

        void push(int x); 
        int pop();
};

// LIST METHODS

List::List()
{
    head = NULL;
}

void List::add(int value)
{

    Node *temp, *p;
        
    temp = new Node;
    temp->next = NULL;
    temp->data = value;

    p = head;
    if(p)
    {
        while(p->next) p = p->next;
        p->next = temp;
    }
    
    else head = temp;
}

void List::remove(int x)
{
    Node * p;
    Node *temp = head;
    int j = 1;

        while (temp)
        {
            if ((j) == x) break;
            temp = temp->next;
            j++;
        }

        if(head == temp)
        {
            Node *z = head; 
            head = z->next;  
            delete z;
        }
        
        else
        {
            p = head;
            while(p->next != temp) p = p->next;
            p->next = temp->next;
            delete temp;
        }
} 

void List::print()
{
    unsigned i;
    Node *p = head;

    cout << endl;

    for(i = 1; p; p = p->next) 
    {
        cout << "Element " << i++ << ".  data = " << p->data << endl;
    }
   
    cout << endl;
}

// QUEUE METHODS

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while (head) dequeue();
}


void Queue::enqueue(int v)
{
    Node* p = new Node;
    p->next = NULL;
    p->data = v;

    cout << "Inserting " << v << endl;

    if(tail) tail->next = p;
    else head = p;
    tail = p;
}

void Queue::dequeue()
{
    if(head)
    {
        Node* p = head;
        head = head->next;

        cout << "Removing " << p->data << endl;
        
        if(!head) tail = NULL;

        delete p;
    }
}

// STACK METHODS

Stack::Stack()
{
    head = NULL;
}

void Stack::push(int x)
{
    Node *temp = new Node;

    cout << "PUSHED " << x << " ON THE STACK!" << endl;

    temp->data = x;
    temp->next = head; 
    
    head = temp;
}

int Stack::pop()
{
    if(head != NULL)
    {
        cout << "POPPED " << head->data << " OF A STACK!" << endl;

        int value = head->data;
        Node *oldHead = head;
        head = oldHead->next;
        delete oldHead;
        return value;
    }
    else
    {
        cout << "CANT POP FROM THE EMPTY STACK!" << endl;
        exit(1);
    }
}


int main()
{
    //////////////// QUEUE  ////////////////


    cout << "QUEUE: " << endl;
    Queue Q;

    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(2);

    Q.print();
    Q.dequeue();
    Q.print();

    //////////////// STACK ////////////////

    cout << "STACK: " << endl;
    Stack S;

    S.push(3);
    S.push(5);
    S.push(4);
    S.push(6);

    S.print();

    S.pop();
    S.pop();

    S.print();

    return 0;
}
