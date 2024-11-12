#ifndef TIPOS_H
#define TIPOS_H

#include <vector>
#include <string>

struct Produto {
    int id;
    std::string nome;
    double preco;
    int tipo; // 1 para unitário, 2 para por kilo
    int quantidade;
    int fornecedorID; // Referência ao fornecedor pelo ID
};

struct Fornecedor {
    int id;
    std::string nome;
    std::string contato;
};

#endif // TIPOS_H
