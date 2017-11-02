#include <iostream>

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

