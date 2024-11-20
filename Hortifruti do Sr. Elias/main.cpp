#include <locale.h>
#include <iostream>
#include "funcoes.h"
#include "tipos.h"

using namespace std;

int main() {
   setlocale(LC_ALL, "");
   
   limparTerminal();
   menuPrograma();

   return 0;
}

// utilizar o comando g++ -Wall -Wextra -g3 main.cpp funcoes.cpp -o output/ para compilação