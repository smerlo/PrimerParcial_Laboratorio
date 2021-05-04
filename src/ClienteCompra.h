#ifndef CLIENTECOMPRA_H_
#define CLIENTECOMPRA_H_

int CliCom_harcodearDatosIniciales(Cliente arrayCliente[], int limiteClientes, int* idCliente, Compra arrayCompra[], int limiteCompras, int* idCompra);
int Clicom_AltaCompra(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra, int* indiceCompras);
int CliCom_bajaCliente(Cliente* arrayCliente,int limiteCliente, int indiceCliente, Compra* arrayCompra, int limiteCompra);
int CliCom_PagarCompra(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente);
int CliCom_CancelarCompra(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente);
int CliCom_ImprimirClientesConCompras(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente);
int CliCom_ImprimirClientesConMasComprasPorEstado(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente, int estado);
int CliCom_ImprimirClientesConComprasPendientes(Compra compraArray[], int limiteCompras,int indiceCompras, Cliente clienteArray[], int limiteCliente);
#endif /* CLIENTECOMPRA_H_ */
