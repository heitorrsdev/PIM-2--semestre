#include <iostream>
using namespace std;

// criando uma funçãoo para limpar o terminal
void limparTerminal () {
    cout << "\033[2J\033[1;1H";
}


// criando uma função para escrever no terminal
void escreva (const string& texto="") {
    cout << "\n" + texto;
}