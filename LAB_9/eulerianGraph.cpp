#include<iostream> 
#include <list> 

using namespace std; 

// KLASA 

class Graph 
{ 
	int V;

    // LISTA SĄSIEDZTWA TUTAJ DLA KAŻDEGO WIERZCHOŁKA

	list<int> *adj;
public: 

	Graph(int V) 
    { 
        this->V = V; 
        adj = new list<int>[V]; 
    }

	~Graph() { delete [] adj; }

	void addEdge(int v, int w); 
	int isEulerian(); 
    void printGraph();
    void printVertex(int x); 

}; 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v);
} 

// SPRAWDZA CZY GRAF JEST GRAFEM EULEROWSKIM 
// ŻEBY BYŁA ŚCIEŻKA TO KAŻDY ZA WYJĄTKIEM DWÓCH MA BYĆ PARZYSTY
// ŻEBY BYŁ CYKL TO KAŻÐY MUSI BYĆ PARZYSTY 

int Graph::isEulerian() 
{ 
	int odd = 0; 
	for (int i = 0; i < V; i++) 
		if (adj[i].size() & 1) // bitwise AND
			odd++; 

	if (odd > 2) 
		return 0; 

	return (odd) ? 1 : 2; 
} 

// TA WYPISUJE PUNKTY Z LISTĄ SĄSIEDZTWA ICH OD RAZU

void Graph::printGraph() 
{ 
	for (int v = 0; v < V; v++) 
	{ 
		cout << "\n Lista sasiedztwa dla wierzcholka: "
			<< v << "\n head "; 
        int count = 0;
		for (auto x : adj[v]) 
        {
		    cout << "-> [" << x << "]"; 
            count++;
        }

        cout << "LICZBA KRAWĘDZI WIERZCHOŁKA: " << count;

        if(count % 2 == 0)
        {
            cout << "- PARZYSTA" << endl;
        }
        else 
        {
            cout << " - NIEPARZYSTA" << endl;
        }

        cout << endl; 
	} 
} 

void Graph::printVertex(int x) 
{ 
    bool is = false;

	for (int v = 0; v < V; v++) 
	{ 
    
        if(v == x)
        {
            cout << "\n Lista sasiedztwa dla wierzcholka: "
                << v << "\n head "; 
            int count = 0;
            for (auto x : adj[v]) 
            {
                cout << "-> [" << x << "]"; 
                count++;
            }

            cout << "LICZBA KRAWĘDZI WIERZCHOŁKA: " << count;

            if(count % 2 == 0)
            {
                cout << "- PARZYSTA" << endl;
            }
            else 
            {
                cout << " - NIEPARZYSTA" << endl;
            }

            cout << endl; 
            is = true;
        }
	} 

    if(!is)
        cout << "NIE MA TAKIEGO WIERZCHOŁKA!" << endl;
} 

void test(Graph &g) 
{ 
	int res = g.isEulerian(); 

	if (res == 0) 
		cout << "NIE JEST GRAFEM EULERA" << endl; 
	else if (res == 1) 
		cout << "MA ŚCIEŻKĘ EULERA" << endl; 
	else
		cout << "MA CYKL EULERA" << endl; 
} 

int main() 
{ 
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,5);
    g.addEdge(5,3);
    g.addEdge(3,4);
    g.addEdge(4,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(2,6);
    g.addEdge(6,0);
    g.addEdge(2,1);

    // int x;
    // cin >> x;

    // g.printVertex(x);
    
    test(g);
     
	return 0; 
} 
