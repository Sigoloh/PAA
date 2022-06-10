#include <iostream>
using namespace std;
#define NOS 6

void achaCaminhos(int mat[][NOS], int inicio, int fim, int tamanho){
  int res[NOS][NOS];
  if(tamanho > 1){
    for(int m = 0; m < tamanho; m++){
      for (int i = 0; i < NOS; i++) {
        for (int j = 0; j < NOS; j++) {
          res[i][j] = 0;
          for (int k = 0; k < NOS; k++){
            res[i][j] += mat[i][k] * mat[k][j];
          }
        }
      }     
    }
  }
  cout<<"Existem "<<res[inicio][fim]<<" caminhos de tamanho "<<tamanho<<" de ("<<inicio<<") até ("<<fim<<")"<<endl;
}

int main(){
  int matriz[NOS][NOS] = {
    {0, 0, 0, 0, 0, 1}, 
    {0, 0, 0, 0, 0, 1}, 
    {0, 0, 0, 1, 0, 1}, 
    {0, 0, 1, 0, 1, 1}, 
    {0, 0, 0, 1, 0, 1}, 
    {1, 1, 1, 1, 1, 0},    
  };

  //Tamanho do caminho que o usuario quer achar
  int n;

  int inicio, fim;

  cout<<"Entre com n: ";
  cin>>n;
  cout<<"Entre com o ponto inicial: ";
  cin>>inicio;
  cout<<"Entre com o ponto final: ";
  cin>>fim;

  achaCaminhos(matriz, inicio, fim, n);

  return 0;
}
