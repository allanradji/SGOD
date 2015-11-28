#include <iostream>
#include "fila.h"

using namespace std;

Fila::Fila(){
    this->cabeca = NULL;
    this->tamanho = 0;
}

void Fila::enqueue(No *ptr){
	if(this->cabeca == NULL){
		this->cabeca = ptr;
	}else{
		No *atual = this->cabeca;
		while (atual->proximo != NULL) {
			atual = atual->proximo;
		}
		atual->proximo = ptr;
	}
    this->tamanho += 1;
}

No *Fila::dequeue(){
	No *aux = this->cabeca; // novo nó auxiliar é criado e aponta para o primeiro da fila
	this->cabeca = aux->proximo; // cabeca aponta para o proximo da lista
	aux->proximo = NULL; // O nó removido passar a apontar para nulo, pois caso seja utilazado para outros fins ele não terá mais ligação com a lista
    return aux; // retorna o nó removido.
}

