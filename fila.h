#ifndef _FILA_H_
#define _FILA_H_

#include <iostream>
#include "no.h"

using namespace std;

class Fila{ // Estrutura Fila
private:
    No *cabeca; // ponteiro cabe�a da fila
    No *tail;
    int tamanho; // vari�vel est�tica da classe, indica o tamanho da fila.

public:
    No* getCabeca(); // Get's e Set's
    void setCabeca(No *node);
    No* getTail();
    void setTail(No *node);
    int getTamanho();
    void setTamanho(int value);
    Fila(); // construtor
    void enqueue(No *node); // Inser��o na fila
    No *dequeue(); // remo��o na Fila
    No *front (); // consulta o primeiro da fila sem remove-lo
    No *last(); // consulta o �ltimo da fila sem remove-lo
    bool isEmpty(); // verifica se a fila est� vazia e retorna TRUE caso esteja
};

#endif
