#ifndef NO_H
#define NO_H


class No{ // Estrutura nó (separada da Fila)
private:
    int numero;
    No *proximo;
public:
    No();
    int getNumero();
    void setNumero(int);
    No* getProximo();
    void setProximo(No*);
};

#endif // NO_H
