#include <iostream>
#include "./no.cpp"
using namespace std;

int tempo = 0;
void dfsVisita(No** grafo, No* vertice){
  tempo++;
  vertice->d = tempo;
  vertice->cor = "cinza";
  for(int i = 0; i < vertice->qtdAdj; i++){
    if(vertice->getAdj(i)->cor == "branco"){
      vertice->getAdj(i)->pai = vertice;
      dfsVisita(grafo, vertice->getAdj(i));
    }
  }
  vertice->cor = "preto";
  tempo++;
  vertice->f = tempo;
}

void dfs(No** grafo){
  for(int i = 0; i < 9; i++){
    if(grafo[i]->cor == "branco"){
      dfsVisita(grafo, grafo[i]);
    }
  }
}
