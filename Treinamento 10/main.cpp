#include <iostream>
#define infitino 100000
using namespace std;

//implemente o algoritmo de floyd-warshall para uma matriz 6x6 e salve o resultado na matriz resultado
void floyd_warshall(int matriz[6][6]){
    for(int k = 0; k < 6; k++){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(matriz[i][j] > matriz[i][k] + matriz[k][j]){
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(matriz[i][j] == infitino){
              cout<<"∞"<<" ";
            }else{
              cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }
}


int main(){
  int matriz[6][6] = {
    {0, 1, infitino, infitino, infitino, infitino},
    {infitino, 0, 1, 3, 2, infitino},
    {3, infitino, 0, 2, infitino, infitino},
    {infitino, infitino, infitino, 0, infitino, 2},
    {infitino, infitino, infitino, 3, 0, infitino},
    {infitino, infitino, infitino, infitino, 3, 0},
  };

  floyd_warshall(matriz);

    return 0;
}
