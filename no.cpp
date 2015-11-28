#include <iostream>
#include "no.h"

using namespace std;

No::No()
{
 this->numero = -1;
 this->proximo = NULL;
}

int No::getNumero(){
    return this->numero;
}
void No::setNumero(int value){
    this->numero = value;
}
No* No::getProximo(){
    return this->proximo;
}
void No::setProximo(No *node){
    this->proximo = node;
}
