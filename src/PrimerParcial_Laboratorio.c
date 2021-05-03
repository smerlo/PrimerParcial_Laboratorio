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
		int precio;




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
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,0,&idCompras,1,"COMPRA 1","COLON/MORENO","VERDE");
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,1,&idCompras,1,"COMPRA 2","MORENO/DORREGO","AZUL");
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,2,&idCompras,2,"COMPRA 3","BELGRANO/ZAPIOLA","ROJO");
		com_altaForzadaArray(arrayCompra,QTY_COMPRAS,3,&idCompras,0,"COMPRA 4","PUCCINI/BRUZA","VIOLETA");

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
										com_alta(arrayCompra,QTY_CLIENTES,auxiliarIndiceCompra,auxiliarId,&idCompras,precio);
									}
									else
									{
										printf("\nEL ID NO EXISTE");
										break;
									}
								}
							}
							break;
						case 5: //com_imprimirArray(arrayCompra,QTY_COMPRAS);
							if(CliCom_PagarCompra(arrayCompra, QTY_COMPRAS, idCompras, arrayCliente, QTY_CLIENTES)!= 0)
							{
								printf("\nERROR");
							}
	;
													break;
						case 6: printf("ingreso opcion 6");
													break;
						case 7: cli_imprimirArray(arrayCliente,QTY_CLIENTES);
													break;
						case 8:printf("¿Que informe desea realizar?");
							do{
							if(!aux_getNumeroInt(&opcion,
									"\n\n1.   Color de barbijo que se compro mas veces"
									"\n2.   Cantidad de compras pendientes"
									"\n3.   Compra con precio por unidad mas bajo"
									"\n4.   Salir\n\n",
									"\nError opcion invalida",1,4,2) )
									{
										switch(opcion)
										{
										case 1: printf("ingreso opcion 1");
																	break;
										case 2: printf("ingreso opcion 2");
																	break;
										case 3: printf("ingreso opcion 3");
																	break;
										}
									}
								}while(opcion != 4);
																	break;
						case 9: printf("ingreso opcion 9");
													break;
								}
				}
			    	}while(opcion != 9);
	return EXIT_SUCCESS;
}
