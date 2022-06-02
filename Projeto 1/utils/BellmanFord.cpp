#include <iostream>
#include <string>
#include "./Node.cpp"
#include <map>
using namespace std;

/*
 *
 * Essa classe é a responsável por fazer a busca do menor caminho possível do ponto In da linha de 
 * produção até o ponto Fn da linha de produção.
 * 
 * O algorítmo de BellmanFord é frequentemente usado para achar caminhos mais curtos sem, necessa-
 * riamente passar pela menor quantidade de nós, entretanto, como a topologia do grafo impede que
 * existam caminhos que a peça saia do ponto A para o ponto C, esse método de resolução do proble-
 * ma é bastante eficiente
 *
 */

class BellmanFord{

  /*
   *
   *
   * As propriedades dessa classe seguem:
   *  - linhaDeProducao: é o grafo apresentado na descrição do projeto, com todos os pontos e todas
   *    as suas ligações.
   *  - resultado: é o vetor que guardará os caminhos tomados pelo algorítmo que asseguram o menor 
   *    tempo. Por exemplo: resultado[0] = "A -> B'", etc.
   *  - tamanho: essa variavel foi criada para que o código pudesse ser reaproveitado para todos os
   *    tipos de grafos e mede a quantidade de nós no grafo.
   *  - tabelaDeDistancias: é uma tabela hash que armazena os menores caminhos descobertos de In até
   *    o nó atual.
   *
   */
  private:
    Node** linhaDeProducao;
    string resultado[100];
    int tamanho = 0;
    map<string, int> tabelaDeDistancias;

  public:
    BellmanFord(Node** linhaDeProducao, map<string, int> tabela, int tamanhoDaLinha){
      this->linhaDeProducao = linhaDeProducao;
      this->tabelaDeDistancias = tabela;
      this->tamanho = tamanhoDaLinha;
    }

    void makeTabelaDeDistancias(){
      /*
       *
       * Este método visita todos os nós e checa se o caminho até ali é menor que o caminho
       * salvo a tabela de distancias. Se for, o caminho descoberto toma o lugar do caminho
       * armazenado na tabela, se não, o caminho da tabela permanece inalterado.
       *
       */
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
      /*
       *
       *
       * Esse método pega as distâncias descobertas pelo método anterior e armazenadas
       * na tabela de distancias e checa todos os caminhos possível recursivamente até
       * o próximo nó, dessa forma, o caminho que condizer com a menor distância da ta-
       * bela de distancias é o escolhido para fazer parte do caminho total e armazena-
       * do em resultado[]
       * 
       *
       */
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
