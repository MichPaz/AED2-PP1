#include <iostream>
#include "LSE.cpp"

typedef int Vertex;

using namespace std;

class Graph
{
	private:
		list<Vertex> *adj;
		int n, m;

		void destroy();
	public:
		Graph(int);
		void initialize(int);
		void insertEdge(Vertex,Vertex);
		void print();

		void setN(int);
		void setM(int);
		void setAdj(list<Vertex>*);

		int getN();
		int setM();
		list<Vertex>* getAdj();
};

void testaGrafo(Graph &g)
{
	g.insertEdge(1,2);
	g.insertEdge(2,3);
	g.insertEdge(3,4);
	g.insertEdge(4,5);
	g.insertEdge(5,1);
	g.insertEdge(5,2);
	g.insertEdge(2,4);
	g.print();
}

Graph::Graph(int n)
{
	initialize(n);
}

void Graph::initialize(int n)
{
	this->n = n;
	adj = new list<Vertex>[n+1];
}

void Graph::insertEdge(Vertex u, Vertex v)
{
	Vertex x = {v};
	adj[u].insert(x);
	x = {u};
	adj[v].insert(x);
	m++;
}

void Graph::print()
{
	for(int i = 1; i <= n; i++){
        //cout << "qnt de vertice adj. = " << adj[i].size() <<endl;
        //cout << "get - " << adj[i].get(1) << endl;
		cout <<"v["<<i<<"] = ";
		adj[i].show();
	}
}

void Graph::destroy()
{
	for(int i = 0; i <= n; i++){
		adj[i].destroy();
	}
	delete adj;
	n = m = 0;
}



int main(int argc, const char* argv[])
{
	int n,m;

	cout << "ordem: ";
	cin >> n;

	Graph g(n);

	testaGrafo(g);

	return 0;
}
