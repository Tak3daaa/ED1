typedef struct animal Animal; 

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho);
Animal *buscarAnimal(Animal *rebanho);
Animal *removerAnimal(Fazenda *fazenda, int id_animal);
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAnimal(Fazenda *fazenda, int id_animal); 

int animalExiste(Animal* rebanho, int id_animal);
void liberarmemoriaAnimal(Animal *rebanho);
void contAnimaisSexo(Fazenda *fazenda);
void MostrarStatus(Fazenda *fazenda, int sts);
void mostrarAnimal(Animal *rebanho);
void mostrarTodosAnimais(Fazenda *fazenda);
float contArroba(Fazenda *fazenda);
