#ifndef FILA_PRIORIDADE
#define FILA_PRIORIDADE

#include <iostream>
#include <fila.h>

using namespace std;

class Fila_prioridade : public Fila {

public:
    Fila_prioridade(); // construtor
    bool possui_Espera();// true se tem fichas aguardando
};

#endif // FILA_PRIORIDADE

