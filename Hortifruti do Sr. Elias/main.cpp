#include <locale.h>
#include <iostream>
#include "funcoes.h"
#include "tipos.h"

using namespace std;

// Compilar no terminal cm o comando 
// g++ -Wall -Wextra -g3 main.cpp funcoes.cpp -o output/main.exe

int main() {
   setlocale(LC_ALL, "");
   
   cout << "Maçã de abóbora" << endl;
   limparTerminal();
   menuPrograma();

   return 0;
}
