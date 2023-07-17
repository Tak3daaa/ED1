#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "animal.c"

int main() {

    Animal *animal;

    animal = criaListaEncadeadaSimplesAnimais();

    animal = cadastrar(animal);
    animal = cadastrar(animal);
    animal = cadastrar(animal);

    Animal *aux = animal;

    while(aux){
        printf("%d %d %.2f %c %d\n", aux->id_animal, aux->id_fazenda, aux->peso, aux->sexo, aux->status);
        aux = aux->prox;
    }

    

    return 0;
}
