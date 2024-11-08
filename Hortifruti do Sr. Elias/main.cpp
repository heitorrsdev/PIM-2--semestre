#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "funcoes.cpp"

using namespace std;

int main() {
   setlocale(LC_ALL, "Portuguese");
    
   limparTerminal();

   menuPrograma();
   cout << "Menu foi exibido";

   return 0;
}
