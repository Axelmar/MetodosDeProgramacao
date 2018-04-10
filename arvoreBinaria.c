#include <stdio.h>
#include <stdlib.h>

// Instanciando os elementos da arvore.

struct No{
  int numero;
  struct No *esquerda;
  struct No *direita;
};
typedef struct No No;

// Para criar a arvore criamos um novo ponteiro
// o qual ainda nao aponta para lugar nenhum.
void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}


// Para inserir um novo elemento na arvore biaria
// temos que alocar o espaço ncesssário para esse novo
// no e criar dois novos ponteiros que apontam para a folha
// da esquerda e da direita e um ponteiro para o conteudo desse novo no.
// Teremos dois comportamentos para colocar a arvore em ordem. Se a raiz
// existir mas estiver vazia apenas vamos inserir, caso contrario iremos
// verificar recursivamente o local para que os nos fiquem em ordem crescente.
void inserir(No **Raiz, int numero){
  if (*Raiz==NULL){
    *Raiz=(No *)malloc(sizeof (No));
    (*Raiz)->esquerda=NULL;
    (*Raiz)->direita=NULL;
    (*Raiz)->numero=numero;
  }else {
    if (numero<((*Raiz)->numero)){
      inserir(&(*Raiz)->esquerda, numero);
    }else{
      inserir(&(*Raiz)->direita, numero);
    }
  }
}

// Como a arvore binaria se organiza com os menres nos a esquerda e os maiores
// nos a direita as duas funções seguintes servem para buscar os endereços dos 
// maior no a direita e do menor no a esquerda ou seja, as folhas mais distantes da raiz.
No *MaiorDireita(No **no){
    if((*no)->direita != NULL) 
       return MaiorDireita(&(*no)->direita);
    else{
       No *aux = *no;
       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esquerda;
       else
          *no = NULL;
       return aux;
       }
}

No *MenorEsquerda(No **no){
    if((*no)->esquerda != NULL) 
       return MenorEsquerda(&(*no)->esquerda);
    else{
       No *aux = *no; 
       if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->direita;
       else
          *no = NULL;
       return aux;
       }
}

// Para removermos um no da arvore temos que verirficar se a arvore existe
// a seguir iremos procurar pelas folhas da arvore de forma recursiva e comparando
// o que queremos remover com o conteudo de cada folha. Uma vez que achamos o no
// iremos guardar sua posição e remove-lopara em seguida rearranjar a arvore de
// forma a manter suas propriedades.
void remover(No **pRaiz, int numero){
    if(*pRaiz == NULL){                       // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       getchar();
       return;
    }
    if(numero < (*pRaiz)->numero)
       remover(&(*pRaiz)->esquerda, numero);
    else 
       if(numero > (*pRaiz)->numero)
          remover(&(*pRaiz)->direita, numero);
       else{                                 // se nao eh menor nem maior, logo, eh o numero que estou procurando
          No *pAux = *pRaiz;     
          if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL; 
               }  
          else{                   // so tem o filho da direita
             if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux); pAux = NULL;
                }
             else{               //so tem filho da esquerda
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{                                        //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = MaiorDireita(&(*pRaiz)->esquerda); //caso contrario, so o que mudaria seria isso:
                   pAux->esquerda = (*pRaiz)->esquerda;      //pAux = MenorEsquerda(&(*pRaiz)->direita);
                   pAux->direita = (*pRaiz)->direita;
                   (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}

// Função recursiva que mostra os nós em ordem crescente de tamanho,
// vasculhando primeiro as folhas da esquerda e em seguite as da direita.
void exibirEmOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esquerda);
        printf("%i \n", pRaiz->numero);
        exibirEmOrdem(pRaiz->direita);
    }
}

// Função recursiva que mostra os nós na ordem em que foram adicionados a arvore
// mantendo a caracteristica de vasculhar primeiro as folhas da esquerda e em seguida as da direita.
void exibirPreOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("%i \n", pRaiz->numero);
        exibirPreOrdem(pRaiz->esquerda);
        exibirPreOrdem(pRaiz->direita);
    }

}

// Assim como as outras busca na ordem crescente da arvore, porem apresenta as folhas na 
// ordem inversa que foram inseridas.
void exibirPosOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("%i \n", pRaiz->numero);
    }

}

// Conta o numero de nós total existente na arvore.
int contarNos(No *pRaiz){
   if(pRaiz == NULL)
        return 0;
   else
        return 1 + contarNos(pRaiz->esquerda) + contarNos(pRaiz->direita);
}

//  Conta o numero de folhas total existente na arvore.
int contarFolhas(No *pRaiz){
   if(pRaiz == NULL)
        return 0;
   if(pRaiz->esquerda == NULL && pRaiz->direita == NULL)
        return 1;
   return contarFolhas(pRaiz->esquerda) + contarFolhas(pRaiz->direita);
}

// Função auxiliar, compara dois numeros e retorna o maior
int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

// Percorre a arvore até o final e no caminho conta para retornar a altura da arvore.
int altura(No *pRaiz){
   if((pRaiz == NULL) || (pRaiz->esquerda == NULL && pRaiz->direita == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->esquerda), altura(pRaiz->direita));
}

// Função auxiliar que retorna o endereço de um nó na arvore.
No* busca_no(No *raiz, int chave) {
  if (raiz == NULL || raiz->numero == chave) {
    return raiz;
  } else if (raiz->numero > chave) {
    return busca_no(raiz->esquerda, chave);
  } else {
       return busca_no(raiz->direita, chave);
  }
}

// Busca atravez da arvore um no com o valor especificado pelo usuário.
void busca(No *raiz)  {
  int num = 0;
  
  printf("\nDigite o numero a ser buscado: ");

  scanf("%d", &num);
  if (busca_no(raiz, num)) {
    printf("%d achado!\n", num);
  } else {
    printf("%d nao achado!\n", num);
  }
}