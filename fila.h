#ifndef _FILA_H_
#define _FILA_H_

#include <iostream>

using namespace std;

struct No{ // Estrutura n� (separada da Fila)
    int numero;
    No *proximo;
};

class Fila{ // Estrutura Fila
private:
    No *cabeca; // ponteiro cabe�a da fila
    int tamanho; // vari�vel est�tica da classe, indica o tamanho da fila.

public:
    Fila(); // construtor
    void enqueue(No *node); // Inser��o na fila
    No *dequeue(); // remo��o na Fila

};

#endif
