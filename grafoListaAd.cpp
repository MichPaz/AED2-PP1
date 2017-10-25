#include <iostream>
#include <vector>

typedef int Vertex;

using namespace std;

class Graph
{
	private:
		vector<Vertex>*  adj;
		int n, m;
		void destroy();

	public:
		Graph(int);
		void initialize(int);
		void insertEdge(Vertex,Vertex);
		void print();

		int getN();
		vector<Vertex>* getAdj();
};

void testaGrafo(Graph &g)
{
		g.insertEdge(1,2);
    g.insertEdge(1,5);
    g.insertEdge(2,6);
    g.insertEdge(3,6);
    g.insertEdge(3,7);
    g.insertEdge(3,4);
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

int particao(std::vector<Vertex>& A, int p, int r)
{
	Vertex x = A[p];
	Vertex tmp = A[r+1];
	A[r+1] = x;

	int i = p;
	int j = r+1;

	while (true){
		do{
			i++;
		}while(A[i] < x);

		do{
			j--;
		}while(A[j] > x);

		if (i < j){
			troca(&A[i],&A[j]);
		}
		else{
			troca(&A[p],&A[j]);
			A[r+1] = tmp;
			break;
		}
	}
	return j;
}

void quickSort(std::vector<int>& A, int p, int r)
{
	if (p < r){
		int q = particao(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}


//Main===================================================================================
int main(int argc, const char* argv[])
{
	int n,m;

	cout << "ordem: ";
	cin >> n;

	Graph g(n);

	testaGrafo(g);

	return 0;
}




//Funcoes da classe Graph=============================================================
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


	quickSort(adj[u],0,adj[u].size()-1);
	quickSort(adj[v],0,adj[v].size()-1);

	m++;
}

void Graph::print()
{
	for(int i = 1; i <= n; i++){
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

int Graph::getN()
{
	return n;
}

void Graph::destroy()
{
	for (int i = 0; i <= n; i++)
		adj[i].clear();
	delete adj;
}
