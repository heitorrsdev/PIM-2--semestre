 #include <iostream>
 #include <locale.h>
 #include "funcoesAuxiliares.cpp" // arquivo com fun��es auxiliares

 int main() {
    setlocale(LC_ALL, "Portuguese");
    
    limparTerminal();
    
    escreva("Ola mund�o!");
    
    bool resposta = perguntaSimNao();
    escreva(resposta ? "Resposta correta!" : "Resposta errada!");
    return 0;
 }