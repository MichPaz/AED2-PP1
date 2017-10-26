#include <iostream>
#include <string>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

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

  for(int i = 0; i <= s.length(); i++){
    if(s[i] == ' ' || i == s.length()){
      posicoes[j] = processaPosicaoEntrada(aux);
      aux = "";
      j++;
    }
    else{
      aux += s[i];
    }
  }
}

string processaPosicaoSaida(int n)
{
  string s;
  int aux = -1;

  while(n>0){
    n -= 8;
    aux++;
  }

  n+=8;

  aux = aux + 'a';
  char c = aux;

  s = c + to_string(n);
  return s;
}

string posicaoSaida(vector<int> v)
{
  string s = "";

  for (int i = 1; i < v.size()-1; i++)
    s += processaPosicaoSaida(v[i]) + " ";
  return s;
}
