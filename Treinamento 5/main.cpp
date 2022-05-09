#include <iostream>
#include <string>
using namespace std;

class Node{
  private:
    int freq = 0;
    char letter = 0;
    Node* dir = nullptr;
    Node* esq = nullptr;
    Node* pai = nullptr;
  public:
    int getFreq(){
      return this->freq;
    }

    void setFreq(int f){
      this->freq = f;
    }

    char getLetter(){
      return this->letter;
    }

    void setLetter(char c){
      this->letter = c;
    }

    void setEsq(Node* element){
      this->esq = element;
    }

    Node* getEsq(){
      return this->esq;
    }

    void setDir(Node* element){
      this->dir = element;
    }

    Node* getDir(){
      return this->dir;
    }

    void setPai(Node* element){
      this->pai = element;
    }

    Node* getPai(){
      return this->pai;
    }

};

class Letter{
  private:
    char letter;
    string code;

  public:
    char getLetter(){
      return this->letter;
    }

    string getCode(){
      return this->code;
    }

    void setLetter(char l){
      this->letter = l;
    }

    void setCode(string c){
      this->code = c;
    }

};

class Huffman{
  private:
    Node nodes[1000];
    Letter table[1000];
    string frase;
    int maior, menor;
    int tam = 0;

  public:

    void setFrase(string f){
      this->frase = f;
    }

    string getFrase(){
      return this->frase;
    }

    void addNode(Node node){
      if(this->tam == 0){
        this->nodes[0] = node;
        maior = menor = node.getFreq();
        this->tam++;
      }else{
        this->nodes[tam] = node;
        this->tam++;
      }
    }

    void orderList(){
      Node aux;
      for(int i = 0; i < this->tam; i++){
        for(int j = 0; j < this->tam; j++){
          if(this->nodes[i].getFreq() < this->nodes[j].getFreq()){
            aux = this->nodes[i];
            this->nodes[i] = this->nodes[j];
            this->nodes[j] = aux;
          }
        }
      }
    }

    Node* getNode(int pos){
      return &this->nodes[pos];
    }

    void createTable(){
      for(int i = 0; i < this->frase.size(); i++){
        if(this->tam == 0){
          Node newNode;
          newNode.setLetter(frase[i]);
          newNode.setFreq(1);
          this->addNode(newNode);
        }else{
          bool exists = false;
          for(int k = 0; k < this->tam; k++){
            if(this->getNode(k)->getLetter() == this->frase[i]){
              this->getNode(k)->setFreq(this->getNode(k)->getFreq() + 1);
              exists = true;
              break;
            }
          }
          if(!exists){
            Node newNode;
            newNode.setLetter(this->frase[i]);
            newNode.setFreq(1);
            this->addNode(newNode);
          }
        }
      }
    }

    void printTable(){
      cout<<"Tamanho: "<<this->tam<<endl;
      for(int i = 0; i < this->tam; i++){
        cout<<"Letra: "<<this->getNode(i)->getLetter()<<endl;
        cout<<"Frequência: "<<this->getNode(i)->getFreq()<<endl;
      }
    }

    void createTree(){
      while(tam != 1){
        cout<<"Tabela: "<<endl;
        //this->printTable();
        Node newNode;

        newNode.setFreq(this->getNode(0)->getFreq() + this->getNode(1)->getFreq());

        if(this->getNode(0)->getFreq() > this->getNode(1)->getFreq()){

          newNode.setDir(&this->nodes[0]);

          newNode.setEsq(&this->nodes[1]);

        } else if(this->getNode(0)->getFreq() < this->getNode(1)->getFreq()){
          
          newNode.setDir(&this->nodes[1]);

          newNode.setEsq(&this->nodes[0]);
          
        } else{
          newNode.setDir(&this->nodes[1]);

          newNode.setEsq(&this->nodes[0]);
        }

        this->nodes[0] = newNode;

        for(int i = 1; i < tam - 1; i++){
          this->nodes[i] = this->nodes[i+1];
        }

        this->tam--;
      }
    }

    void createLetterDictionary(){
      Node* root = getNode(0);
      cout<<"Letra: "<<root->getEsq()->getFreq()<<endl;
    }
};

int main(){
  Huffman codigo;

  string frase = "apaga";

  codigo.setFrase(frase);

  codigo.createTable();

  codigo.orderList();

  codigo.createTree();

  codigo.createLetterDictionary();

  return 0;
}
