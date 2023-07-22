#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"
#include "fazenda.h"

int menu(){
    printf("\n---------------------------------------------\n");
    printf("1 - Cadastrar Criador\t2 - Cadastrar Fazenda\n");
    printf("3 - Cadastrar Animal\t4 - Mostrar Criador\n");
    printf("5 - Remover Criador\t6 - Remover Fazenda\n");
    printf("7 - Remover Animal\t8 - Tem Fazenda\n");
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);

    return op;
}

int main() {

    Criador *listaCriadores = criarListaDuplaCriadores();

    Criador *c;
    Fazenda *f;
    //Animal *a;
    Criador *c1;
    Criador *c2;
    Fazenda *f1 = NULL;
    Fazenda *f2 = NULL;

    int r = 1;

    while(r != 0){
        r = menu();
        switch (r){
        case 1:
            listaCriadores = cadastrarCriador(listaCriadores);
            break;
        case 2:
            c = buscarCriador(listaCriadores);
            c->fazendas = cadastrarFazenda(c->fazendas);
            break;
        case 3:
            c = buscarCriador(listaCriadores);
            f = buscarFazenda(c->fazendas);
            f->rebanho = cadastrarAnimal(f->rebanho);
            break;
        case 4:
            mostrarCriadores(listaCriadores);
            break;
        case 5:
            listaCriadores = removerCriador(listaCriadores);
            break;
        case 7:
            c = buscarCriador(listaCriadores);
            f = buscarFazenda(c->fazendas);
            f->rebanho = buscarAnimal(f->rebanho);
            int x;
            printf("Informe o id do animal: ");
            scanf("%d", &x);
            f->rebanho = removerAnimal(c->fazendas, x);
            break;
        case 8:
            c = buscarCriador(listaCriadores);
            printf("Tem fazenda %d\n", temFazenda(c->fazendas));
            break;
        case 9:

            c1 = buscarCriador(listaCriadores);
            c2 = buscarCriador(listaCriadores);
            f1 = buscarFazenda(c1->fazendas);
            f2 = buscarFazenda(c2->fazendas);
            permutasAnimais(c1->fazendas, c2->fazendas);
            
            break;
        default:
            break;
        }
    }

    /*listaCriadores = cadastrarCriador(listaCriadores);
    listaCriadores = cadastrarCriador(listaCriadores);
    listaCriadores = cadastrarCriador(listaCriadores);

    c = buscarCriador(listaCriadores);

    c->fazendas = cadastrarFazenda(c->fazendas);

    mostrarCriadores(listaCriadores);

    listaCriadores = removerCriador(listaCriadores);

    mostrarCriadores(listaCriadores);*/



    // listaCriadores = cadastrarCriador(listaCriadores);

    // c = buscarCriador(listaCriadores);

    // c->fazendas = cadastrarFazenda(c->fazendas);

    //mostrarCriadores(c);

    //printf("Id fazenda criador: %5d \tId fazenda fazenda: %5d\n", c->fazendas->id_criador, c->fazendas->id_fazenda);

    //c = buscarCriador(listaCriadores);

    //f = buscarFazenda(c->fazendas);

    //printf("Teste fazenda criador: %5d \tTeste fazenda fazebda: %5d\n", f->id_criador, f->id_fazenda);

    //c = buscarCriador(listaCriadores);

    //f = buscarFazenda(c->fazendas);
    //mostrarFazenda(f);

    //a = buscarAnimal(f->rebanho);

    //printf("Id animal %5d\tId fazenda %5d\n", a->id_animal, a->id_fazenda);

    return 0;
}

// \Trabalhos-Estruturas-de-Dados>teste.exe
