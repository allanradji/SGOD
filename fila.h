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
    int tipoFicha;//tipo 1-normal; 2-prioridade
    Fila(); // construtor
    void enqueue(No *node); // Inser��o na fila
    int getTipoFicha(); //retorna se a ficha � normal ou prioridade
    No *dequeue(); // remo��o na Fila

};

#endif
