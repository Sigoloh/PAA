#include <iostream>
#include <string>
#include "./Node.cpp"
#include <map>
using namespace std;

class BellmanFord{
  private:
    Node** linhaDeProducao;
    string resultado[100];
    int tamanhoCaminhoFinal = 0;
    int tamanho = 0;
    map<string, int> tabelaDeDistancias;
  public:
    BellmanFord(Node** linhaDeProducao, map<string, int> tabela, int tamanhoDaLinha){
      this->linhaDeProducao = linhaDeProducao;
      this->tabelaDeDistancias = tabela;
      this->tamanho = tamanhoDaLinha;
    }

    void makeTabelaDeDistancias(){
      for(int i = 0; i < this->tamanho; i++){
        for(int k = 0; k < this->linhaDeProducao[i]->getQuantidadeDeLigacoes(); k++){
        Node* nodoVisitado = this->linhaDeProducao[i];
        if(i == 0){
          this->tabelaDeDistancias["A"] = nodoVisitado->getConection(0)->getDistancia();
          this->tabelaDeDistancias["A''"] = nodoVisitado->getConection(1)->getDistancia();
        }else{
          if(this->tabelaDeDistancias[nodoVisitado->getNome()] + nodoVisitado->getConection(k)->getDistancia() < this->tabelaDeDistancias[nodoVisitado->getConection(k)->getNameOfDestiny()]){
            this->tabelaDeDistancias[nodoVisitado->getConection(k)->getNameOfDestiny()] = 
            this->tabelaDeDistancias[nodoVisitado->getNome()] + nodoVisitado->getConection(k)->getDistancia();
          }
        }
        }
      }    
    }
    
    void makeFastestPath(Node* comeFrom, int count = 0){
      for(int i = 0; i < comeFrom->getQuantidadeDePontosDePartida(); i++){
        if(this->tabelaDeDistancias[comeFrom->getNome()] - this->tabelaDeDistancias[comeFrom->getPontoDePartida(i)->getVemDe()] == comeFrom->getPontoDePartida(i)->getDistancia()){
          this->resultado[count] = comeFrom->getPontoDePartida(i)->getVemDe() + " -> " + comeFrom->getNome(); 
          makeFastestPath(comeFrom->getPontoDePartida(i)->getNode(), count + 1);
        }
      }
    }

    void showFastestPath(){
      this->makeTabelaDeDistancias();
      this->makeFastestPath(this->linhaDeProducao[this->tamanho - 1]);
      for(int i = 100; i >= 0 ; i--){
        if(this->resultado[i] != ""){
          cout<<this->resultado[i]<<endl;
        }
      }
    }
};
