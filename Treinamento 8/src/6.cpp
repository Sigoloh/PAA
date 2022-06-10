#include <iostream>
using namespace std;


//Algorítmo Deep First Search para checar todos os nós adjacentes ao nó pos
void DFS(int pos, int vis[], int matriz[][7]){
  vis[pos] = 1;
  for(int i = 0; i < 7; i++){
    if(matriz[pos][i] == 1){
      if(vis[i] == 0){
        DFS(i, vis, matriz);
      }     
    }
  }
}

int main(){
  int vis[7] = {0, 0, 0, 0, 0, 0, 0};
  int count = 0;
  int matriz[7][7] = {
    {0, 0, 1, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0}, 
    {1, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 1, 0, 0}, 
    {0, 0, 0, 1, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 1}, 
    {0, 0, 0, 1, 0, 1, 0} 
  };
  
  //Para cada nó do grafo, um DFS é chamado recursivamente até que não haja mais conexões
  for(int i = 0; i < 7; i++){
    if(vis[i] == 0){
      count++;
      DFS(i, vis, matriz);
    }
  }

  cout<<"O número de componentes conexos é: "<<count<<endl;
  return 0;
}
