#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"

int main() {

    Criador *c;

    c = criarListaDuplaCriadores();

    c = cadastrarCriador(c);
    c = cadastrarCriador(c);
    c = cadastrarCriador(c);
    c = cadastrarCriador(c);
    
    mostrarCriadores(c);

    ///printf("%d\n",temFazenda(c->fazendas));
    

    return 0;
}
