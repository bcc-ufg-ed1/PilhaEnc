#include<stdio.h>
#include<stdlib.h>
#include "PilhaEnc.h"

void imprimirPilha(PilhaEnc* p) {
    PilhaEnc* pAux = criarPilha();
    int item;
    while(!estahVazia(p)) {
        desempilhar(p, &item);
        printf("%d\n", item);
        empilhar(pAux, item);
    }
    while(!estahVazia(pAux)) {
        desempilhar(pAux, &item);
        empilhar(p, item);
    }
    liberarPilha(pAux);
}

int main() {
    PilhaEnc* minhaPilha = criarPilha();
    empilhar(minhaPilha, 1);
    empilhar(minhaPilha, 2);
    empilhar(minhaPilha, 3);
    imprimirPilha(minhaPilha);
    liberarPilha(minhaPilha);
    return EXIT_SUCCESS;
}
