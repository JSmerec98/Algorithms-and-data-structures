#include<iostream> 
#include <list> 

using namespace std; 

class Graph 
{ 
	int V;

	list<int> *adj;

    void DFSUtil(int v, bool visited[]); 

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

    // Depth First Search 
    void DFS();
    // Breadth First Search
    void BFS(int x);   

}; 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	//adj[w].push_back(v);
} 

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

void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 

    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
void Graph::DFS() 
{  
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    // SPRAWDZENIE CZY JEST JAKIŚ NIEPOŁĄCZONY
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
} 

void Graph::BFS(int s) 
{ 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 

    list<int> queue; 

    visited[s] = true; 
    queue.push_back(s); 

    list<int>::iterator i;
  
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        for (i = adj[s].begin(); i != adj[s].end(); i++) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 

int main() 
{ 
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,5);
    g.addEdge(5,4);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,5);
    //g.addEdge(2,5);
    g.addEdge(2,3);

    g.DFS();
    cout << endl;
    g.BFS(0);

    //g.printGraph();
     
	return 0; 
} 
