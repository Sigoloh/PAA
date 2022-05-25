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

void calculaCaminho(Node* chegada, string* resultado, int &tamanhoCaminhoFinal, map<string, int>tabela, int count = 0){
  for(int i = 0; i < chegada->getQuantidadeDePontosDePartida(); i++){
    if(tabela[chegada->getNome()] - tabela[chegada->getPontoDePartida(i)->getVemDe()] == chegada->getPontoDePartida(i)->getDistancia()){
      resultado[count] = chegada->getPontoDePartida(i)->getVemDe() + " -> " + chegada->getNome();
      tamanhoCaminhoFinal++;
      calculaCaminho(chegada->getPontoDePartida(i)->getNode(), resultado, tamanhoCaminhoFinal, tabela, count + 1);
    }
  }
}

int main(){
  int tamanho = 27;
//
// Cria os nos
//

  //Nó inicial
  Node *In = new Node("In");

  Node *A = new Node("A");

  Node *B = new Node("B");
Node *C = new Node("C");
  Node *D = new Node("D");

  Node *E = new Node("E");

  Node *F = new Node("F");

  Node *G = new Node("G");

  Node *H = new Node("H");

  Node *I = new Node("I");
  
  Node *Bl = new Node("B'");

  Node *Cl = new Node("C'");

  Node *Dl = new Node("D'");

  Node *El = new Node("E'");

  Node *Fl = new Node("F'");

  Node *Gl = new Node("G'");
  
  Node *Hl = new Node("H'");

  Node *All = new Node("A''");

  Node *Bll = new Node("B''");

  Node *Cll = new Node("C''");

  Node *Dll = new Node("D''");

  Node *Ell = new Node("E''");

  Node *Fll = new Node("F''");

  Node *Gll = new Node("G''");

  Node *Hll = new Node("H''");

  Node *Ill = new Node("I''");

  //Nó final
  Node *Fn = new Node("Fn");

//
// Cria as conexões
//

  // Nó inicial
  
    In->addConection(A, 1);

    In->addConection(All, 5);

  // A
    
    A->addConection(B, 7);

    A->addConection(Bl, 12);

  // B
    
    B->addConection(C, 9);

    B->addConection(Cl, 6);

  // C
    
    C->addConection(D, 4);

    C->addConection(Dl, 2);

  // D

    D->addConection(E, 9);

    D->addConection(El, 2);

  // E
    
    E->addConection(F, 5);

    E->addConection(Fl, 4);

  // F
    
    F->addConection(G, 1);

    F->addConection(Gl, 8);

  // G

    G->addConection(H, 4);

    G->addConection(Hl, 2);

  // H

    H->addConection(I, 1);

  // I

    I->addConection(Fn, 11);
  // A''
    
    All->addConection(Bll, 7);

    All->addConection(Bl, 12);

  // B''
    
    Bll->addConection(Cll, 9);

    Bll->addConection(Cl, 6);

  // C''
    
    Cll->addConection(Dll, 4);

    Cll->addConection(Dl, 2);

  // D''

    Dll->addConection(Ell, 9);

    Dll->addConection(El, 2);

  // E''
    
    Ell->addConection(Fll, 5);

    Ell->addConection(Fl, 4);

  // F''
    
    Fll->addConection(Gll, 1);

    Fll->addConection(Gl, 8);

  // G''

    Gll->addConection(Hll, 4);

    Gll->addConection(Hl, 2);

  // H''

    Hll->addConection(Ill, 1);

  // I''

    Ill->addConection(Fn, 11);

  // B'

    Bl->addConection(C, 1);

    Bl->addConection(Cl, 5);

    Bl->addConection(Cll, 3);

  // C'
    Cl->addConection(D, 1);

    Cl->addConection(Dl, 5);

    Cl->addConection(Dll, 3);

  // D'
    Dl->addConection(E, 1);

    Dl->addConection(El, 5);

    Dl->addConection(Ell, 3);

  // E'
    El->addConection(F, 1);

    El->addConection(Fl, 5);

    El->addConection(Fll, 3);

  // F'
    Fl->addConection(G, 1);

    Fl->addConection(Gl, 5);

    Fl->addConection(Gll, 3);

  // G'
    Gl->addConection(H, 1);

    Gl->addConection(Hl, 5);

    Gl->addConection(Hll, 3);

  // H'
    Gl->addConection(I, 1);

    Gl->addConection(Ill, 3);

//
// Preenchendo o vetor da linha de produção
//

  Node* linhaDeProducao[27] = {
    In, A, All,
    B, Bl, Bll,
    C, Cl, Cll,
    D, Dl, Dll,
    E, El, Ell,
    F, Fl, Fll,
    G, Gl, Gll,
    H, Hl, Hll,
    I, Ill, Fn,
  };

//
// Verifica se a árvore está preenchida corretamente
//
  
//  checaLinha(linhaDeProducao, tamanho);

// Cria o vetor de distâncias mínimas com tudo setado para infinito,

  map<string, int> tabelaDeDistancias {
    {"In", 0},
    {"A", INFINITO},
    {"B", INFINITO},
    {"C", INFINITO},
    {"D", INFINITO},
    {"E", INFINITO},
    {"F", INFINITO},
    {"G", INFINITO},
    {"H", INFINITO},
    {"I", INFINITO},
    {"B'", INFINITO},
    {"C'", INFINITO},
    {"D'", INFINITO},
    {"E'", INFINITO},
    {"F'", INFINITO},
    {"G'", INFINITO},
    {"H'", INFINITO},
    {"A''", INFINITO},
    {"B''", INFINITO},
    {"C''", INFINITO},
    {"D''", INFINITO},
    {"E''", INFINITO},
    {"F''", INFINITO},
    {"G''", INFINITO},
    {"H''", INFINITO},
    {"I''", INFINITO},
    {"Fn", INFINITO},
  };

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

//  for(auto it = tabelaDeDistancias.begin(); it != tabelaDeDistancias.end(); it++){
//      cout<<it->first<<" : "<<it->second<<endl;
//  }

//
// Calcula o melhor caminho com base na tabela de distancias
//
  
  string resultado[20];
  int tamanhoCaminhoFinal = 0;
  calculaCaminho(linhaDeProducao[26], resultado, tamanhoCaminhoFinal, tabelaDeDistancias);

  for(int i = tamanhoCaminhoFinal; i >= 0; i--){
    cout<<resultado[i]<<endl;
  }
  return 0;
}
