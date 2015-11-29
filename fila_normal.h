#ifndef FILA_NORMAL
#define FILA_NORMAL

#include <iostream>
#include <fila.h>

using namespace std;

class Fila_normal : public Fila {

public:
    Fila_normal(); // construtor
    bool possui_Espera(); // true se tem fichas aguardando
};

#endif // FILA_NORMAL

