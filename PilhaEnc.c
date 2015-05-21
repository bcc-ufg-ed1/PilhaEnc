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
	no->item = item;
	no->prox = prox;
	return no;
}

int empilhar(int item, PilhaEnc* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	No *no = criarNo(item, pilha->topo);
	pilha->topo = no;
}

int estahVazia(PilhaEnc *pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	if (pilha->topo == NULL) return TRUE;
	return FALSE;
}

int desempilhar(PilhaEnc* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    No* aux = pilha->topo;
	pilha->topo = aux->prox;
    *item = aux->item;
	free(aux);
	aux = NULL;
	return OK;
}

int apenasDesempilhar(PilhaEnc* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    No* aux = pilha->topo;
	pilha->topo = aux->prox;
	free(aux);
	aux = NULL;
	return OK;
}


int obterTopo(PilhaEnc* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    *item = pilha->topo->item;
    return OK;
}

int liberarPilha(PilhaEnc* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	while(!estahVazia(pilha))
        apenasDesempilhar(pilha);
	free(pilha);
	pilha = NULL;
	return OK;
}
PilhaEnc* clonePilha(PilhaEnc* pilha){
    if(pilha==NULL) return NULL;
    PilhaEnc* novaPilhaAux = criarPilha();
    No* aux = pilha->topo;
    while(aux!=NULL){
        empilhar(aux->item,novaPilhaAux);
        aux=aux->prox;
    }
    PilhaEnc* novaPilha = criarPilha();
    aux=novaPilhaAux->topo;
    while(aux!=NULL){
        empilhar(aux->item,novaPilha);
        aux=aux->prox;
    }
    liberarPilha(novaPilhaAux);
    free(aux);
    return novaPilha;

}

