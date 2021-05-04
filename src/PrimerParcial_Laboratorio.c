#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Compra.h"
#include "auxiliar.h"
#include "ClienteCompra.h"


#define MAX_CLIENTES 100
#define MAX_COMPRAS 1000
int main(void) {
	setbuf(stdout,NULL);
	Cliente arrayCliente[MAX_CLIENTES];
	Compra arrayCompra[MAX_COMPRAS];
	int opcion;
	int idCliente = 0;
	int idCompras = 0;
	if(cli_inicializarArray(arrayCliente,MAX_CLIENTES) == 0 && com_inicializarArray(arrayCompra,MAX_COMPRAS) == 0)// INICIALIZA EL ARRAY EN 0
	{

		if(CliCom_harcodearDatosIniciales(arrayCliente,MAX_CLIENTES, &idCliente,arrayCompra, MAX_COMPRAS, &idCompras) == 0)
		{
			do{
				if(!aux_getNumeroInt(	&opcion,
						"\n\n1. Dar de alta Cliente"
						"\n2.   Modificar datos de un Cliente"
						"\n3.   Eliminar un Cliente"
						"\n4.   Realizar una Compra"
						"\n5.   Pagar una Compra"
						"\n6.   Cancelar una Compra"
						"\n7.   Imprimir Clientes con cantidad de Compras"
						"\n8.   Informes"
						"\n9.   Salir\n\n",
						"\nError, opcion no valida. Reingrese",1,9,2) )
				{
					switch(opcion)
					{
					case 1:
						if(cli_alta(arrayCliente,MAX_CLIENTES,&idCliente) != 0)
						{
							printf("\nERROR");
						}

						break;
					case 2:
						if(cli_modificarArray(arrayCliente,MAX_CLIENTES,idCliente) != 0)
						{
							printf("\nERROR");
						}
						break;
					case 3:
						if(CliCom_bajaCliente(arrayCliente,MAX_CLIENTES,idCliente,arrayCompra,MAX_COMPRAS)	!= 0)
						{
							printf("\ERROR");
						}
						break;
					case 4:
						if(Clicom_AltaCompra(arrayCliente,MAX_CLIENTES, idCliente,arrayCompra, MAX_COMPRAS, &idCompras)!=0)
						{
							printf("\nERROR");
						}
						break;
					case 5:
						if(CliCom_PagarCompra(arrayCompra, MAX_COMPRAS, idCompras, arrayCliente, MAX_CLIENTES)!= 0)
						{
							printf("\nERROR");
						}
						break;
					case 6:
						if(CliCom_CancelarCompra(arrayCompra, MAX_COMPRAS, idCompras, arrayCliente, MAX_CLIENTES)!= 0)
						{
							printf("\nERROR");
						}
						break;
					case 7:
						if(CliCom_ImprimirClientesConCompras(arrayCompra, MAX_COMPRAS, idCompras, arrayCliente, MAX_CLIENTES)!= 0)
						{
							printf("\nERROR");
						}
						break;
					case 8:printf("Seleccione el informe a imprimir:");
						do
						{
							if(!aux_getNumeroInt(&opcion,
								"\n\n1. Color de barbijo que se compro mas veces"
								"\n2.   Cantidad de compras pendientes"
								"\n3.   Compra con precio por unidad mas bajo"
								"\n4.   Salir\n\n",
								"\nOError, opcion no valida. Reingrese",1,4,2) )
							{
								switch(opcion)
								{
								case 1:
									if(com_ColorMasPedido(arrayCompra, MAX_COMPRAS) != 0)
									{
										printf("\nERROR");
									}
															break;
								case 2:
									if(com_ContarPendientes(arrayCompra, MAX_COMPRAS) != 0)
									{
										printf("\nERROR");
									}
									break;
								case 3:
									if(com_CompraConPrecioXunidadMasBajo(arrayCompra, MAX_COMPRAS) != 0)
									{
										printf("\nERROR");
									}
									break;
								}
							}
						}while(opcion != 4);
						break;
					}
				}
			}while(opcion != 9);
		}else
		{
			printf("\nError en la carga de datos iniciales");
		}
	}
	else
	{
		printf("\nError al inicial el programa");
	}
	return EXIT_SUCCESS;
}
