#include <iostream>
#include "LSE.cpp"

typedef int Vertex;
 
using namespace std;

class Graph
{
	private:
		list<Vertex>*  adj;
		int n, m;
		void destroy();

	public:
		Graph(int);
		void initialize(int);
		void insertEdge(Vertex,Vertex);
		void print();

		int getN();
		list<Vertex>* getAdj();
};

void testaGrafo(Graph &g)
{
	g.insertEdge(2,8);
	g.insertEdge(1,5);
	g.insertEdge(1,2);
    g.insertEdge(1,6);
    g.insertEdge(3,6);
    g.insertEdge(3,7);
    g.insertEdge(8,4);
    g.insertEdge(4,7);
    g.insertEdge(4,8);
    g.insertEdge(6,7);
    g.insertEdge(7,8);

	g.print();
}

//quickSort=====================================================================================
void troca(Vertex* x, Vertex* y)
{
	Vertex aux = *x;
	*x = *y;
	*y = aux;
}

int particao(list<Vertex>& A, int p, int r)
{
	Vertex x = A.at(p)->item;
	Vertex tmp = A.at(r+1)->item;
	A.at(r+1)->item = x;

	int i = p;
	int j = r+1;

	while (true){
		do{
			i++;
		}while(A.at(i)->item < x);

		do{
			j--;
		}while(A.at(j)->item > x);

		if (i < j){
			troca(&A.at(i)->item, &A.at(j)->item);
		}
		else{
			troca(&A.at(p)->item, &A.at(j)->item);
			A.at(r+1)->item = tmp;
			break;
		}
	}
	return j;
}

void quickSort(list<int>& A, int p, int r)
{
	if (p < r){
		int q = particao(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

//Funcoes da classe Graph=============================================================
Graph::Graph(int n)
{
	initialize(n);
}

void Graph::initialize(int n)
{
	this->n = n;
	adj = new list<int>[n+1];
}

void Graph::insertEdge(Vertex u, Vertex v)
{
	Vertex x = v;
	adj[u].insert(x);
	x = u;
	adj[v].insert(x);

	quickSort(adj[u], 0, adj[u].size()-1);
	quickSort(adj[v], 0, adj[v].size()-1);	
	
	m++;
}

void Graph::print()
{
	for(int i = 1; i <= n; i++){
		cout <<"v["<<i<<"] = ";
		adj[i].show();
		cout << endl;
	}
}

list<Vertex>* Graph::getAdj()
{
	return adj;
}

int Graph::getN()
{
	return n;
}

void Graph::destroy()
{
	for (int i = 0; i <= n; i++)
		adj[i].destroy();
	delete adj;
}

int main(int argc, char const *argv[])
{
	Graph g(8);

	testaGrafo(g);

	return 0;
}