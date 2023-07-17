typedef struct fazenda Fazenda;
typedef struct endereco Endereco;
#include "criador.h"

Criador *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrar(Fazenda *fazendas);
Fazenda *remover(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
int buscar(Fazenda *fazendas);
Fazenda *getBuscar(Fazenda *fazendas, int id);

/*
Desenvolva funcoes que, dado uma FAZENDA, informar:
- Quantidade de animais por sexo;
- Peso total em arroba (isto é, a cada 15 KG)
- Valor total da fazenda considerando o preço da arroba de R$ 235
- lista de animais por tipo de status
- Funcao para liberar a memoria
*/

//int quantAnimaisSexo(Fazenda *fazenda, char sexo);
void arrobaTotal(Fazenda *fazendas);
void valorTotal(Fazenda *fazenda);
void listaStatusAnimais(Fazenda *fazenda);
void liberarFazendas(Fazenda *fazendas);
