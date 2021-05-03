#ifndef COMPRA_H_
#define COMPRA_H_
#define QTY_DIRECCIONDEENTREGA 64
#define QTY_COLOR 32
#define QTY_DESCRIPCION 128

typedef struct{
	int idCliente;
	char direccionDeEntrega[QTY_DIRECCIONDEENTREGA];
	char color [QTY_COLOR];
	int idCompra;
	int isEmpty;
	char descripcion[QTY_DESCRIPCION];
	int estado;
	int precio;

}Compra;

int com_inicializarArray(Compra* array,int limite);
int com_altaForzadaArray(Compra* array,int limite, int indice, int* idCompra, int idCliente,char* descripcion, char* direccion, char* color);
int com_imprimirArray(Compra* array,int limite);
int com_imprimirComprasImpagas(Compra* array,int limite);
int com_imprimir(Compra* pElemento);
int com_alta(Compra* array,int limite, int indice,int idCliente, int* idCompra , int* precio);
int com_getEmptyIndex(Compra* array,int limite);
int com_baja(Compra* array,int limite, int indice);
int com_buscarId(Compra array[], int limite, int valorBuscado);
int com_ImprimirPorClienteId(Compra array[], int limite, int clienteId);
int com_EliminarPorClienteId(Compra array[], int limite, int clienteId);
int com_PagarCompra(Compra array[], int limite, int posicion);
#endif /* COMPRA_H_ */