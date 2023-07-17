#include <stdio.h>
#include <stdlib.h> 

#include "animal.h"

struct animal {
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; // em KG
	int status; // 1 - Nascimento na própria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais() {
	return NULL;
}

Animal *cadastrar(Animal *rebanho) {
	Animal *novo = (Animal*)malloc(sizeof(Animal));
	printf("\nInforme o id da fazenda: ");
	scanf("%d", &novo->id_fazenda);

	// Verifica se a fazenda já existe
	Animal *temp;
	for (temp = rebanho; temp != NULL; temp = temp->prox) {
		if (novo->id_fazenda == temp->id_fazenda) {
			printf("A fazenda já existe.\n");
			free(novo);
			return rebanho; // Retorna a lista original sem adicionar o novo animal
		}
	}

	printf("Informe o id do animal: ");
	scanf("%d", &novo->id_animal);

	// Verifica se o id do animal já existe
	for (temp = rebanho; temp != NULL; temp = temp->prox) {
		if (novo->id_animal == temp->id_animal) {
			printf("O id do animal ja existe.\n");
			free(novo);
			return rebanho; // Retorna a lista original sem adicionar o novo animal
		}
	}

	printf("Informe o sexo do animal (M ou F): ");
	scanf(" %c", &novo->sexo);
	if (novo->sexo != 'M' && novo->sexo != 'F') {
		printf("Sexo invalido. Utilize 'M' ou 'F'.\n");
		free(novo);
		return rebanho; // Retorna a lista original sem adicionar o novo animal
	}

	printf("Informe o peso do animal: ");
	scanf("%f", &novo->peso);

	printf("Informe o status do animal:\n");
	printf("1 - Nascimento na propria fazenda.\n");
	printf("2 - Venda.\n");
	printf("3 - Troca\n");
	scanf("%d", &novo->status);
	if (novo->status != 1 && novo->status != 2 && novo->status != 3) {
		printf("Status invalido. Utilize 1, 2 ou 3.\n");
		free(novo);
		return rebanho; // Retorna a lista original sem adicionar o novo animal
	}

	novo->prox = rebanho;
	rebanho = novo;

	return rebanho;
}

Animal *buscarAnimal(Animal *rebanho)
{
	Animal *aux;
	int id;
	printf("Informe o id do animal: ");
	scanf("%d", &id);
	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
	{
		if(aux->id_animal == id)
		{
			printf("---------------------------------------\n");
			printf("Id da fazenda: %d\n", rebanho->id_fazenda);
			printf("Id do animal: %d\n", rebanho->id_animal);
			printf("Sexo: %c", rebanho->sexo);
			printf("Peso: %.2f", rebanho->peso);
			if (rebanho->status == 1)
			{
				printf("Status: Nascimento na propria fazenda.\n");
			}
			if (rebanho->status == 2)
			{
				printf("Status: Vendido.\n");
			}
			if (rebanho->status == 3)
			{
				printf("Status: Troca.\n");
			}

		}
	}

	return NULL;
}

void mostrarAnimalSexo(Animal *rebanho)
{
	Animal *aux;
	int countF = 0, countM = 0;
	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
	{
		if (aux->sexo == 'F')
		{
			countF++;
		}
		if (aux->sexo == 'M')
		{
			countM++;
		}	
	}

}

Animal mostrarAnimalStatus(Animal *rebanho)
{
	Animal *aux;
	int sts;
	printf("Informe o tipo de status do animal que queira listar: ");
	scanf("%d", &sts);
	if (sts == 1)
	{
		printf("Status: Nascimento na propria fazenda.\n");
	}
	if (sts == 2)
	{
		printf("Status: Vendido.\n");
	}
	if (sts == 3)
	{
		printf("Status: Troca.\n");
	}
	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
	{
		if(aux->status == sts)
		{
			printf("---------------------------------------\n");
			printf("Id da fazenda: %d\n", rebanho->id_fazenda);
			printf("Id do animal: %d\n", rebanho->id_animal);
			printf("Sexo: %c", rebanho->sexo);
			printf("Peso: %.2f", rebanho->peso);
		}
	}
}