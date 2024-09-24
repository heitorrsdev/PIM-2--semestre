 #include <iostream>
 #include <locale.h>
 #include "funcoesAuxiliares.cpp" // arquivo com funções auxiliares

 int main() {
    setlocale(LC_ALL, "Portuguese");
    
    limparTerminal();
    
    escreva("Ola mundão!");
    
    bool resposta = perguntaSimNao();
    escreva(resposta ? "Resposta correta!" : "Resposta errada!");
    return 0;
 }