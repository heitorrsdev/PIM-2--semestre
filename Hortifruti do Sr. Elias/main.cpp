#include <locale.h>
#include "headers/funcoes.h"
#include "headers/tipos.h"

using namespace std;

int main() {
   setlocale(LC_ALL, "Portuguese");
    
   limparTerminal();

   menuPrograma();


   return 0;
}
