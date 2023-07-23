#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Info cliente
struct endereco
{
    int CEP, numero_casa;
    char cidade[20], estado[3], rua[50]; 
};

struct transportadora
{
    int contato;
    char nome[100], id[15];
    struct endereco local;
    struct transportadora *prox;
};

struct fila
{
    struct transportadora *inicio;
    struct transportadora *fim;
};

typedef struct endereco Endereco;
typedef struct transportadora Transportadora;
typedef struct fila Fila;

Transportadora *CriarListaEncadeada()
{
    return NULL;
}

Transportadora *cadastroCliente(Transportadora *cliente)
{
    Transportadora *novo = (Transportadora *)malloc(sizeof(Transportadora));
    printf("Informe os dados do cliente.\n\n");
    fflush(stdin);
    printf("Nome completo: ");
    scanf(" %99[^\n]", novo->nome);
    fflush(stdin);
    printf("Identidade: ");
    scanf(" %14[^\n]", novo->id);
    printf("Contato: ");
    scanf("%d", &novo->contato);
    printf("\nInforme o endereco.\n");
    fflush(stdin);
    printf("Cidade: ");
    scanf(" %19[^\n]", novo->local.cidade);
    fflush(stdin);
    printf("Estado: ");
    scanf(" %2[^\n]", novo->local.estado);
    fflush(stdin);
    printf("Rua: ");
    scanf(" %49[^\n]", novo->local.rua);
    fflush(stdin);
    printf("CEP: ");
    scanf("%d", &novo->local.CEP);
    printf("Numero da casa: ");
    scanf("%d", &novo->local.numero_casa);

    novo->prox = cliente;

    return novo;
}

Transportadora *buscarCliente(Transportadora *cliente)
{
    Transportadora *t = cliente;
    char identidade[15];
    printf("Informe a id do cliente a ser buscada: ");
    scanf(" %14[^\n]", identidade);
    while (t != NULL)
    {
        if (strcmp(t->id, identidade) == 0)
        {
            printf("Cliente encontrado.\n\n");
            printf("Dados do cliente.\n\n");
            printf("Nome completo: %s\n", t->nome);
            printf("Identidade: %s\n", t->id);
            printf("Contato: %d\n", t->contato);
            printf("Cidade: %s\n", t->local.cidade);
            printf("Estado: %s\n", t->local.estado);
            printf("Rua: %s\n", t->local.rua);
            printf("CEP: %d\n", t->local.CEP);
            printf("Numero da casa: %d\n", t->local.numero_casa);
            printf("\n");
            return t;
        }
        t = t->prox;     
    }
    printf("Cliente nao encontrado.\n");
    return NULL;
}

Transportadora *excluirCliente(Transportadora *cliente)
{
    Transportadora *ant = NULL;
    Transportadora *t = cliente;
    char identidade[15];
    printf("Informe a id do cliente a ser excluido: ");
    scanf(" %14[^\n]", identidade);
    while (t != NULL && strcmp(t->id, identidade) != 0)
    {
        ant = t;
        t = t->prox;
    }
    if (t == NULL)
    {
        printf("Cliente nao encontrado.\n");
        return cliente;
    }
    if (ant == NULL)
    {
        cliente = t->prox;
    }
    else
    {
        ant->prox = t->prox;
    }

    free(t);

    printf("Cliente excluido com sucesso.\n");
    return cliente;   
}






Fila *criarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void entregas(Transportadora *cliente, Fila *f)
{
    Transportadora *aux = cliente;
    while (aux != NULL)
    {
        if (aux->prox != NULL && aux->local.CEP == aux->prox->local.CEP)
        {
            if (f->fim != NULL)
                f->fim->prox = aux->prox;
            else
                f->inicio = aux->prox;
            f->fim = aux->prox;
            aux->prox = aux->prox->prox;
            f->fim->prox = NULL;
        }
        else
        {
            aux = aux->prox;
        }
    }
}

void imprimirCliente(Transportadora *cliente)
{
    Transportadora *t;

    for (t = cliente; t != NULL; t = t->prox)
    {
        printf("Dados do cliente.\n\n");
        printf("Nome completo: %s\n", t->nome);
        printf("Identidade: %s\n", t->id);
        printf("Contato: %d\n", t->contato);
        printf("Cidade: %s\n", t->local.cidade);
        printf("Estado: %s\n", t->local.estado);
        printf("Rua: %s\n", t->local.rua);
        printf("CEP: %d\n", t->local.CEP);
        printf("Numero da casa: %d\n", t->local.numero_casa);
        printf("\n");
    }
}

void liberarLista(Transportadora *cliente)
{
    Transportadora *proxCliente;

    while (cliente != NULL)
    {
        proxCliente = cliente->prox;
        free(cliente);
        cliente = proxCliente;
    }
}