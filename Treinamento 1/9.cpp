#include <iostream>
using namespace std;

#define MAXTAM 1000

void addElement(int element, int *vector, int &tamanho, int &maior, int &menor){
  
  if(tamanho == 0){
    maior = menor = vector[0] = element;
    tamanho++;
  } else if(element > maior){
    
    //Criar um vetor auxiliar
    int aux[tamanho];

    //Preencher o vetor auxiliar com os elementos do vetor principal
    for(int i = 0; i < tamanho; i++){
      aux[i] = vector[i];
    }

    //Colocar o elemento na primeira posição do vetor principal
    vector[0] = element;

    //Aumentar o tamanho do vetor
    tamanho++;

    //Colocar o resto dos valores
    for(int i = 1; i < tamanho; i++){
      vector[i] = aux[i - 1];
    } 

    //Declarar que o maior elemento do vetor é o ultimo elemento colocado
    maior = element;
  } else if(element < menor){
    vector[tamanho] = element;
    menor = element;
    tamanho++;
  } else {

    //Acha qual posição o novo elemento tem que ficar
    int posi = 0;

    for(int i = 0; i < tamanho; i++){
      if(element > vector[i]){
        posi = i;
        i = tamanho + 1;
      }
    }

    //Cria um vetor auxiliar para armazenar tudo o que tem antes da posição
    int aux1[posi+1];
    for(int i = 0; i < posi; i++){
      aux1[i] = vector[i];
    }

    aux1[posi] = element;

    //Copia o vetor principal

    int aux2[tamanho];

    for(int i = 0; i < tamanho; i++){
      aux2[i] = vector[i];
    }

    //Junta os dois vetores
    
    for(int i = 0; i < tamanho + 1; i++){
      if(i <= posi){
        vector[i] = aux1[i];
      } else {
        vector[i] = aux2[i - 1];
      }
    }

    tamanho++;
  }

}

int main(){
  int maior, menor, tamanho = 0;

  int arr[MAXTAM];
  
  for(int i = 0; i < 100; i++)

  return 0;
}
