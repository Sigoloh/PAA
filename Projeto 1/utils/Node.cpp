#include <iostream>
#include <string>
using namespace std;

class Node{
  class Ligacao{
      private:
        Node* vaiPara;
        int distancia;
        string vemDe;

      public:
        Ligacao(Node* node = nullptr, int dis = -1, string vemDe = ""){
          this->distancia = dis;
          this->vaiPara = node;
          this->vemDe = vemDe;
        }

        string getNameOfDestiny(){
          return this->vaiPara->getNome();
        }

        Node* getNode(){
          return this->vaiPara;
        }

        string getVemDe(){
          return this->vemDe;
        }

        int getDistancia(){
          return this->distancia;
        }
  };

  private:
    int qtdLigacoes = 0;
    int qtdPontosDePartida = 0;
    Ligacao ligacoes[100];  
    Ligacao pontosDePartida[100];
    string nome;

  public:

      Node(string name = "."){
      this->nome = name;
    }

    void setNome(string nome){
      this->nome = nome;
    }

    string getNome(){
      return this->nome;
    }

    void addPontoDePartida(Ligacao* lig){
      this->pontosDePartida[qtdPontosDePartida] = *lig;
      this->qtdPontosDePartida++;
    } 

    Ligacao* getPontoDePartida(int position){
      return &this->pontosDePartida[position];
    }

    void addConection(Node* node, int distancia){
      Ligacao *novaLigacao = new Ligacao(node, distancia);

      this->ligacoes[qtdLigacoes] = *novaLigacao;

      Ligacao *pontoDePartida = new Ligacao(this, distancia, this->nome);
      
      node->addPontoDePartida(pontoDePartida);

      this->qtdLigacoes++;
    }

    Ligacao* getConection(int position){
      if(position >= this->qtdLigacoes){
          cout<<"Posição não existe"<<endl;
          return nullptr;
      }
      return &this->ligacoes[position];
    }

    int getQuantidadeDeLigacoes(){
      return this->qtdLigacoes;
    }

    int getQuantidadeDePontosDePartida(){
      return this->qtdPontosDePartida;
    }

};
