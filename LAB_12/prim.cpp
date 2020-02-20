#include<bits/stdc++.h> 

using namespace std; 
  
typedef pair<int, int> iPair; 
  
class Graph 
{ 
    int V; 
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V); 

    void addEdge(int u, int v, int w); 

    void primMST(); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    // PARA Z KIERUNKIEM KRAWĘDZI I WARTOŚĆIĄ JEJ
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w)); 
} 
  
void Graph::primMST() 
{ 
    // KOJELKA PRORYTEROWA DLA WIERZOCHŁÓW DODAWANYCH DO DRZEWA
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    // TYPE, vector TYPE, comparsionType
    
    int src = 0;
   
    // INICJALIZACJA KLUCZY NA NIESKOŃCZOŚĆ WSZYSTKICH
    // KLUCZ = KOSZT KRAWĘDZI
    vector<int> key(V, 1000); 
  
    // INICJALIZACJA RODZICÓW WSZYSTKICH NA -1
    vector<int> parent(V, -1);
  
    // DO ZAPISYWANIA CZY SĄ W MST INICIALIZACJA NA FALSE BO ŻADEN NIE JEST JESZCZE
    vector<bool> inMST(V, false);
  
    // DODANIE DO KOLEJKI ŹRÓDŁA Z KLUCZEM 0 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    // PĘTLA DOPÓKI KOLEJKA NIE JEST PUSTA
    while (!pq.empty()) 
    { 
        int u = pq.top().second;
        pq.pop();
  
        inMST[u] = true;  // DODANIE WIERZCHOŁKA DO MST

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        { 
            int v = (*i).first;
            int weight = (*i).second;

            // JEŚLI NIE MA W DRZEWIE I KLUCZ JEST WIĘKSZY NIŻ WAGA
            if (inMST[v] == false && key[v] > weight) 
            { 
                // AKTUALIZACJA WIERZCHOŁKA
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            }
        } 
    } 

    cout << "MST:" << endl; 

    for (int i = 1; i < V; i++) 
        cout <<  parent[i] << "->" << i << endl; 
} 
  
int main() 
{ 
    int V = 9; 
    Graph g(V); 
  
    g.addEdge(0,1,1); 
    g.addEdge(0,2,3);
    g.addEdge(1,3,3);
    g.addEdge(1,2,4);
    g.addEdge(1,4,2);
    g.addEdge(2,4,4);
    g.addEdge(2,8,3);
    g.addEdge(3,4,1);
    g.addEdge(3,5,2);
    g.addEdge(4,5,6);
    g.addEdge(4,6,5);
    g.addEdge(4,7,4);
    g.addEdge(5,6,7);
    g.addEdge(6,8,6);
    g.addEdge(6,7,2);
    g.addEdge(7,8,1);

    g.primMST(); 
  
    return 0; 
} 
