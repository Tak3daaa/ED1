#include <stdio.h>
#include <stdlib.h>

#include "fazenda.h"
#include "fazenda.c"

int main() {


    Fazenda *faz;


    faz = criarListaEncadeadaCircularFazendas();

    faz = cadastrarFazenda(faz);

    Fazenda *aux = faz;

    while(aux){
        if(aux->prox == faz) break;
        printf("%d\n", aux->id_fazenda);
        aux = aux->prox;
    }

    return 0;
}
