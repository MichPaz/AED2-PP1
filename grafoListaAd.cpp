#include <iostream>
#include <vector>

typedef int Vertex;

using namespace std;

class Graph
{
	private:
		vector<Vertex>*  adj;
		int n, m;

	public:
		void destroy();
		Graph(int);
		void initialize(int);
		void insertEdge(Vertex,Vertex);
		void print();

		vector<Vertex>* getAdj();
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
	adj = new vector<Vertex>[n+1];
}

void Graph::insertEdge(Vertex u, Vertex v)
{
	Vertex x = v;
	adj[u].push_back(x);
	x = u;
	adj[v].push_back(x);
	m++;
}

void Graph::print()
{
	for(int i = 1; i <= n; i++){
        //cout << "qnt de vertice adj. = " << adj[i].size() <<endl;
        //cout << "get - " << adj[i].get(1) << endl;
		cout <<"v["<<i<<"] = ";
		for(int j = 0; j < adj[i].size();j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}

vector<Vertex>* Graph::getAdj()
{
	return adj;
}

void Graph::destroy()
{
	for (int i = 0; i <= n; i++)
		adj[i].clear();
	delete adj;
}

int main(int argc, const char* argv[])
{
	int n,m;

	cout << "ordem: ";
	cin >> n;

	Graph g(n);

	testaGrafo(g);

	g.print();

	return 0;
}
