#include <iostream>
using namespace std;

// limpa o terminal
void limparTerminal () {
    cout << "\033[2J\033[1;1H";
}


// escreve no terminal
void escreva (const string& texto="") {
    cout << texto;
}


bool perguntaSimNao() {
    string resposta;
    bool respostaValida = false;

    while (!respostaValida) {
        escreva("Por favor, responda apenas 's' ou 'n': ");
        cin >> resposta;

        if (resposta == "Sim" || resposta == "sim" || resposta == "s") {
            respostaValida = true;
            return true;
        } else if (resposta == "Nao" || resposta == "nao" || resposta == "n") {
            respostaValida = true;
            return false;
        } else {
            escreva("Resposta inv�lida. Tente novamente.\n") ;
        }
    }
}
