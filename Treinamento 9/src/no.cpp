#include <iostream>
#include <string>
using namespace std;

class No{
  private:
    No* prec[100];
    No* adj[100];
  public:

    string cor = "branco";

    string nome;

    No* next = nullptr;

    No* pai = nullptr;

    int d = 0;

    int f = 0;

    int qtdPrec = 0;

    int qtdAdj = 0;
    No(string nome){
      this->nome = nome;
    }

    void addPrec(No* prec){
      this->prec[qtdPrec] = prec;
      this->qtdPrec++;
    }

    void addAdj(No* adj){
      this->adj[qtdAdj] = adj;
      adj->addPrec(this);
      this->qtdAdj++;
    }

    No* getAdj(int index){
      return this->adj[index];
    }
};
