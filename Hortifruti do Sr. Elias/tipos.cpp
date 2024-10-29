#include <iostream>

using namespace std;

struct Produto {
    string tipo; //1 para unitário e 2 para kg
    string nome;
    double preco;
    double quantidadeEstoque;
};
typedef struct Produto produto;

