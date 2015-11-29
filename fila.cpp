#include <iostream>
#include "fila.h"

using namespace std;

Fila::Fila(){ // construtor
    this->cabeca = NULL;
    this->tamanho = 0;
    ultimaFichaRetirada = 0;
    this->tail = NULL;
}

No* Fila::getCabeca(){ // get's e set's
    return this->cabeca;
}

void Fila::setCabeca(No *node){
    this->cabeca = node;
}

No* Fila::getTail(){
    return this->tail;
}

void Fila::setTail(No *node){
    this->tail = node;
}

int Fila::getTamanho(){
    return this->tamanho;
}

void Fila::setTamanho(int value){
    this->tamanho = value;
}

void Fila::enqueue(No *ptr){ // inserç?o em fila
    if(this->cabeca == NULL){ // se a cabeça estiver vazia a fila deve receber um novo nó
        ptr->setNumero(1); // inserindo numero da primeira ficha
        this->cabeca = ptr;
        this->tail = cabeca;
    }else{ // caso contrário
        ptr->setNumero(this->tail->getNumero()+1); // Inserindo o numero da ficha
        this->tail->setProximo(ptr); // a calda da fila encadeia o novo nó
        this->tail = this->tail->getProximo(); // a calda da fila é atualizada
    }
    this->tamanho += 1; // tamanho da fila é atualizado
    this->ultimaFichaRetirada = this-tail->getNumero();
}

No *Fila::dequeue(){
    No *aux = this->cabeca; // novo nó auxiliar é criado e aponta para o primeiro da fila
    this->cabeca = aux->getProximo(); // cabeca aponta para o proximo da lista
    aux->setProximo(NULL); // O nó removido passar a apontar para nulo, pois caso seja utilazado para outros fins ele não terá mais ligação com a lista
    this->tamanho -= 1; // diminui o tamanho
    return aux; // retorna o nó removido.
}

No* Fila::front (){ // consulta o primeiro da fila sem remover
    return this->cabeca;
}

No* Fila::last (){ // consulta o último da fila sem remover
    return this->tail;
}

int Fila::getTipoFicha(){
    return this->tipoFicha;
}

bool Fila::isEmpty(){
    if (this->cabeca == NULL){
        return true;
    }else{
        return false;
    }
}
