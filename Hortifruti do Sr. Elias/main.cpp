#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "funcoes.h"
#include "tipos.h"

using namespace std;

int main() {
   setlocale(LC_ALL, "Portuguese");
    
   limparTerminal();

   menuPrograma();


   return 0;
}
