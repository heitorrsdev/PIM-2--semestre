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
