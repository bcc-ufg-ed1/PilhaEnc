#include<stdio.h>
#include<stdlib.h>
#include "PilhaEnc.h"

PilhaEnc* criarPilha() {
	PilhaEnc *pilha = malloc(sizeof(*pilha));
    if (pilha == NULL)
        return NULL;
	pilha->topo = NULL;
	return pilha;
}

No* criarNo(int item, No* prox) {
	No *no = malloc(sizeof(*no));
	if (no == NULL)
        return NULL;
	no->item = item;
	no->prox = prox;
	return no;
}

int empilhar(PilhaEnc* pilha, int item) {
	No *no = criarNo(item, pilha->topo);
    if (pilha == NULL || no == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	pilha->topo = no;
	return OK;
}

int estahVazia(PilhaEnc *pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	if (pilha->topo == NULL)
        return TRUE;
	return FALSE;
}

int desempilhar(PilhaEnc* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    No* aux = pilha->topo;
	pilha->topo = aux->prox;
    if (item != NULL)
        *item = aux->item;
	free(aux);
	aux = NULL;
	return OK;
}

int obterTopo(PilhaEnc* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    if (item == NULL)
        return PARAMETRO_INVALIDO;
    *item = pilha->topo->item;
    return OK;
}

int liberarPilha(PilhaEnc* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	while(!estahVazia(pilha))
        desempilhar(pilha, NULL);
	free(pilha);
	pilha = NULL;
	return OK;
}
