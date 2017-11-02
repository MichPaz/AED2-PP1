#include <iostream>
#include <limits>
#include <vector>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

typedef int Vertex;

using namespace std;

//Lista Encadeada ==============================================================================
//Classe do No da lista encadeada
template <typename T>
class node
{
public:
	T item;
	node* next;
	node* previous;
	int id;

	node(){
		next = NULL;
	}
};

//Classe da lista encadeada
template <typename T>
class list
{
public:
	int cont;
	node<T>* first;
	node<T>* last;

	list(){
		first = new node<T>();
		first->previous = NULL;


		last = new node<T>();
		last->next = NULL;
		last->previous = first;
		first->next = last;

		cont = 0;

		last->id = cont;
	}

	void insert(T);
	void remove(T);
	void show();
	T get(int);
	int size();
	node<T>* at(int);
	node<T>* prev(node<T>*);
	void destroy();
};

//Funcoes da lista encadeada
template <typename T>
void list<T>::insert(T item)
{
	last->item = item;

	last->next = new node<T>();
	last->next->previous = last;
	last = last->next;
	last->next = NULL;

	cont++;

	last->id = cont;
}

template <typename T>
node<T>* list<T>::at(int ind)
{
	node<T>* n = first->next;
	while((n!=last)&&(n->id != ind))
		n = n->next;
	return n;
}


template <typename T>
void list<T>::show()
{
	if(last->id == 0)
		std::cout<<"LISTA VAZIA\n";
	else{
		node<T>* nod = first->next;
		while(nod->next!=NULL){
			if(nod->next!=NULL)
				std::cout << nod->item << "\t";
			nod = nod->next;
		}
		std::cout << std::endl;
	}
}

template <typename T>
T list<T>::get(int i)
{
    int c = 0;
    node<T>* nod = first->next;
	while(nod!=NULL){
        if(c==i){
            return nod->item;
        }
		if(nod!=NULL)
			c++;
		nod = nod->next;
	}
	return NULL;
}

template <typename T>
int list<T>::size()
{
	return cont;
}

template <typename T>
void list<T>::destroy()
{
	node<T>* nod = first;
	while(nod!=NULL){
		node<T>* n = nod;
		nod = nod->next;
		delete n;
	}

	first = new node<T>();
	first->next = NULL;
	last = first;
}

//Classe da Fila ======================================================================
template <class T>
class NoFila
{
private:
    T item;
    NoFila<T>* prox;
public:
    NoFila();

    void setItem(T);
    void setProx(NoFila<T>*);

    T getItem();
    NoFila<T>* getProx();
};

template <class T>
NoFila<T>::NoFila(){
    prox = NULL;
}

template <class T>
void NoFila<T>::setItem(T item)
{
    this->item = item;
}

template <class T>
void NoFila<T>::setProx(NoFila<T>* prox)
{
    this->prox = prox;
}

template <class T>
T NoFila<T>::getItem()
{
    return item;
}

template <class T>
NoFila<T>* NoFila<T>::getProx()
{
    return prox;
}



//Classe Fila
template <class T>
class Fila
{
private:
    NoFila<T> *frente ;
    NoFila<T> *tras ;
public:
    Fila();
    void enfileira(T);
    T desenfileira();
    bool vazia();
    void print();
};

//Funcoes da classe Fila
template <class T>
Fila<T>::Fila()
{
    frente = new NoFila<T>;
    frente->setProx(NULL);
    tras = frente;
}

template <class T>
void Fila<T>::enfileira(T item)
{
    tras->setProx(new NoFila<T>);
    tras = tras->getProx();
    tras->setItem(item);
    tras->setProx(NULL);
}

template <class T>
T Fila<T>::desenfileira()
{
    NoFila<T>* aux = frente;
    frente=frente->getProx();

    NoFila<T>* aux1 = aux;
    delete aux1;

    return frente->getItem();
}

template <class T>
bool Fila<T>::vazia()
{
    return tras==frente;
}

template <class T>
void Fila<T>::print()
{
    NoFila<T> *aux = frente;
    if (vazia()){
        cout << "lista vazia"<< endl;
    }else{
        while(aux->getProx()!=NULL)
        {
            aux = aux->getProx();
            cout << aux->getItem() << endl;
        }
    }
}

//Representacao do Grafo pela lista de adjacencia =========================================
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


//QuickSort
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

//Funcoes da classe Graph
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

//Classe de vertice para BFS ========================================================
class VertexBFS
{
private:
    int d; //distancia do ponto p para a BFS
    int p; //prnode<T>* nod = first->next;edecessor
    int cor; //0-branco  1-cinza  2-preto

public:

    VertexBFS();

    void setD(int);
    void setP(int);
    void setCor(int);

    int getD();
    int getP();
    int getCor();
};

VertexBFS::VertexBFS()
{
    this->d = 0;
    this -> p = 0;
    this->cor = 0;
}

void VertexBFS::setD(int i)
{
    this->d = i;
}
void VertexBFS::setP(int i)
{
    this->p = i;
}
void VertexBFS::setCor(int i)
{
    this->cor = i;
}

int VertexBFS::getD()
{
    return this->d;
}

int VertexBFS::getP()
{
    return this->p;
}

int VertexBFS::getCor()
{
    return this->cor;
}


//BFS---------------------------------------------------------------------------------------
vector<VertexBFS> bfs(Graph &graph, int s)
{
    vector<VertexBFS> u(graph.getN()+1);
    Graph gr(graph.getN());

    for(int i = 1; i <= graph.getN(); i++){
        u[i].setCor(0);
        u[i].setD(0);
        u[i].setP(-1);
    }

    u[s].setCor(1);
    u[s].setD(0);
    u[s].setP(-1);

    Fila<int> q;
    q.enfileira(s);

    while(!q.vazia()){

        int j = q.desenfileira();

        for(int i = 0; i<graph.getAdj()[j].size(); i++){
            if(u[graph.getAdj()[j].at(i)->item].getCor()==0){

                u[graph.getAdj()[j].at(i)->item].setCor(1);
                u[graph.getAdj()[j].at(i)->item].setD(u[j].getD()+1);
                u[graph.getAdj()[j].at(i)->item].setP(j);

                gr.insertEdge(j,graph.getAdj()[j].at(i)->item);
                q.enfileira(graph.getAdj()[j].at(i)->item);
            }
        u[j].setCor(2);
        }
    }
    graph = gr;
    return u;
}

//Aplicacao no problema ====================================================================

//Retorna se e possivel fazer a jogada em "L"
bool inRange(int i, int j)
{
    return ( (i>=0) &&(i<8) && (j >=0) && (j<8) );
}

//Retorna todos os movimentos em "L" possiveis a partir da posicao p
vector<int> movL(int p)
{
    vector <int> pos;
    int tabuleiro[8][8];
    int cont=1, x,y;


    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
                tabuleiro[j][i]=cont;
                if(p == cont){
                    x=j;
                    y=i;
                }
                cont++;
        }
    }
    //Movimentos em "L" possiveis
    if(!inRange(x,y)){
        cout << "posicao invalida, erro na posicao do tabuleiro.\n" ;
        cout << "(x,y) = " << "(" << x << "," << y << ")\n";
    }

    if(inRange(x+2,y+1))
        pos.push_back(tabuleiro[x+2][y+1]);
    if(inRange(x+2,y-1))
        pos.push_back(tabuleiro[x+2][y-1]);
    if(inRange(x-2,y+1))
        pos.push_back(tabuleiro[x-2][y+1]);
    if(inRange(x-2,y-1))
        pos.push_back(tabuleiro[x-2][y-1]);
    if(inRange(x+1,y+2))
        pos.push_back(tabuleiro[x+1][y+2]);
    if(inRange(x+1,y-2))
        pos.push_back(tabuleiro[x+1][y-2]);
    if(inRange(x-1,y+2))
        pos.push_back(tabuleiro[x-1][y+2]);
    if(inRange(x-1,y-2))
        pos.push_back(tabuleiro[x-1][y-2]);

    return pos;

}

//Retorna um grafo que possui todas as jogadas possiveis no tabuleio a partir da posicao inicial
Graph geraCaminhos(int posInicial){

    if (posInicial<0 || posInicial>64){
        cout << "Posicao inicial invalida = " << posInicial << endl;
    }

    int visited[65];
    for(int i=1;i<=64;i++){
        visited[i]=0;
    }
    Graph graph(64);
    Fila<int> q;
    q.enfileira(posInicial);
    while(!q.vazia()){
        int u = q.desenfileira();
        for(unsigned int i = 0; i < movL(u).size();i++){
            if((unsigned)visited[movL(u).at(i)]<movL(movL(u).at(i)).size()){
                int cont = 0;
                for(int k=0;k<graph.getAdj()[u].size();k++){
                    if(movL(u).at(i)==graph.getAdj()[u].at(k)->item)
                        cont++;
                }
                if(cont==0){
                    graph.insertEdge(u, movL(u).at(i));
                    visited[movL(u).at(i)]++;
                    q.enfileira(movL(u).at(i));
                }
            }
        }
    }
    return graph;
}

//retorna a distancia e os passos do cavaleiro ate chegar ao rei
vector<int> caminho(int rei, int cavaleiro)
{
    Graph g = geraCaminhos(cavaleiro);
    vector<VertexBFS> grafoBFS;
    grafoBFS = bfs(g,rei);
    vector<int> cam;
    cam.push_back(grafoBFS[cavaleiro].getD());
    int posca = cavaleiro;
    cam.push_back(cavaleiro);
    for(int i = 0; i<grafoBFS[cavaleiro].getD();i++){
        for(int j = 0; j < g.getAdj()[posca].size();j++){
            if(grafoBFS[g.getAdj()[posca].at(j)->item].getD()<grafoBFS[posca].getD()){
                posca = g.getAdj()[posca].at(j)->item;
                cam.push_back(posca);
            }
        }
    }
    return cam;
}

//Procedimentos de entrada e saida =========================================================
int processaPosicaoEntrada(string s)
{
  int aux = 8*(s[0] - 'a');

  int aux2 = s[1] - '0';

  int res = aux+aux2;

  return res;
}

void posicoesEntrada(string s, int *posicoes)
{
  string aux = "";
  int j = 0;

  for(unsigned int i = 0; i <= s.length(); i++){
    if(s[i] == ' ' || (unsigned) i == s.length()){
      posicoes[j] = processaPosicaoEntrada(aux);
      aux = "";
      j++;
    }
    else{
      aux += s[i];
    }
  }
}


//Execucao ======================================================================================
int main(){

    int rep;

    cin >> rep;
    cin.ignore();
    for (int i = 0; i < rep; i++){

        std::string s;
        vector<int> menores(4);
        int *x = new int[5];

        getline(cin,s);

        posicoesEntrada(s,x);

        int menor = 99;
        //Exemplo do cavaleiro na casa 1 e o rei na casa 2
        for(int j = 0; j < 4; j++){

            vector<int> c;
            c = caminho(x[4],x[j]);

            if(--c[0] < menor){
                menor = c[0];
                menores.clear();
                menores.push_back(menor);
            }
            else if (c[0] == menor){
                menores.push_back(menor);
            }

        }

        for(unsigned int i = 0; i < menores.size(); i++)
            cout << menores[i] << " ";
        cout << endl;
        delete x;
    }
    return 0;
}
