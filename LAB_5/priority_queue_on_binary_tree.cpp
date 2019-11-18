#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node *parent;
    Node *left;
    Node *right;
    int key;
    string data;
};

class Queue
{
  private:
    
    Node *root;    

    Node* insert(int x, Node* t,string v);
    void InOrder(Node* node);

  public:

    Queue();

    void push(int x,string v);
    void pop();
    void InOrder();
};

Queue::Queue()
{
    root = NULL;
}

Node* Queue::insert(int x, Node* t,string v)
{
    if(t == NULL)
    {
        t = new Node;
        t->key = x;
        t->left = t->right = NULL;
        t->parent = NULL;
        t->data = v;
    }
    else if(x > t->key)
    {
        t->left = insert(x,t->left,v);
        t->left->parent = t;
    }
    else if(x < t->key)
    {
        t->right = insert(x,t->right,v);
        t->right->parent = t;
    }

    return t;
}

void Queue::pop()
{
    Node *p;

    if(root != NULL)         
    {               
        for(p = root; p->right; p = p->right);

        if(p->left) 
            p->left->parent = p->parent;

        if(p->parent) 
            p->parent->right = p->left;
        else 
            root = p->left;

        delete p;
    }
}

void Queue::InOrder(Node* node)
{ 
    if (node != NULL) 
    { 
        InOrder(node->left);  
        cout << node->data << endl;
        InOrder(node->right); 
        
    } 
}

void Queue::InOrder()
{ 
    InOrder(root);
} 

void Queue::push(int x,string v)
{
    root = insert(x,root,v);
}

int main()
{
    Queue *Q = new Queue;

    Q->push(1,"STRING1");
    Q->push(2,"STRING2");
    Q->push(3,"STRING3");
    Q->push(5,"STRING4");
    Q->push(0,"STRING5");

    Q->InOrder();
    cout << endl;

    Q->pop();
    //Q->pop();

    Q->InOrder();

    return 0;
}
