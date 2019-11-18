#include <iostream>
#include <vector>
#include <fstream>

using namespace std; 
  
struct Node 
{ 
    int data; 
    Node *left;
    Node *right; 
}; 

Node* newNode(int data) 
{ 
    Node* node = new Node;

    node->data = data; 
    node->left = NULL;
    node->right = NULL; 

    cout << "Inserting: " << node->data << endl; 

    return node; 
} 

Node* insertLevelOrder(vector<int> tab, Node* root, int i, int n) 
{ 
    if (i < n) 
    { 
        Node* temp = newNode(tab[i]); 
        root = temp; 
  
        root->left = insertLevelOrder(tab, root->left, 2 * i + 1, n); 
  
        root->right = insertLevelOrder(tab, root->right, 2 * i + 2, n); 
    }

    return root; 
} 
  
void preOrder(Node* root) 
{ 
    if (root != NULL) 
    { 
        cout << root->data <<" "; 
        preOrder(root->left);  
        preOrder(root->right); 
    } 
} 

void inOrder(Node* root) 
{ 
    if (root != NULL) 
    { 
        inOrder(root->left);  
        cout << root->data <<" "; 
        inOrder(root->right); 
    } 
} 

void postOrder(Node* root) 
{ 
    if (root != NULL) 
    { 
        postOrder(root->left);  
        postOrder(root->right); 
        cout << root->data <<" ";
    } 
} 
  
int main() 
{ 
    fstream plik;

    std::vector<int> tab;

    int value;

    plik.open("lista.txt",std::ios::in | std::ios::out);
    if( plik.good() == true )
    {
        while (plik>>value)
        {
            tab.push_back(value);
        }
    }

    int n = tab.size();
    
    Node* root = insertLevelOrder(tab, root, 0, n); 

    preOrder(root); 
    cout << endl;

    //inOrder(root);
    //cout << endl;
    //postOrder(root);

    plik.close();
} 
  

