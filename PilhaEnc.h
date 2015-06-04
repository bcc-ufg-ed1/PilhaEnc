#ifndef PILHA_ENC_H
#define PILHA_ENC_H

#define TRUE 1
#define FALSE 0

#define OK 0
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_VAZIA -2
#define PARAMETRO_INVALIDO -3

typedef struct {
  int item;
  struct No* prox;
} No;

typedef struct {
  No* topo;
} PilhaEnc;

PilhaEnc* criarPilha();
int liberarPilha(PilhaEnc* pilha);
int estahVazia(PilhaEnc* pilha);
int empilhar(PilhaEnc* pilha, int item);
int desempilhar(PilhaEnc* pilha, int* item);
int obterTopo(PilhaEnc* pilha, int* item);

#endif // PILHA_ENC_H
