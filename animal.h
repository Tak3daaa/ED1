typedef struct animal Animal; 

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho);
Animal *buscarAnimal(Animal *rebanho);
void mostrarAnimalSexo(Animal *rebanho);
void mostrarAnimalStatus(Animal *rebanho);
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAnimal(Fazenda *fazenda, int id_animal); 
/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/
