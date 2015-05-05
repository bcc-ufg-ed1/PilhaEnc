#include<stdio.h>
#include<stdlib.h>
#include "PilhaEnc.h"

void imprimirPilha(PilhaEnc* p) {
    PilhaEnc* pAux = criarPilha();
    int item;
    while(!estahVazia(p)) {
        desempilhar(p, &item);
        printf("%d\n", item);
        empilhar(item, pAux);
    }
    while(!estahVazia(pAux)) {
        desempilhar(pAux, &item);
        empilhar(item, p);
    }
    liberarPilha(pAux);
}

int main() {
    PilhaEnc* minhaPilha = criarPilha();
    empilhar(1, minhaPilha);
    empilhar(2, minhaPilha);
    empilhar(3, minhaPilha);
    imprimirPilha(minhaPilha);
    liberarPilha(minhaPilha);
    return EXIT_SUCCESS;
}
