#include <locale.h>
#include "funcoes.cpp"
#include "tipos.cpp"

using namespace std;

int main() {
   setlocale(LC_ALL, "Portuguese");
    
   limparTerminal();

   menuPrograma();


   return 0;
}
