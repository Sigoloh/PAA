#include <iostream>
#include "./no.cpp"
using namespace std;

class Lista{
  private:
    No* ini = nullptr;
    No* fim = nullptr;
  public:

    int tam = 0;

    void insert(No* node){
      if(tam == 0){
        this->ini = this->fim = node;
        this->ini->next = node;
        tam++;
      }else{
        No* aux;
        aux = this->fim;
        this->fim = node;
        aux->next = node;
        tam++;
      }
    }

    void showList(){
      No* aux;
      aux=this->ini;
      while(aux != nullptr){
        cout<<aux->nome<<endl;
        aux=aux->next;
      }
    }

    No* getMember(int index){
      if(index >= tam){
        cout<<"Posição não existe na lista"<<endl;
        return nullptr;
      }
      No* aux = this->ini;
      
      for(int i = 0; i < index; i++){
        aux=aux->next;
      }

      return aux;
    }
};
