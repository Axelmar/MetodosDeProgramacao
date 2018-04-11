#include <stdio.h>
#include <stdlib.h>
#include <arvoreBinaria.h>

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