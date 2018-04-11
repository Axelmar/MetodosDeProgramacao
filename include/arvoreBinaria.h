typedef struct No{
  int numero;
  struct No *esquerda;
  struct No *direita;
}No;

void criarArvore(No **pRaiz);

void inserir(No **Raiz, int numero);

No *MaiorDireita(No **no);

No *MenorEsquerda(No **no);

void remover(No **pRaiz, int numero);

void destruir(No **pRaiz);

void exibirEmOrdem(No *pRaiz);

void exibirPreOrdem(No *pRaiz);

void exibirPosOrdem(No *pRaiz);

int contarNos(No *pRaiz);

int contarFolhas(No *pRaiz);

int maior(int a, int b);

int altura(No *pRaiz);

No* busca_no(No *raiz, int chave);

void busca(No *raiz);