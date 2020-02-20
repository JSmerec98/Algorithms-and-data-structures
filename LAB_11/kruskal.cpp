#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

typedef pair<int, int> iPair; 

struct Graph 
{ 
	int V, E; 
	// 	WEKTOR KRAWĘDZI MINIMALNEGO DRZEWA: (KOSZT PRZEJŚCIA, {PIERWSZY WIERZCHOŁEK, DRUGI WIERZCHOŁEK})
	vector< pair<int, iPair> > edges; 

	Graph(int V, int E) 
	{ 
		this->V = V;
		this->E = E;
	} 

	void addEdge(int u, int v, int w) 
	{ 
		edges.push_back({w, {u, v}}); 
	} 

	int kruskalMST(); 
}; 

struct DisjointSets 
{ 
	int *parent; //  RODZIC
	int *rank; // TAK JAKBY ROZMIAR GAŁĄZKI JAK PRZYŁĄCZASZ NOWE TO ZWIĘKSZASZ O JEDEN
	int n; 

	DisjointSets(int n) 
	{ 
		this->n = n; 
		parent = new int[n+1]; 
		rank = new int[n+1]; 

		// NA POCZĄTKU WSZYSTKIE SĄ ROZDZIELONE
		for (int i = 0; i <= n; i++) 
		{ 
			rank[i] = 0; 

			// KAŻDY JEST RODZICEM DLA SAMEGO SIEBIE
			parent[i] = i; 
		} 
	} 

	// ZNAJDUJE RODZICA WIERZCHOŁKA U (NA POCZĄTKU KAŻDY JEST SWOIM RODZICEM A POTEM JUZ MAMY USTAWIONE PRZEZ MERGE WIĘC JAK ROBI FIND TO JEST USTAWIONY :) 
	int find(int u) 
	{ 
		if (u != parent[u]) 
			parent[u] = find(parent[u]); 

		return parent[u]; 
	} 

	// ZŁĄCZENIE
	void merge(int x, int y) 
	{ 
		x = find(x), y = find(y); 

		// DOŁĄCZAMY MNIEJSZE DO WIĘKSZEGO 
		if (rank[x] > rank[y]) 
			parent[y] = x; 
		else // JAK RÓWNE TO Y JEST RODZICEM 
			parent[x] = y; 

		// JEŻELI SĄ RÓWNO TWORZYMY ZŁĄCZONY GDZIE Y JAKO RODZIC
		if (rank[x] == rank[y]) 
			rank[y]++; 
	} 
}; 

int Graph::kruskalMST()
{ 
	int mst_wt = 0;

	// SORTOWANIE KRAWĘDZI WEDŁUG KOSZTÓW
	sort(edges.begin(), edges.end());

	// TWORZY ZBIORY ROZŁĄCZNE DLA KAŻDEGO WIERZCHOŁKA OSOBNY NA POCZĄTKU
	DisjointSets ds(V); 

	// PRZECHODZI PO WSZYSTKICH POSORTOWANYCH KRAWĘDZIACH
	vector< pair<int, iPair> >::iterator it; 
	for (it = edges.begin(); it != edges.end(); it++) 
	{ 
		int u = it->second.first;
		int v = it->second.second; 

		int set_u = ds.find(u); 
		int set_v = ds.find(v); 

		// JEŚLI NIE TWORZĄ CYKLU
		if (set_u != set_v) 
		{ 
			// WYPISUJEMY KRAWĘDŹ
			cout << u << " - " << v << endl; 

			mst_wt += it->first; 

			// ZŁĄCZAMY ZBIORY
			ds.merge(set_u, set_v); 
		} 
	} 

	return mst_wt; 
} 

int main() 
{ 
	int V = 8; 
	int E = 10; 
	Graph g(V, E);

	g.addEdge(0,1,2);  
	g.addEdge(1,2,6);
	g.addEdge(2,3,7);
	g.addEdge(3,4,9);
	g.addEdge(4,5,1);
	g.addEdge(5,6,10);
	g.addEdge(5,7,3);
	g.addEdge(0,7,6);
	g.addEdge(1,5,4);
	g.addEdge(2,5,11);
	
	cout << "KRAWĘDZIE MINIMALNEGO DRZEWA ROZPINAJĄCEGO\n"; 
	int mst_wt = g.kruskalMST(); 

	cout << "\nWAGA MINIMANLEGO DRZEWA ROZPINAJĄCEGO: " << mst_wt << "\n";

	return 0; 
} 
