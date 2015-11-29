#include <iostream>
#include "fila.h"
#include "fila_normal.h"

Fila_normal::Fila_normal(){
    this->tipoFicha = 1;
}

bool Fila_normal::possui_Espera(){
    //verifica se tem ficha após a última chamada (pode receber a última ficha chamada como parâmetro)
    return true;
}
