typedef struct animal Animal; 

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho);
Animal *buscarAnimal(Animal *rebanho);
Animal *removerAnimal(Fazenda *fazenda, int id_animal);
void permutasAnimais(Fazenda *origem, Fazenda *destino);//obervar para atualizar o status do animal na fazenda de destino
void trocarAnimal(Animal* animal1, Animal* animal2);
int animalExiste(Animal* rebanho, int id_animal);
void liberarmemoriaAnimal(Animal *rebanho);
void contAnimaisSexo(Fazenda *fazenda);
void MostrarStatus(Fazenda *fazenda, int sts);
void mostrarAnimal(Animal *rebanho);
void mostrarTodosAnimais(Fazenda *fazenda);
float contArroba(Fazenda *fazenda);
