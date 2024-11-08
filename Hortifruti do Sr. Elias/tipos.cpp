#include <iostream>

using namespace std;
struct Produto {
    int id;
    string nome;
    double preco;
    int tipo; // 1 para unitário, 2 para por kilo
    int quantidade;
    int fornecedorID; // Referência ao fornecedor pelo ID
};
typedef struct Produto produto;

struct Fornecedor {
    int id;
    string nome;
    string contato;
};
typedef struct Fornecedor fornecedor;
