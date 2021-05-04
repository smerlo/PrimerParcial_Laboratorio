#include"cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"

/**
 * \brief 	Inicializa todos los elementos del array como vacios
 * \param array. Puntero al array de Clientes
 * \param limite Cantidad maxima de posiciones del array
 *  * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 */
int cli_inicializarArray(Cliente* array,int limite)
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
 * \brief 	Pide ingresar datos de un cliente, busca una posicion libre en el array y lo guarda ahi
 * \param array. Puntero al array de Clientes
 * \param limite Cantidad maxima de posiciones del array
 * \param id. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 *  * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 *
 */
int cli_alta(Cliente* array,int limite, int* id)
{
	int respuesta = -1;
	int indice = -1;
	Cliente bufferCliente;
	if(array != NULL && limite > 0)
	{
		indice = cli_getEmptyIndex(array,limite);
		if(limite > 0 && indice < limite && indice >= 0 && id != NULL)
		{
			if(	aux_getString(bufferCliente.nombre,NOMBRE_LEN,"\nIngrese el nombre del cliente: \n","\nERROR\n",2) == 0 &&
				aux_getString(bufferCliente.apellido,APELLIDO_LEN,"\nIngrese el apellido del cliente: \n","\nERROR\n",2) == 0 &&
				aux_getStringNum(bufferCliente.Cuit,12,"\nIngrese el cuit del cliente:  \n","\nERROR. El cuit solo puede ser numerico y de 11 digitos\n",2) == 0)
			{
				respuesta = 0;
				bufferCliente.id = *id;
				bufferCliente.isEmpty = 0;
				array[indice] = bufferCliente;
				printf("\nCarga realizada con exito con id: %d",*id);
				(*id)++;

			}
		}
		else
		{
			respuesta = 0;
			printf("El listado de clientes esta lleno");
		}
	}
	return respuesta;
}
/**
 * \brief 	Imprime todos los datos de un cliente
 * \param pElemento. Puntero a un cliente
 *  * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 *
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\n %d - %s - %s - %s ",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->Cuit);
		}
	return retorno;
}
/**
 * \brief 	Imprime todos los datos de un cliente junto a la cantidad de compras que posee
 * \param pElemento. Puntero a un cliente
 * \param compras. Numero de compras del cliente
 *  * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 *
 */
int cli_ImprimirConCompras(Cliente* pElemento, int compras)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\n %d - %s - %s - %s - %d ",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->Cuit, compras);
		}
	return retorno;
}
/**
 * \brief 	Imprime todos los clientes del array
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 *  * \return Retorna 0 si se obtiene el nummero correctamente y -1 si ocurre algun error
 *
 */
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		printf("IdCliente - Nombre - Apellido - Cuit");
			for(i=0;i<limite;i++)
			{
					cli_imprimir(&array[i]);
			}
	}
	return respuesta;
}

/**
 * \brief 	Encuentra una posicion vacia en el array
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 *  * \return Retorna la posicion disopnible o -1 si ocurre algun error
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite)
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
 * \brief 	Guarda un cliente sin pedirle datos al usuario
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 * \param id. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \param nombre. Puntero a un array de caracteres que contiene el nombre
 * \param apellido. Puntero a un array de caracteres que contiene el apellido
 * \param cuit. Puntero a un array de caracteres que contiene el cuit
 * \return Retorna 0 si se obtiene el numero correctamente y -1 si ocurre algun error
 *
 */
int cli_harcodeo(Cliente* array,int limite, int* id,char* nombre,char* apellido,char* cuit)
{
	int respuesta = -1;
	int indice = -1;
	Cliente bufferCliente;
	indice = cli_getEmptyIndex(array,limite);
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferCliente.nombre,nombre,NOMBRE_LEN);
			strncpy(bufferCliente.apellido,apellido,APELLIDO_LEN);
			strncpy (bufferCliente.Cuit,cuit,12);
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
	}
	return respuesta;
}
/**
 * \brief 	Busca la posicion de un cliente dentro del array usando el id del mismo
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 * \param valorBuscado. Id del cliente a buscar
 * \return Retorna la posicion del array donde se encuentra el cliente o -1 si ocurre algun error
 *
 */
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado && array[i].isEmpty == 0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Modifica los datos de un cliente
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 * \param clienteId. Id del cliente a modificar
 * \return Retorna 0 si semodifica el cliente correctamente y -1 si ocurre algun error
 *
 */
int cli_modificarArray(Cliente* array,int limite, int clienteId)
{
	int respuesta = -1;
	int indice = -1;
	int auxclienteId = -1;
	Cliente bufferCliente;
	if(array != NULL && limite > 0 )
	{
		cli_imprimirArray(array,limite);
		if(aux_getNumeroInt(&auxclienteId,"\nIndique el ID del Cliente a modificar\n","\nID invalido. Reingrese\n",0,clienteId,0) == 0)
		{
			indice = cli_buscarId(array,limite,auxclienteId);
			if(	indice < limite && indice >= 0 && array[indice].isEmpty == 0)
			{
				if(	aux_getString(bufferCliente.nombre,NOMBRE_LEN,"\nIngrese el nombre del cliente: \n","\nERROR\n",2) == 0 &&
					aux_getString(bufferCliente.apellido,APELLIDO_LEN,"\nIngrese el apellido del cliente\n","\nERROR\n",2) == 0 &&
					aux_getString(bufferCliente.Cuit,12,"\nIngrese el cuit del cliente: \n","\nERROR. El cuit solo puede ser numerico y de 11 digitos\n",2) == 0)
				{
				respuesta = 0;
				bufferCliente.id = array[indice].id;
				bufferCliente.isEmpty = 0;
				array[indice] = bufferCliente;
				printf("\nModificación realizada con exito");
				}
			}
		}
	}
	return respuesta;
}
/**
 * \brief Elimina un cliente del array
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 * \param indice. Posicion del cliente en el array
 * \return Retorna 0 si elimina el cliente correctamente y -1 si ocurre algun error
 *
 */
int cli_EliminarPorClienteId(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}
/**
 * \brief Imprime todos los datos de un cliente
 * \param array. Puntero a al array de Clientes
 * \param limite. Cantidad maxima de posiciones del array
 * \param indice. id del cliente
 * \return Retorna 0 si imprime el cliente correctamente y -1 si ocurre algun error
 *
 */

int cli_imprimirPorId(Cliente* array,int limite, int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(array[i].id == indice)
			{
				printf("\nId - Nombre - Apellido - Cuit");
				printf("\n %d - %s - %s - %s ",array[i].id,array[i].nombre,array[i].apellido,array[i].Cuit);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
