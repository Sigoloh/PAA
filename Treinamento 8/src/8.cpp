#include <iostream>
using namespace std;
#define NOS 4

int main(){
  int ePar[NOS];

  for(int i = 0; i < NOS; i++){
    ePar[i] = 0;
  }

  int matriz[NOS][NOS] = {
      {0, 1, 1, 1}, 
      {1, 0, 1, 1}, 
      {1, 1, 1, 1}, 
      {1, 1, 1, 0},    
  };

  int graus = 0;
  for(int i = 0; i < NOS; i++){
    for(int k = 0; k < NOS; k++){
      matriz[i][k] == 1 ? graus++ : graus = graus;
    }
    if(graus % 2 == 0){
      ePar[i] = 1;
    }
    graus = 0;
  }

  int soma = 0;
  for(int i = 0; i < NOS; i++){
    soma += ePar[i];
  }

  if(soma == NOS || soma == NOS - 2){
    cout<<"O grafo tem um caminho Euleriano"<<endl;
  } else {
    cout<<"O grafo não tem um caminho Euleriano"<<endl;
  }

  return 0;
}
