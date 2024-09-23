 #include <iostream>
 #include <locale.h>
 // importar as funções do arquivo funcoesAuxiliares.cpp
 #include "funcoesAuxiliares.cpp"

 int main() {
    setlocale(LC_ALL, "Portuguese");
    
    limparTerminal();
    escreva("Ola mundão!");
    return 0;
 }