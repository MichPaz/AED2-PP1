#include <limits>
#include "fila.cpp"
#include "grafoListaAd.cpp"


//Classe para BFS---------------------------------------------------------------------
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


//BFS------------------------------------------------------------
VertexBFS* bfs(Graph &graph, int s)
{

    VertexBFS u[graph.getN()];
    Graph gr(graph.getN());

    for(int i = 0; i < graph.getN(); i++){
        u[i].setCor(0);
        u[i].setD(0);
        u[i].setP(-1);
    }

    u[s].setCor(1);
    u[s].setD(0);
    u[s].setP(-1);

    for(int i = 0; i<graph.getN(); i++){
        cout << "vertice[" << i+1 << "] cor - " << u[i].getCor() << ", d - " << u[i].getD() << ", p - " << u[i].getP() << endl;
    }

    Fila<int> q;
    q.enfileira(s);
    cout << "cor do 8 = " << u[8].getCor()<<endl;

    while(!q.vazia()){
        int j = q.desenfileira();
        cout<<"\nsaiu da fila o "<<j<<endl;
        //cout << "variacao do i = " << graph.getAdj()[j].size() << endl;
        for(int i = 0; i<graph.getAdj()[j].size(); i++){
            cout << "cor do 8 = " << u[8].getCor()<<endl;
            cout<<"\nolhando o vertice "<<graph.getAdj()[j].at(i) ;
            cout<<" "<< u[graph.getAdj()[j].at(i)].getCor() << "=" << 0;
            if(u[graph.getAdj()[j].at(i)].getCor()==0){
                cout<<"\nVisitando o vertice "<<graph.getAdj()[j].at(i) ;
                u[graph.getAdj()[j].at(i)].setCor(1);
                u[graph.getAdj()[j].at(i)].setD(u[j].getD()+1);
                u[graph.getAdj()[j].at(i)].setP(j);

                cout<<"\n inserindo vertice: "<<j<<","<<graph.getAdj()[j].at(i)<<endl;
                gr.insertEdge(j,graph.getAdj()[j].at(i));
                cout<<"\nenfileira "<< graph.getAdj()[j].at(i);
                q.enfileira(graph.getAdj()[j].at(i));
            }
        u[j].setCor(2);
        }
    }
    graph = gr;

    for(int i = 0; i<graph.getN(); i++){
        cout << "vertice[" << i+1 << "] cor - " << u[i].getCor() << ", d - " << u[i].getD() << ", p - " << u[i].getP() << endl;
    }

    return u;
}


int main()
{
    Graph g(8);
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
    cout << "Grafo" << endl;
    g.print();
    cout << "\n\nGrafo-BFS" << endl;
    bfs(g, 2);
    g.print();
    return 0;
}
