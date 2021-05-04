#include"Compra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"

/**
 * \brief 	Inicializa todos los elementos del array como vacios
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
 *  * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 */
int com_inicializarArray(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
		{
			respuesta = 0;
			for(i=0;i<limite;i++)
			{
				array[i].isEmpty = 1;
			}
		}
	return respuesta;
}

/**
 * \brief 	Guarda una Compra sin pedirle datos al usuario
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 * \param idCompra. Puntero a la variable donde se guarda el id disponible para ponerle a la Compra
 * \param idCliente. Puntero a la variable donde se guarda el id del cliente que hizo la compra
 * \param descripcion. Puntero a un array de caracteres que contiene la descripcion
 * \param direccion. Puntero a un array de caracteres que contiene la direccion
 * \param color. Puntero a un array de caracteres que contiene el color
 * \param cantidad. Cantidad de barbijos comprados
 * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 *
 */
int com_harcodeo(Compra* array,int limite, int* idCompra, int idCliente,char* descripcion, char* direccion, char* color, int cantidad)
{
	int respuesta = -1;
	int indice = -1;
	Compra bufferCompra;
	indice = com_getEmptyIndex(array, limite);
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCompra != NULL)
		{
			strncpy(bufferCompra.direccionDeEntrega,direccion,QTY_DIRECCIONDEENTREGA);
			strncpy(bufferCompra.color,color,QTY_COLOR);
			strncpy(bufferCompra.descripcion,descripcion,QTY_DESCRIPCION);
			bufferCompra.idCliente = idCliente;
			bufferCompra.idCompra = *idCompra;
			bufferCompra.cantidad = cantidad;
			bufferCompra.isEmpty = 0;
			bufferCompra.estado=0;
			respuesta = 0;
			array[indice] = bufferCompra;
			(*idCompra)++;


		}
	return respuesta;
}

/**
 * \brief 	Imprime todos las Compras del array
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 *  * \return Retorna 0 si se obtiene el nummero correctamente y -1 si ocurre algun error
 *
 */
int com_imprimirArray(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("\nIdCompra - Descripcion - Entre calles - Color  ");
		for(i=0;i<limite;i++)
			{
				com_imprimir(&array[i]);
			}
	}
		return respuesta;
}

/**
 * \brief 	Imprime todos las Compras del array que se encuentren impagas
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 *  * \return Retorna 0 si se obtiene el nummero correctamente y -1 si ocurre algun error
 *
 */
int com_imprimirComprasImpagas(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("\nIdCompra - Descripcion - Entre calles - Color - Cantidad ");
		for(i=0;i<limite;i++)
			{
				if(array[i].estado == 0 && array[i].isEmpty == 0)
				{
					com_imprimir(&array[i]);
				}
			}
	}
		return respuesta;
}

/**
 * \brief 	Imprime los datos de una Compra
 * \param pElemento. Puntero a una compra
 *  * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 *
 */
int com_imprimir(Compra* pElemento)
{
	int respuesta=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
		respuesta=0;
		printf("\nID: %d - %s - %s - %s - %d",pElemento->idCompra,pElemento->descripcion,pElemento->direccionDeEntrega,pElemento->color, pElemento->cantidad);
		}
	return respuesta;
}

/**
 * \brief 	Encuentra una posicion vacia en el array
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 *  * \return Retorna la posicion disopnible o -1 si ocurre algun error
 *
 */
int com_getEmptyIndex(Compra* array,int limite)
{
	int respuesta = -1;
	int i;
		if(array != NULL && limite > 0)
			{
				for(i=0;i<limite;i++)
				{
					if(array[i].isEmpty == 1)
					{
						respuesta = i;
						break;
					}
				}
			}
	return respuesta;
}
/**
 * \brief 	Pide ingresar datos de una Compra para luego buscar una posicion libre en el array y lo guarda ahi
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
  * \param idCliente. Variable donde se guarda el id del cliente que realizo la compra
 * \param idCompra. Puntero a la variable donde se guarda el id disponible para ponerle a la Compra
 *  * \return Retorna 0 si se carga la compra correctamente y -1 si ocurre algun error
 *
 */
int com_alta(Compra* array,int limite,int idCliente, int* idCompra)
{
	int respuesta = -1;
	Compra bufferCompra;
	int indiceCompra = -1;
	if(array != NULL && limite > 0 )
	{
		indiceCompra = com_getEmptyIndex(array,limite);
		if(indiceCompra < limite && indiceCompra >= 0 && idCompra != NULL)
		{
			if( aux_getString(bufferCompra.descripcion,QTY_DESCRIPCION,"\nIngrese descripcion: ", "\nError",2) ==0 &&
				aux_getString(bufferCompra.direccionDeEntrega,QTY_DIRECCIONDEENTREGA, "\nIngrese direccion: ","\nError",2 )==0 &&
				aux_getNumeroInt(&bufferCompra.cantidad,"\nIngrese la cantidad de barbijos: ","\nError. Reingrese",0,10000000,2) == 0  &&
				aux_getString(bufferCompra.color,QTY_COLOR, "\nColor?","\nError",2 )==0)
				{
					respuesta = 0;
					bufferCompra.idCliente = idCliente;
					bufferCompra.idCompra = *idCompra;
					bufferCompra.isEmpty = 0;
					bufferCompra.estado=0;
					array[indiceCompra] = bufferCompra;
					printf("\nCompra agregada correctamente con id: %d", (*idCompra));
					(*idCompra)++;
				}
		}
	}

	return respuesta;
}


/**
 * \brief 	Busca la posicion donde se encuentra una compra en el array
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
  * \param valorBuscado. Id de la compra a buscar.
 *  * \return Retorna la posicion de la compra en el array o -1 si ocurre algun error
 *
 */
int com_buscarId(Compra array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idCompra == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Imprime todas las compras realizadas por un cliente
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 * \param indice. id del cliente
 * \return Retorna 0 si imprime las compras correctamente y -1 si ocurre algun error
 *
 */
int com_ImprimirPorClienteId(Compra array[], int limite, int clienteId)
{
	int respuesta = -1;
	Compra bufferCompra;
	if(array != NULL && limite > 0 && clienteId >= 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == clienteId && array[i].isEmpty == 0)
			{
				bufferCompra = array[i];
				com_imprimir(&bufferCompra);
			}
		}
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Elimina todas las compras realizadas por un cliente
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 * \param indice. id del cliente
 * \return Retorna 0 si elimina las compras correctamente y -1 si ocurre algun error
 *
 */
int com_EliminarPorClienteId(Compra array[], int limite, int clienteId)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && clienteId >= 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == clienteId && array[i].isEmpty == 0)
			{
				array[i].isEmpty = 1;
			}
		}
		respuesta = 0;
	}
		return respuesta;
}

/**
 * \brief marca una compra como pagada
 * \param array. Puntero a al array de Compras
 * \param limite. Cantidad maxima de posiciones del array
 * \param posicion. Posicion de la compra en el array
 * \return Retorna 0 si marca la compra correctamente y -1 si ocurre algun error
 *
 */
int com_PagarCompra(Compra array[], int limite, int posicion)
{
	int respuesta = -1;
	int monto = 0;
	int accion = -1;
	if(array != NULL && limite > 0 && posicion >= 0)
	{
		if(	aux_getNumeroInt(&monto,"\nIngrese el monto de la compra: ","\nError. Reingrese",0,10000000,2) == 0 )
		{
			if(aux_getNumeroInt(&accion, "\nDesea guardar los cambios? 0= NO, 1=SI", "\nOpcion incorrecta. Reingrese", 0, 1, 2)== 0)
			{
				if(accion == 1)
				{
					array[posicion].precio = monto;
					array[posicion].estado = 1;
					respuesta = 0;
				}
			}
		}
	}
	return respuesta;
}

/**
 * \brief 	Elimina del array una Compra que no este paga
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
  * \param indice. Posicion del array a eliminar.
 *  * \return Retorna 0 si se elimina la compra correctamente y -1 si ocurre algun error
 *
 */

int com_CancelarCompra(Compra array[], int limite, int posicion)
{
	int respuesta = -1;
	int accion = -1;
		if(array != NULL && limite > 0 && posicion >= 0)
		{
			if(array[posicion].estado == 0)
			{
				if(aux_getNumeroInt(&accion, "\nDesea guardar los cambios? 0= NO, 1=SI", "\nOpcion incorrecta. Reingrese", 0, 1, 2)== 0)
				{
					if(accion == 1)
					{
						array[posicion].isEmpty = 1;
						respuesta = 0;
						printf("\nLos cambios se guardaron correctamente");
					}
				}
			}
		}
	return respuesta;
}



/**
 * \brief 	Cuenta e imprimer la cantidad de compras pendientes de pago
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
 * \return Retorna 0 los parametros son correctos y -1 si ocurre algun error
 *
 */

int com_ContarPendientes(Compra array[], int limite)
{
	int respuesta = -1;
	int contador = 0;
	if(array != NULL && limite > 0)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].estado == 0)
				{
					contador++;
				}
			}
			printf("\nHay un total de %d compras pendientes", contador);
		}
	return respuesta;
}

/**
 * \brief 	Busca e imprime la compra con el precio mas bajo por unidad
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
 * \return Retorna 0 si los parametros son correctos y -1 si ocurre algun error
 *
 */
int com_CompraConPrecioXunidadMasBajo(Compra array[], int limite)
{
	int respuesta = -1;
	int compraId = -1;
	float precio = -1;
	float precioAux;
	if(array != NULL && limite > 0)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].estado == 1)
				{
					precioAux = (float)array[i].precio / (float)array[i].cantidad;
					if(precio != -1)
					{
						if(precioAux < precio )
						{
							precio = precioAux;
							compraId = array[i].idCompra;
						}
					}
					else
					{
						precio = precioAux;
						compraId = array[i].idCompra;
					}

				}
			}
			if(compraId != -1)
			{
				printf("\n La compra con el precio por unidad mas bajo es la %d con un valor de %.2f por unidad", compraId, precio);
			}
			else
			{
				printf("\nNo hay compras abonadas");
			}
		}
	return respuesta;
}

/**
 * \brief 	Busca e imprime el color de barbijo mas pedido junto a la cantidad de compras donde lo piden
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
 * \return Retorna 0 si los parametros son correctos y -1 si ocurre algun error
 *
 */
int com_ColorMasPedido(Compra array[], int limite)
{
	int respuesta = -1;
	char colores[limite][QTY_COLOR];
	int flagEncontrado;
	int indiceColores = 1;
	char ColorMasPedido[QTY_COLOR];
	int auxCantidad = 0;
	int CantidadPedidos = 0;
	if(array != NULL && limite > 0)
			{
				respuesta = 0;
				strcpy(colores[0], array[0].color);
				for(int i=1;i<limite;i++)
				{
					if(array[i].isEmpty == 0)
					{
						flagEncontrado = 0;
						for(int j=0;i<=indiceColores;j++)
						{
							if(strcmp(colores[j],array[i].color) != 0)
							{
								flagEncontrado = 1;
							}
							break;
						}
						if(flagEncontrado == 1)
						{
							strcpy(colores[indiceColores], array[i].color);
							indiceColores++;
						}
					}
				}
				for(int i=0;i<indiceColores;i++)
				{
					if(com_ContarPorColor(array,limite, colores[i], &auxCantidad) == 0)
					{
						if(CantidadPedidos < auxCantidad )
						{
							CantidadPedidos = auxCantidad;
							strcpy(ColorMasPedido, colores[i]);
						}
					}
				}
				printf("\nEl color mas vendido es %s con un total de %d pedidos", ColorMasPedido,CantidadPedidos);

			}
	return respuesta;

}

/**
 * \brief 	Cuenta la cantidad de compras que tiene un color
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
 * \param color. Array de caracteres que contiene el color a buscar
 * \param cantidad. Puntero a la variable donde se guardará la cantidad de pedidos del color
 * \return Retorna 0 si los parametros son correctos y -1 si ocurre algun error
 *
 */
int com_ContarPorColor(Compra array[], int limite, char color[], int* cantidad)
{
	int respuesta = -1;
	int contador = 0;
		if(array != NULL && limite > 0 && color != NULL)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && strcmp(array[i].color, color) == 0)
				{
					contador++;
				}
			}
			*cantidad = contador;
		}
	return respuesta;
}


/**
 * \brief 	Cuenta la cantidad de compras pagadas que tiene un cliente
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
  * \param clienteId. Id del cliente a buscar
  * \param cantidad. Puntero a la variable donde se guardara la cantidad de compras del cliente
 *  * \return Retorna 0 si los parametros no son null y -1 si ocurre algun error
 *
 */

int com_ContarPagasPorClienteId(Compra array[], int limite, int clienteId, int* cantidad)
{
	int respuesta = -1;
	int contador = 0;
		if(array != NULL && limite > 0 && clienteId >= 0)
		{
			respuesta = 0;
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].idCliente == clienteId && array[i].estado == 1)
				{
					contador++;
				}
			}
			*cantidad = contador;
		}
	return respuesta;
}
/**
 * \brief 	Cuenta la cantidad de compras que tiene un cliente
 * \param array. Puntero al array de Compras
 * \param limite Cantidad maxima de posiciones del array
  * \param clienteId. Id del cliente a buscar
  * \param cantidad. Puntero a la variable donde se guardara la cantidad de compras del cliente
 *  * \return Retorna 0 si los parametros no son null y -1 si ocurre algun error
 *
 */

int com_ContarPorClienteId(Compra array[], int limite, int clienteId, int* cantidad, int estado)
{
	int respuesta = -1;
	int contador = 0;
	if(array != NULL && limite > 0 && clienteId >= 0)
	{
		respuesta = 0;
		if(estado == -1)
		{
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].idCliente == clienteId)
				{
					contador++;
				}
			}
		}
		else
		{
			for(int i=0;i<limite;i++)
			{
				if(array[i].isEmpty == 0 && array[i].idCliente == clienteId && array[i].estado == estado)
				{
					contador++;
				}
			}
		}

		*cantidad = contador;
	}
	return respuesta;
}

