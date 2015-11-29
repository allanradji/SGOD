#include <iostream>
#include "fila.h"
#include "fila_prioridade.h"

Fila_prioridade :: Fila_prioridade(){
    this->tipoFicha = 2;
}

bool Fila_prioridade::possui_Espera(){
    //verifica se tem ficha após a última chamada (pode receber a última ficha chamada como parâmetro)
    return false;
}
