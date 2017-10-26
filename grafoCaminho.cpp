#include "BFS.cpp"
#include <vector>
#include "entradaSaida.cpp"

using namespace std;

//Retorna se � possivel fazer a jogada em "L"
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
    if(!inRange(x,y))
        cout << "posicao invalida, erro na posicao do tabuleiro." ;

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
    int visited[65];
    for(int i=1;i<=64;i++){
        visited[i]=0;
    }
    Graph graph(64);
    Fila<int> q;
    q.enfileira(posInicial);
    while(!q.vazia()){
        int u = q.desenfileira();
        for(int i = 0; i < movL(u).size();i++){
            if(visited[movL(u).at(i)]<movL(movL(u).at(i)).size()){
                int cont = 0;
                for(int k=0;k<graph.getAdj()[u].size();k++){
                    if(movL(u).at(i)==graph.getAdj()[u].at(k))
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
            if(grafoBFS[g.getAdj()[posca].at(j)].getD()<grafoBFS[posca].getD()){
                posca = g.getAdj()[posca].at(j);
                cam.push_back(posca);
            }
        }
    }
    return cam;
}

int main(){

    std::string s;
    int *x = new int[5];

    getline(cin,s);

    posicoesEntrada(s,x);

    //Exemplo do cavaleiro na casa 1 e o rei na casa 2
    for(int j = 0; j < 4; j++){

      vector<int> c;
      c = caminho(x[4],x[j]);

      string s = posicaoSaida(c);

      cout <<--c[0] << " "<< s << endl;

      /*cout << "caminho "<<x[j]<<" :";

      for(int i = 0; i< c.size() -1; i++){
          cout << c[i] << " ";
      }
      cout << endl;*/
    }
    return 0;
}
