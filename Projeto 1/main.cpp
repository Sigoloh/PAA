#include <iostream>
#include <string>
#include <map>
#define INFINITO 2147483647
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

void checaLinha(Node** linhaDeProducao, int tamanho){
  for(int i = 0; i < tamanho; i++){
      cout<<"É possivel chegar à "<<linhaDeProducao[i]->getNome()<<" pelos caminhos: "<<endl;
      for(int k = 0; k < linhaDeProducao[i]->getQuantidadeDePontosDePartida(); k++){
          cout<<linhaDeProducao[i]->getPontoDePartida(k)->getVemDe()<<" - "<<linhaDeProducao[i]->getNome()<<endl;
      }
  }
}

void calculaCaminho(Node* chegada, string* resultado, map<string, int>tabela, int count = 0){
  for(int i = 0; i < chegada->getQuantidadeDePontosDePartida(); i++){
    if(tabela[chegada->getNome()] - tabela[chegada->getPontoDePartida(i)->getVemDe()] == chegada->getPontoDePartida(i)->getDistancia()){
      resultado[count] = chegada->getPontoDePartida(i)->getVemDe() + " -> " + chegada->getNome();
      calculaCaminho(chegada->getPontoDePartida(i)->getNode(), resultado, tabela, count + 1);
    }
  }
}

int main(){
  int tamanho = 9;
//
// Cria os nos
//

  //Nó inicial
  Node *In = new Node("In");

  Node *A = new Node("A");

  Node *B = new Node("B");

  Node *C = new Node("C");

  Node *Bl = new Node("B'");

  Node *All = new Node("A''");

  Node *Bll = new Node("B''");

  Node *Cll = new Node("C''");

  //Nó final
  Node *Fn = new Node("Fn");

//
// Cria as conexões
//

  In->addConection(A, 3);

  In->addConection(All, 8);

  A->addConection(B, 9);

  A->addConection(Bl, 8);

  All->addConection(Bl, 9);

  All->addConection(Bll, 8);

  B->addConection(C, 6);

  Bl->addConection(C, 6);

  Bl->addConection(Cll, 2);

  Bll->addConection(Cll, 6);

  C->addConection(Fn, 9);

  Cll->addConection(Fn, 5);

//
// Preenchendo o vetor da linha de produção
//

  Node* linhaDeProducao[9] = {In, A, All, B, Bl, Bll, C, Cll, Fn};

//
// Verifica se a árvore está preenchida corretamente
//
  
//  checaLinha(linhaDeProducao, tamanho);

// Cria o vetor de distâncias mínimas com tudo setado para infinito,
// bem como um vetor de "Dicionario para as posições"

  map<string, int> tabelaDeDistancias {
    {"In", 0},
    {"A", INFINITO},
    {"B", INFINITO},
    {"C", INFINITO},
    {"B'", INFINITO},
    {"A''", INFINITO},
    {"B''", INFINITO},
    {"C''", INFINITO},
    {"Fn", INFINITO},
  };

  string dicionario[9] = {"In", "A", "A''", "B", "B'", "B''", "C", "C''"};

//
// Faz o calculo da menor distância para todos os nós
//

  for(int i = 0; i < tamanho; i++){
    for(int k = 0; k < linhaDeProducao[i]->getQuantidadeDeLigacoes(); k++){
      Node* nodoVisitado = linhaDeProducao[i];
      if(i == 0){
        tabelaDeDistancias["A"] = nodoVisitado->getConection(0)->getDistancia();
        tabelaDeDistancias["A''"] = nodoVisitado->getConection(1)->getDistancia();
      }else{
        if(tabelaDeDistancias[nodoVisitado->getNome()] + nodoVisitado->getConection(k)->getDistancia() < tabelaDeDistancias[nodoVisitado->getConection(k)->getNameOfDestiny()]){
          tabelaDeDistancias[nodoVisitado->getConection(k)->getNameOfDestiny()] = 
            tabelaDeDistancias[nodoVisitado->getNome()] + nodoVisitado->getConection(k)->getDistancia();
        }
      }
    }
  }

//
// Imprime a tabela de distancia final
//

  for(auto it = tabelaDeDistancias.begin(); it != tabelaDeDistancias.end(); it++){
      cout<<it->first<<" : "<<it->second<<endl;
  }

//
// Calcula o melhor caminho com base na tabela de distancias
//
  
  string resultado[10];
  calculaCaminho(linhaDeProducao[8], resultado, tabelaDeDistancias);

  for(int i = 9; i >= 0; i--){
    cout<<resultado[i]<<endl;
  }
  return 0;
}
