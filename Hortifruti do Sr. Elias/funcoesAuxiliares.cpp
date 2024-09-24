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
        cout << "Por favor, responda apenas 's' ou 'n': ";
        cin >> resposta;
        escreva(resposta + "\n");
        if (resposta == "Sim" || resposta == "sim" || resposta == "s") {
            respostaValida = true;
            return true;
        } else if (resposta == "Nao" || resposta == "nao" || resposta == "n") {
            respostaValida = true;
            return false;
        } else {
            cout << "Resposta inválida. Tente novamente." << endl;
        }
    }
}
