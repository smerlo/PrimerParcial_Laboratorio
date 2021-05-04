#ifndef CLIENTE_H_
#define CLIENTE_H_
#define NOMBRE_LEN 50
#define APELLIDO_LEN 50



typedef struct{
	char nombre [NOMBRE_LEN];
	char apellido [APELLIDO_LEN];
	char Cuit[11];
	int id;
	int isEmpty;
}Cliente;


int cli_inicializarArray(Cliente* array,int limite);
int cli_alta(Cliente* array,int limite, int* id);
int cli_imprimir(Cliente* pElemento);
int cli_imprimirArray(Cliente* array,int limite);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_harcodeo(Cliente* array,int limite, int* id,char* nombre,char* apellido,char* cuit);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_EliminarPorClienteId(Cliente* array,int limite, int indice);
int cli_imprimirPorId(Cliente* array,int limite, int indice);
int cli_ImprimirConCompras(Cliente* pElemento, int compras);

#endif /* CLIENTE_H_ */
