#include <iostream>
#include <map>
#include "./dfs.cpp"
#define TAMANHO 9
using namespace std;

void bubbleSort(No* arr[], int n){
  int i, j;
  No* temp;

  for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(arr[j]->f < arr[j+1]->f)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
  
  // Resolvemos usar nós para representar o grafo pois assim
  // seria mais fácil ordená-los em uma lista sequencial no
  // futuro

  No *cueca = new No("cueca");

  No *calca = new No("calca");

  No *meia = new No("meia");

  No *sapatos = new No("sapatos");

  No *cinto = new No("cinto");

  No *camisa =  new No("camisa");

  No *gravata = new No("gravata");

  No *paleto = new No("paleto");

  No *relogio = new No("relogio");

  // Estabelecendo as relações de adjacência
  cueca->addAdj(calca);

  cueca->addAdj(sapatos);

  meia->addAdj(sapatos);

  calca->addAdj(sapatos);

  calca->addAdj(cinto);

  camisa->addAdj(cinto);

  camisa->addAdj(gravata);

  cinto->addAdj(paleto);

  gravata->addAdj(paleto);

  //Como optamos por usar nós ao invés de uma matriz
  //de adjacência, usamos o vetor grafo para armazenar
  //o grafo

  No* grafo[TAMANHO] = {camisa, cueca, meia, relogio};

  dfs(grafo);
  
  No* vec[9];
  for(int i = 0; i < TAMANHO; i++){
    cout<<grafo[i]->nome<<": "<<grafo[i]->f<<endl;
    vec[i] = grafo[i];
  }

  cout<<endl;
  bubbleSort(grafo, TAMANHO);

  for(int i = 0; i < TAMANHO; i++){
    cout<<grafo[i]->nome<<": "<<grafo[i]->f<<" ";
  }
  cout<<endl;
  return 0;
}
