#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Compra.h"
#include "auxiliar.h"
#include "ClienteCompra.h"


#define QTY_CLIENTES 100
#define QTY_COMPRAS 1000
int main(void) {
	setbuf(stdout,NULL);

		Cliente arrayCliente[QTY_CLIENTES];
		Compra arrayCompra[QTY_COMPRAS];

		int opcion;
		int idCliente;
		int auxiliarIndice;
		int auxiliarId;
		int idCompras;
		int auxiliarIndiceCompra;
		int posicion;





		if(cli_inicializarArray(arrayCliente,QTY_CLIENTES) == 0)// INICIALIZA EL ARRAY EN 0
		{
			printf("Array inicializado correctamente. \n\n");
		}
		if(com_inicializarArray(arrayCompra,QTY_COMPRAS) == 0)// INICIALIZA EL ARRAY EN 0
		{
			printf("Array inicializado correctamente. \n\n");
		}

		//ALTA FORZADA CLIENTE
		cli_altaForzadaArray(arrayCliente,QTY_CLIENTES,0,&idCliente,"Esteban ","Quito", "253954271022");
		cli_altaForzadaArray(arrayCliente,QTY_CLIENTES,1,&idCliente,"Armando","Lios", "2045265871");
		cli_altaForzadaArray(arrayCliente,QTY_CLIENTES,2,&idCliente,"TOMAS","RODRIGUEZ", "20342158261");

		//ALTA FORZADA COMPRA
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,0,&idCompras,1,"COMPRA 1","COLON/MORENO","VERDE", 10, 500);
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,1,&idCompras,1,"COMPRA 2","MORENO/DORREGO","AZUL", 20, 980);
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,2,&idCompras,2,"COMPRA 3","BELGRANO/ZAPIOLA","ROJO", 5, 300);
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,3,&idCompras,0,"COMPRA 4","PUCCINI/BRUZA","VIOLETA", 500, 10000);
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,4,&idCompras,0,"COMPRA 5","PUCCINI/BRUZA","VERDE", 600, 10000);
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,5,&idCompras,2,"COMPRA 6","PUCCINI/BRUZA","AZUL", 450, 10000);
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,6,&idCompras,0,"COMPRA 7","PUCCINI/BRUZA","AZUL", 15, 10000);

		do{
			if(!aux_getNumeroInt(	&opcion,
					"\n\n1.   Dar alta a  Cliente"
					"\n2.   Modificar datos de Cliente"
					"\n3.   Eliminar un Cliente"
					"\n4.   Realizar compra"
					"\n5.   Pagar Compra"
					"\n6.   Cancelar Compra"
					"\n7.   Imprimir Clientes"
					"\n8.   Informes"
					"\n9.   Salir\n\n",
					"\nError opcion invalida",1,9,2) )
				{
						switch(opcion)
						{
						case 1:
							auxiliarIndice = cli_getEmptyIndex(arrayCliente,QTY_CLIENTES);
							if(auxiliarIndice >= 0)
							{
								if(cli_alta(arrayCliente,QTY_CLIENTES,auxiliarIndice,&idCliente) == 0)
								{
									printf("\nCarga realizada con exito\n");
								}
							}else
							{
								printf("\nNO HAY MAS LUGAR");
							}
							break;
						case 2:
							cli_imprimirArray(arrayCliente,QTY_CLIENTES);
							if(aux_getNumeroInt(&auxiliarId,"\nIndique el ID del Cliente a modificar","\nID invalido. Reingrese",0,idCliente,0) == 0)
							{
								auxiliarIndice = cli_buscarId(arrayCliente,QTY_CLIENTES,auxiliarId);
								if(	auxiliarIndice >= 0 &&
									cli_modificarArray(arrayCliente,QTY_CLIENTES,auxiliarIndice) == 0)
										{
											printf("\nModificacion realizada con exito\n");
										}
							}
							break;
						case 3:
							cli_imprimirArray(arrayCliente,QTY_CLIENTES);
							if(aux_getNumeroInt(&auxiliarId,"\nIndique el ID del Cliente a eliminar","\nID invalido",0,idCliente-1,2)==0)
								{
									auxiliarIndice = cli_buscarId(arrayCliente,QTY_CLIENTES,auxiliarId);
									if(	auxiliarIndice >= 0 && CliCom_bajaCliente(arrayCliente,QTY_CLIENTES,auxiliarIndice,arrayCompra,QTY_COMPRAS)	== 0)
									{
										printf("\nBaja realizada con exito\n");
									}
									else
									{
										printf("\nHubo un error, pruebe de vuelta");
									}
							}
							break;
						case 4:
							auxiliarIndiceCompra = com_getEmptyIndex(arrayCompra,QTY_COMPRAS);
							if(auxiliarIndiceCompra >= 0)
							{
								cli_imprimirArray(arrayCliente,QTY_CLIENTES);
								if(	aux_getNumeroInt(&auxiliarId,"\nId Cliente: ","\nError. Reingrese",0,idCliente-1,2) == 0 )
								{
									posicion = cli_buscarId(arrayCliente,QTY_CLIENTES,auxiliarId);
									if(posicion != -1)
									{
										com_alta(arrayCompra,QTY_CLIENTES,auxiliarIndiceCompra,auxiliarId,&idCompras);
									}
									else
									{
										printf("\nEL ID NO EXISTE");
										break;
									}
								}
							}
							break;
						case 5:
							if(CliCom_PagarCompra(arrayCompra, QTY_COMPRAS, idCompras, arrayCliente, QTY_CLIENTES)!= 0)
							{
								printf("\nERROR");
							}
							break;
						case 6:
							if(CliCom_CancelarCompra(arrayCompra, QTY_COMPRAS, idCompras, arrayCliente, QTY_CLIENTES)!= 0)
							{
								printf("\nERROR");
							}
							break;
						case 7:
							if(CliCom_ImprimirClientesConCompras(arrayCompra, QTY_COMPRAS, idCompras, arrayCliente, QTY_CLIENTES)!= 0)
							{
								printf("\nERROR");
							}
							break;
						case 8:printf("¿Que informe desea realizar?");
							do{
								if(!aux_getNumeroInt(&opcion,
									"\n\n1.   Color de barbijo que se compro mas veces"
									"\n2.   Cantidad de compras pendientes"
									"\n3.   Compra con precio por unidad mas bajo"
									"\n4.   Salir\n\n",
									"\nOpcion Invalidad. Reingrese",1,4,2) )
									{
										switch(opcion)
										{
										case 1:
											if(com_ColorMasPedido(arrayCompra, QTY_COMPRAS) != 0)
											{
												printf("\nERROR");
											}
																	break;
										case 2:
											if(com_ContarPendientes(arrayCompra, QTY_COMPRAS) != 0)
											{
												printf("\nERROR");
											}
											break;
										case 3:
											if(com_CompraConPrecioXunidadMasBajo(arrayCompra, QTY_COMPRAS) != 0)
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
	return EXIT_SUCCESS;
}
