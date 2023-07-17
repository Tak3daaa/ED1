#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criador.h"
#include "fazenda.h"
//#include "fazenda.c"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

int id = 0;

Criador *criarListaDuplaCriadores(){
	/*Criador *c;

	c = (Criador*)malloc(sizeof(Criador));

	c->ant = NULL;
	c->prox = NULL;*/

	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));
	//c->fazendas = (Fazenda*)malloc(sizeof(Fazenda));
	//c->fazendas->prox = NULL;
	//c->fazendas->id_fazenda = id;
	c->id_criador = ++id;
	c->ant = NULL;
	strcpy(c->nome, "teste");
	if(!criadores){
		c->prox = NULL;
	} else{
		c->prox = criadores;
		criadores->ant = c;
	}

	return c;
}

Criador *cadastrarCriadorII(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));
	//c->fazendas = (Fazenda*)malloc(sizeof(Fazenda));
	//c->fazendas = NULL;
	++id;
	//c->fazendas->id_fazenda = id;
	c->id_criador = id;
	c->ant = NULL;
	strcpy(c->nome, "teste");
	if(!criadores){
		c->prox = NULL;
	} else{
		c->prox = criadores;
		criadores->ant = c;
	}

	return c;
}


int temFazenda(Fazenda *fazenda){
	if(fazenda){
		return 1;
	}

	return 0;
}

int size(Criador *c){
	Criador *aux;
	int count = 0;

	aux = c;
	while(aux){
		count++;
		aux = aux->prox;
	}

	return count;
}

int buscarCriador(Criador *criadores){
	Criador *aux = criadores;
	int id = 3, rep = 0;

	while(aux){
		if(id == aux->id_criador){
			return rep;
		}

		aux = aux->prox;
		rep++;
	}

	return -1;
}

void mostrarCriadores(Criador *criadores){
	Criador *aux = criadores;
	//printf("Id\tNome\tTem Fazenda\tId fazenda\n");
	printf("Id\tNome\n");
	while(aux){
		//printf("%d\t%s\t\t", aux->id_criador, aux->nome);
		printf("%d\t%s\n", aux->id_criador, aux->nome);
		//printf("%d\t\t%d\n", temFazenda(aux->fazendas), aux->fazendas->id_fazenda);
		aux = aux->prox;
	}
}

