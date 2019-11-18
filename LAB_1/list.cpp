#include <iostream>

using namespace std;

class List
{
    public:

    struct Node
    {
        Node * next;
        int data;
    };

    Node* head;

    List()
    {
        head = NULL;
    }

    ~List()
    {

    }

    void add(int value)
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

    void del(int x)
    {
        if(x == 1) 
        {
            // usuwanie pierwszego elementu

            Node *p = head; 

            head = p->next;  
            delete p;
        
        }
        else if(x >= 2)
        {
        int j = 1;

        Node *temp = head;

        while (temp)
        {
            if ((j+1) == x) break;

            temp = temp->next;
            j++;
        }

        if (temp->next->next == 0)
                temp->next = 0;

        else        
            temp->next = temp->next->next;
    }
}
    void remove(int x)
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



    void print()
    {
        unsigned i;
        Node *p = head;

        for(i = 1; p; p = p->next) 
        {
            cout << "Element " << i++ << ".  data = " << p->data << endl;
        }
        
        cout << endl;
    }

};


int main()
{
    List L;

    L.add(2);
    L.add(4);
    L.add(5);

    L.print();

    L.remove(1);

    L.print();



    return 0;
}