#ifndef _FILA_H_
#define _FILA_H_

#include <iostream>
#include "no.h"

using namespace std;

class Fila{ // Estrutura Fila
private:
    No *cabeca; // ponteiro cabeça da fila
    No *tail;
    int tamanho; // variável estática da classe, indica o tamanho da fila.

public:
    No* getCabeca(); // Get's e Set's
    void setCabeca(No *node);
    No* getTail();
    void setTail(No *node);
    int getTamanho();
    void setTamanho(int value);
    Fila(); // construtor
    void enqueue(No *node); // Inserção na fila
    No *dequeue(); // remoção na Fila
    No *front ();
    No *last();

};

#endif
