#include "BFS.cpp"
#include <vector>

using namespace std;

bool inRange(int i, int j)
{
    return ( (i>=0) &&(i<8) && (j >=0) && (j<8) );
}

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

    /*for(int i=0;i<8;i++){
        cout << "\n";
        for(int j=0;j<8;j++){
                cout << "   " << tabuleiro[i][j] << "   ";
        }
    }*/
    /*cout << "\n\n";
    for(int i=0;i<pos.size();i++){
        cout << pos.at(i) <<endl;
    }*/

    return pos;

}

Graph geraCaminhos(int posInicial){
    int visited[65];
    for(int i=1;i<=64;i++){
        visited[i]=0;
    }
    //visited[posInicial]=true;
    Graph graph(64);
    Fila<int> q;
    q.enfileira(posInicial);
    while(!q.vazia()){
        int u = q.desenfileira();
        for(int i = 0; i < movL(u).size();i++){
            if(visited[movL(u).at(i)]<movL(movL(u).at(i)).size()){
                graph.insertEdge(u, movL(u).at(i));
                visited[movL(u).at(i)]++;
                cout<<"enfileira " << movL(u).at(i)<<endl;
                q.enfileira(movL(u).at(i));
            }
        }
    }
    graph.print();
    return graph;
}

int main(){
    geraCaminhos(1);
    return 0;
}
