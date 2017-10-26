#include <limits>
#include "fila.cpp"
#include "grafoListaAd.cpp"


//Classe de vertice para BFS---------------------------------------------------------------------
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
            if(u[graph.getAdj()[j].at(i)].getCor()==0){

                u[graph.getAdj()[j].at(i)].setCor(1);
                u[graph.getAdj()[j].at(i)].setD(u[j].getD()+1);
                u[graph.getAdj()[j].at(i)].setP(j);

                gr.insertEdge(j,graph.getAdj()[j].at(i));
                q.enfileira(graph.getAdj()[j].at(i));
            }
        u[j].setCor(2);
        }
    }
    graph = gr;
    return u;
}
