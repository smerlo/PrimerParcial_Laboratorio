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
	int cantidad;
	int isEmpty;
	char descripcion[QTY_DESCRIPCION];
	int estado;
	int precio;

}Compra;

int com_inicializarArray(Compra* array,int limite);
int com_harcodeo(Compra* array,int limite, int* idCompra, int idCliente,char* descripcion, char* direccion, char* color, int cantidad);
int com_imprimirArray(Compra* array,int limite);
int com_imprimirComprasImpagas(Compra* array,int limite);
int com_imprimir(Compra* pElemento);
int com_alta(Compra* array,int limite,int idCliente, int* idCompra);
int com_getEmptyIndex(Compra* array,int limite);
int com_buscarId(Compra array[], int limite, int valorBuscado);
int com_ImprimirPorClienteId(Compra array[], int limite, int clienteId);
int com_EliminarPorClienteId(Compra array[], int limite, int clienteId);
int com_PagarCompra(Compra array[], int limite, int posicion);
int com_CancelarCompra(Compra array[], int limite, int posicion);
int com_ContarPorClienteId(Compra array[], int limite, int clienteId, int* cantidad);
int com_ContarPendientes(Compra array[], int limite);
int com_CompraConPrecioXunidadMasBajo(Compra array[], int limite);
int com_ColorMasPedido(Compra array[], int limite);
int com_ContarPorColor(Compra array[], int limite, char color[], int* cantidad);
#endif /* COMPRA_H_ */
