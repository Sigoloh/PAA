#include <iostream>
#include <string>
#include <map>
#include "./utils/BellmanFord.cpp"
#define INFINITO 2147483647
using namespace std;
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

  string caminho[54] = {
    "In -> A",
    "In -> A'",
    "A -> B",
    "A -> B'",
    "B -> C",
    "B -> C'",
    "C -> D",
    "C -> D'",
    "D -> E",
    "D -> E'",
    "E -> F",
    "E -> F'",
    "F -> G",
    "F -> G'",
    "G -> H",
    "G -> H'",
    "H -> I",
    "I -> Fn",
    "A'' -> B''",
    "A'' -> B'",
    "B'' -> C''",
    "B'' -> C'",
    "C'' -> D''",
    "C'' -> D'",
    "D'' -> E''",
    "D'' -> E'",
    "E'' -> F''",
    "E'' -> F'",
    "F'' -> G''",
    "F'' -> G'",
    "G'' -> H''",
    "G'' -> H'",
    "H'' -> I''",
    "I'' -> Fn",
    "B' -> C",
    "B' -> C'",
    "B' -> C''",
    "C' -> D",
    "C' -> D'",
    "C' -> D''",
    "D' -> E",
    "D' -> E'",
    "D' -> E''",
    "E' -> F",
    "E' -> F'",
    "E' -> F''",
    "F' -> G",
    "F' -> G'",
    "F' -> G''",
    "G' -> H",
    "G' -> H'",
    "G' -> H''",
    "H' -> I",
    "H' -> I''"
  };

  int pesos[54];
  
  for(int i = 0; i < 54; i++){
    cout<<caminho[i]<<endl;
    cin>>pesos[i];
  }
  // Nó inicial
    
    In->addConection(A, pesos[0]);

    In->addConection(All, pesos[1]);

  // A
    
    A->addConection(B, pesos[2]);

    A->addConection(Bl, pesos[3]);

  // B
    
    B->addConection(C, pesos[4]);

    B->addConection(Cl, pesos[5]);

  // C
    
    C->addConection(D, pesos[6]);

    C->addConection(Dl, pesos[7]);

  // D

    D->addConection(E, pesos[8]);

    D->addConection(El, pesos[9]);

  // E
    
    E->addConection(F, pesos[10]);

    E->addConection(Fl, pesos[11]);

  // F
    
    F->addConection(G, pesos[12]);

    F->addConection(Gl, pesos[13]);

  // G

    G->addConection(H, pesos[14]);

    G->addConection(Hl, pesos[15]);

  // H

    H->addConection(I, pesos[16]);

  // I

    I->addConection(Fn, pesos[17]);
  // A''
    
    All->addConection(Bll, pesos[18]);

    All->addConection(Bl, pesos[19]);

  // B''
    
    Bll->addConection(Cll, pesos[20]);

    Bll->addConection(Cl, pesos[21]);

  // C''
    
    Cll->addConection(Dll, pesos[22]);

    Cll->addConection(Dl, pesos[23]);

  // D''

    Dll->addConection(Ell, pesos[24]);

    Dll->addConection(El, pesos[25]);

  // E''
    
    Ell->addConection(Fll, pesos[26]);

    Ell->addConection(Fl, pesos[27]);

  // F''
    
    Fll->addConection(Gll, pesos[28]);

    Fll->addConection(Gl, pesos[29]);

  // G''

    Gll->addConection(Hll, pesos[30]);

    Gll->addConection(Hl, pesos[31]);

  // H''

    Hll->addConection(Ill, pesos[32]);

  // I''

    Ill->addConection(Fn, pesos[33]);

  // B'

    Bl->addConection(C, pesos[34]);

    Bl->addConection(Cl, pesos[35]);

    Bl->addConection(Cll, pesos[36]);

  // C'
    Cl->addConection(D, pesos[37]);

    Cl->addConection(Dl, pesos[38]);

    Cl->addConection(Dll, pesos[39]);

  // D'
    Dl->addConection(E, pesos[40]);

    Dl->addConection(El, pesos[41]);

    Dl->addConection(Ell, pesos[42]);

  // E'
    El->addConection(F, pesos[43]);

    El->addConection(Fl, pesos[44]);

    El->addConection(Fll, pesos[45]);

  // F'
    Fl->addConection(G, pesos[46]);

    Fl->addConection(Gl, pesos[47]);

    Fl->addConection(Gll, pesos[48]);

  // G'
    Gl->addConection(H, pesos[49]);

    Gl->addConection(Hl, pesos[50]);

    Gl->addConection(Hll, pesos[51]);

  // H'
    Hl->addConection(I, pesos[52]);

    Hl->addConection(Ill, pesos[53]);

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

  for(int i = 0; i < 26; i++){
    for(int k = 0; k < linhaDeProducao[i]->getQuantidadeDeLigacoes(); k++){
      cout<<linhaDeProducao[i]->getNome()<<" -> "<<linhaDeProducao[i]->getConection(k)->getNameOfDestiny()<<" = "<<linhaDeProducao[i]->getConection(k)->getDistancia()<<endl;
    }
  };
// Faz o calculo da menor distância para todos os nós for(int i = 0; i < tamanho; i++){ for(int k = 0; k < linhaDeProducao[i]->getQuantidadeDeLigacoes(); k++){ Node* nodoVisitado = linhaDeProducao[i]; if(i == 0){ tabelaDeDistancias["A"] = nodoVisitado->getConection(0)->getDistancia(); tabelaDeDistancias["A''"] = nodoVisitado->getConection(1)->getDistancia(); }else{ if(tabelaDeDistancias[nodoVisitado->getNome()] + nodoVisitado->getConection(k)->getDistancia() < tabelaDeDistancias[nodoVisitado->getConection(k)->getNameOfDestiny()]){ tabelaDeDistancias[nodoVisitado->getConection(k)->getNameOfDestiny()] = tabelaDeDistancias[nodoVisitado->getNome()] + nodoVisitado->getConection(k)->getDistancia(); } } } }
//
// Imprime a tabela de distancia final
//

//  for(auto it = tabelaDeDistancias.begin(); it != tabelaDeDistancias.end(); it++){
//      cout<<it->first<<" : "<<it->second<<endl;
//  }

  BellmanFord* bellmanFord = new BellmanFord(linhaDeProducao, tabelaDeDistancias, 27);

  bellmanFord->showFastestPath();
  return 0;
}
