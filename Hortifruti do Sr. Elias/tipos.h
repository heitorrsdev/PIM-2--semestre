#ifndef TIPOS_H
#define TIPOS_H

#include <string>
using namespace std;

struct Produto {
    int id;
    string nome;
    double preco;
    int tipo; // 1 para unitário, 2 para por kilo
    int quantidade;
    int fornecedorID;
};

struct Fornecedor {
    int id;
    string nome;
    string contato;
};

#endif // TIPOS_H
