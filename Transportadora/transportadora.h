typedef struct transportadora Transportadora;
typedef struct endereco Endereco;
typedef struct fila Fila;


Transportadora *CriarListaEncadeada();
Transportadora *cadastroCliente(Transportadora *cliente);
Transportadora *buscarCliente(Transportadora *cliente);
Transportadora *excluirCliente(Transportadora *cliente);
Fila *criarFila();
void entregas(Transportadora *cliente, Fila *f);

void imprimirCliente(Transportadora *cliente); 