#ifndef _FILA_H_
#define _FILA_H_

#include <iostream>

using namespace std;

struct No{ // Estrutura nó (separada da Fila)
    int numero;
    No *proximo;
};

class Fila{ // Estrutura Fila
private:
    No *cabeca; // ponteiro cabeça da fila
    int tamanho; // variável estática da classe, indica o tamanho da fila.

public:
    int tipoFicha;//tipo 1-normal; 2-prioridade
    Fila(); // construtor
    void enqueue(No *node); // Inserção na fila
    int getTipoFicha(); //retorna se a ficha é normal ou prioridade
    No *dequeue(); // remoção na Fila

};

#endif
