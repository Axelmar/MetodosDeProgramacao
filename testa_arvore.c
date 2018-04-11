/** Primeiro trabalho da disciplina Metodos de Programacao
*   Aluno: Marcelo Axel Chiapinotto de Nazare
*   @brief Arquivo de teste da arvore binaria implementada em C
*   @file testa_arvore.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
//#include "catch.hpp"

//#define CATCH_CONFIG_MAIN //This tells Catch to provide a main() - only do this in one cpp file




/*TEST_CASE( "Inclusao bem sucedida", "[inserir]") {
  REQUIRE( inserir(&primeiroNo, 123) == 123);
}*/

int main(){

  No *primeiroNo = NULL;

  criarArvore(&primeiroNo);

  inserir(&primeiroNo, 123);
  inserir(&primeiroNo, 321);
  inserir(&primeiroNo, 213);

  exibirEmOrdem(primeiroNo);
  printf("\n");
  
  exibirPosOrdem(primeiroNo);
  printf("\n");

  exibirPreOrdem(primeiroNo);
  printf("\n");

  printf("%i \n", contarNos(primeiroNo));
  printf("%i \n", contarFolhas(primeiroNo));
  printf("%i \n", altura(primeiroNo));
  printf("\n");

  remover(&primeiroNo, 213);

  exibirPreOrdem(primeiroNo);
  printf("\n");

  busca(primeiroNo);
  destruir(&primeiroNo);
  destruir(&primeiroNo);







  return 0;
}