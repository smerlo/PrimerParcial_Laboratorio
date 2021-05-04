#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "Cliente.h"
#include "Compra.h"


/**
 * \brief Harcodea Clientes y compras al iniciar el programa
 * \param arrayCliente. Puntero a al array de Clientes
 * \param limiteClientes. Cantidad maxima de posiciones del array
 * \param idCliente. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \param arrayCompra. Puntero a al array de Clientes
 * \param limiteCompras. Cantidad maxima de posiciones del array
 * \param idCompra. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \return Retorna 0 si el valor de los parametros es correcto y -1 si ocurre algun error
 *
 */
int CliCom_harcodearDatosIniciales(Cliente arrayCliente[], int limiteClientes, int* idCliente, Compra arrayCompra[], int limiteCompras, int* idCompra)
{
	int respuesta = -1;
	if(arrayCliente != NULL && limiteClientes > 0 && arrayCompra != NULL && limiteCompras > 0)
	{
		cli_harcodeo(arrayCliente,limiteClientes, idCliente,"Santiago","Merlo", "20361711725");
		cli_harcodeo(arrayCliente,limiteClientes, idCliente,"Martin","Perez","20155647895");
		cli_harcodeo(arrayCliente,limiteClientes, idCliente,"Jose","Gonzalez","20113569515");

		com_harcodeo(arrayCompra,limiteCompras, idCompra,0,"Esta es la primer compra","Alsina 653 ","VIOLETA", 500);
		com_harcodeo(arrayCompra,limiteCompras, idCompra,0,"Otra Compra","Alsina 653 ","ROJO", 200);
		com_harcodeo(arrayCompra,limiteCompras, idCompra,1,"Esta es tercer compra","Moreno 456 3F ","AZUL", 1500);
		com_harcodeo(arrayCompra,limiteCompras, idCompra,2,"Cuarta compra","Lavalle 987 ","ROJO", 3500);
		com_harcodeo(arrayCompra,limiteCompras, idCompra,1,"Quinta compra","Moreno 456 3F ","AMARILLO", 700);
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Da de alta una compra, pidiendo antes el id del cliente de la misma
 * \param arrayCliente. Puntero a al array de Clientes
 * \param limiteClientes. Cantidad maxima de posiciones del array
 * \param idCliente. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \param arrayCompra. Puntero a al array de Clientes
 * \param limiteCompras. Cantidad maxima de posiciones del array
 * \param idCompra. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \return Retorna 0 si la compra se agrega y -1 si ocurre algun error
 *
 */
int Clicom_AltaCompra(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra, int* indiceCompras)
{
	int respuesta = -1;
	int idCliente = -1;
	int indiceCli = -1;
	if(arrayCliente != NULL && limiteCliente > 0 )
	{
		cli_imprimirArray(arrayCliente,limiteCliente);
		if(	aux_getNumeroInt(&idCliente,"\nId Cliente: ","\nError. Reingrese",0,indiceCliente-1,2) == 0 )
		{
			indiceCli = cli_buscarId(arrayCliente,limiteCliente,idCliente);
			if(indiceCli != -1)
			{
				com_alta(arrayCompra,limiteCompra,idCliente,indiceCompras);
				respuesta = 0;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Elimina un cliente con todas sus compras
 * \param arrayCliente. Puntero a al array de Clientes
 * \param limiteClientes. Cantidad maxima de posiciones del array
 * \param idCliente. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \param arrayCompra. Puntero a al array de Clientes
 * \param limiteCompras. Cantidad maxima de posiciones del array
 * \param idCompra. Puntero a la variable donde se guarda el id disponible para ponerle al cliente
 * \return Retorna 0 si la eliminacion es y -1 si ocurre algun error
 *
 */
int CliCom_bajaCliente(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra)
{
	int respuesta = -1;
	int accion = -1;
	int auxclienteId = -1;
	int indice = -1;
	if(arrayCliente != NULL && limiteCliente > 0 )
	{
		cli_imprimirArray(arrayCliente,limiteCliente);
		if(aux_getNumeroInt(&auxclienteId,"\nIndique el ID del Cliente a eliminar","\nID invalido",0,indiceCliente-1,2)==0)
		{
			indice = cli_buscarId(arrayCliente,limiteCliente,auxclienteId);
			if(indice < limiteCliente && indice >= 0 && arrayCliente[indice].isEmpty == 0 && arrayCompra != NULL)
			{
				if(com_ImprimirPorClienteId(arrayCompra,limiteCompra,indice) == 0)
				{
					if(aux_getNumeroInt(&accion, "\nDesea eliminar al cliente y sus compras? 0= NO, 1=SI", "\nOpcion incorrecta. Reingrese", 0, 1, 2)== 0)
					{
						if(accion == 1)
						{
							if( cli_EliminarPorClienteId(arrayCliente,limiteCliente, indice) == 0 && com_EliminarPorClienteId(arrayCompra,limiteCliente,indice)== 0)
							{
								respuesta = 0;
								printf("\nBaja realizada con exito\n");
							}
						}
					}
				}
			}
		}
	}

	return respuesta;
}

/**
 * \brief Imprime las compras impagas y permite marcar una como paga
 * \param arrayCliente. Puntero a al array de Clientes
 * \param limiteClientes. Cantidad maxima de posiciones del array
 * \param arrayCompra. Puntero a al array de Clientes
 * \param limiteCompras. Cantidad maxima de posiciones del array
 * \param indiceCompras. Variable donde se guarda el id disponible

 * \return Retorna 0 si la compra se paga correctamente y -1 si ocurre algun error
 *
 */
int CliCom_PagarCompra(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente)
{
	int respuesta = -1;
	int compraId = -1;
	int posicion;
	if(com_imprimirComprasImpagas(compraArray,limiteCompras)== 0)
	{
		if(	aux_getNumeroInt(&compraId,"\nIngrese el id de la compra: ","\nError. Reingrese",0,indiceCompras-1,2) == 0 )
			{
			posicion = com_buscarId(compraArray, limiteCompras, compraId);
				if(posicion != -1)
				{
					if(cli_imprimirPorId(clienteArray,limiteCliente, compraArray[posicion].idCliente)== 0 && com_PagarCompra(compraArray, limiteCompras, posicion) == 0)
					{
						printf("\nCambios guardados correctamente");
					}
				}
				respuesta = 0;
		}
	}
	return respuesta;
}

/**
 * \brief Imprime las compras impagas y permite eliminar una que no este paga
 * \param arrayCliente. Puntero a al array de Clientes
 * \param limiteClientes. Cantidad maxima de posiciones del array
 * \param arrayCompra. Puntero a al array de Clientes
 * \param limiteCompras. Cantidad maxima de posiciones del array
 * \param indiceCompras. Variable donde se guarda el id disponible

 * \return Retorna 0 si la compra se cancela correctamente y -1 si ocurre algun error
 *
 */
int CliCom_CancelarCompra(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente)
{
	int respuesta = -1;
	int compraId = -1;
	int posicion;
	if(com_imprimirArray(compraArray,limiteCompras)== 0)
	{
		if(	aux_getNumeroInt(&compraId,"\nIngrese el id de la compra: ","\nError. Reingrese",0,indiceCompras-1,2) == 0 )
			{
			posicion = com_buscarId(compraArray, limiteCompras, compraId);
				if(posicion != -1)
				{
					if(compraArray[posicion].estado != 1)
					{
						if( cli_imprimirPorId(clienteArray,limiteCliente, compraArray[posicion].idCliente)== 0 && com_CancelarCompra(compraArray, limiteCompras, posicion) == 0)
						{

						}
					}
					else
					{
						printf("\nNo se puede cancelar una compra ya abonada");
					}
				}
				respuesta = 0;
		}
	}
	return respuesta;
}

/**
 * \brief Imprime todos los clientes junto con sus compras
 * \param arrayCliente. Puntero a al array de Clientes
 * \param limiteClientes. Cantidad maxima de posiciones del array
 * \param arrayCompra. Puntero a al array de Clientes
 * \param limiteCompras. Cantidad maxima de posiciones del array
 * \param indiceCompras. Variable donde se guarda el id disponible

 * \return Retorna 0 si el listado se imprime correctamente y -1 si ocurre algun error
 *
 */
int CliCom_ImprimirClientesConCompras(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente)
{
	int respuesta = -1;
	int cantidadCompras;
	if(clienteArray != NULL && limiteCliente > 0 && compraArray != NULL && limiteCompras > 0)
		{
			printf("IdCliente - Nombre - Apellido - Cuit - Compras");
			for(int i=0;i<limiteCliente;i++)
			{
				if(clienteArray[i].isEmpty == 0 && com_ContarPorClienteId(compraArray,limiteCompras, clienteArray[i].id, &cantidadCompras) == 0)
				{
					cli_ImprimirConCompras(&clienteArray[i], cantidadCompras);
				}
			}
			respuesta = 0;
		}
	return respuesta;
}
