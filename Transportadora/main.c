#include <stdio.h>
#include <stdlib.h>
#include "transportadora.h"
#include "transportadora.c"

int main()
{
    Transportadora *lista_clientes = CriarListaEncadeada();
    Fila *fila_entregas = criarFila();
    int opcao = -1;

    do
    {
        printf("Menu:\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Realizar entregas\n");
        printf("3 - Imprimir clientes\n");
        printf("4 - Buscar cliente\n");
        printf("5 - Remover cliente\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            lista_clientes = cadastroCliente(lista_clientes);
            break;

        case 2:
            entregas(lista_clientes, fila_entregas);
            break;

        case 3:
            imprimirCliente(lista_clientes);
            break;

        case 4:
            lista_clientes = buscarCliente(lista_clientes);
            break;

        case 5:           
            lista_clientes = excluirCliente(lista_clientes);
            break;
        case 0:
            liberarLista(lista_clientes);
            free(fila_entregas);
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
