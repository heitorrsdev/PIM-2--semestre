 #include <iostream>
 #include <locale.h>
 // importar as fun��es do arquivo funcoesAuxiliares.cpp
 #include "funcoesAuxiliares.cpp"

 int main() {
    setlocale(LC_ALL, "Portuguese");
    
    limparTerminal();
    escreva("Ola mund�o!");
    return 0;
 }