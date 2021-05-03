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
					if(com_EliminarPorClienteId(arrayCompra,limiteCliente,indiceCliente)== 0 && cli_EliminarPorClienteId(arrayCliente,limiteCliente, indiceCliente) == 0)
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
