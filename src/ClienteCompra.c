#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "Cliente.h"
#include "Compra.h"


int CliCom_bajaCliente(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra)
{
	int respuesta = -1;
	int accion = -1;
	if(arrayCliente != NULL && limiteCliente > 0 && indiceCliente < limiteCliente && indiceCliente >= 0 && arrayCliente[indiceCliente].isEmpty == 0
			&&arrayCompra != NULL)
	{
		if(com_ImprimirPorClienteId(arrayCompra,limiteCompra,indiceCliente) == 0)
		{
			if(aux_getNumeroInt(&accion, "\nDesea eliminar al cliente y sus compras? 0= NO, 1=SI", "\nOpcion incorrecta. Reingrese", 0, 1, 2)== 0)
			{
				if(accion == 1)
				{
					if( cli_EliminarPorClienteId(arrayCliente,limiteCliente, indiceCliente) == 0 && com_EliminarPorClienteId(arrayCompra,limiteCliente,indiceCliente)== 0)
					{
						respuesta = 0;
					}
				}
			}
		}
	}
	return respuesta;
}

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
