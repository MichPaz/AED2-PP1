#include "BFS.cpp"
#include <vector>

using namespace std;

bool inRange(int i, int j)
{
    return ( (i>=0) &&(i<8) && (j >=0) && (j<8) );
}

vector<int> movCavaleiro(int p)
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
        cout << "posicao invalida" ;

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

    for(int i=0;i<8;i++){
        cout << "\n";
        for(int j=0;j<8;j++){
                cout << "   " << tabuleiro[i][j] << "   ";
        }
    }
    cout << "\n\n";
    for(int i=0;i<pos.size();i++){
        cout << pos.at(i) <<endl;
    }

    return pos;

}

/*Graph geraCaminhosCavaleiro(int posCav){

}*/

int main(){
    movCavaleiro(59);
    return 0;
}
