#include <iostream>
#include <string>

using namespace std;

int processaPosicao(string s)
{
  int aux = 8*(s[0] - 'a');

  int aux2 = s[1] - '0';

  int res = aux+aux2;
  cout << res << endl;
  return res;
}

void posicoes(string s, int *posicoes)
{
  string aux = "";
  int j = 0;

  for(int i = 0; i <= s.length(); i++){
    if(s[i] == ' ' || i == s.length()){
      posicoes[j] = processaPosicao(aux);
      aux = "";
      j++;
    }
    else{
      aux += s[i];
    }
  }
}
int main()
{
  std::string s;
  int *x = new int[4];

  getline(cin,s);

  posicoes(s,x);

  for (int i = 0; i < 4; i++)
    cout << x[i] << " ";

  cout << endl;

  return 0;
}
