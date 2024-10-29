 #include <iostream>
 #include <locale.h>
 #include "funcoes.cpp"

 using namespace std;

 int main() {
    setlocale(LC_ALL, "Portuguese");
    
    limparTerminal();
    menuComprarProduto();
    
    return 0;
 }