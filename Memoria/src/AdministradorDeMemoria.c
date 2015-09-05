/*
 * AdministradorDeMemoria.c
 *
 *  Created on: 3/9/2015
 *      Author: utnso
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <commons/config.h>
#include <commons/log.h>
#include "MemoriaArranque.h"
#include "/home/utnso/workspace2/commonsPropias/src/sockets.h"

int main(void) {

	leerArchivoConfiguracion("configMemoria");
	crearArchivoLog();

	int socketSwap = Conectar(IP_SWAP, PUERTO_SWAP);
	char* mensaje = Recibir(socketSwap);
	printf("Recibi un mensaje %s\n", mensaje);

	int listenningSocket = Escuchar(PUERTO_ESCUCHA);
	int socketCPU = Aceptar(listenningSocket);
	Enviar(socketCPU, "BIENVENIDO A LA MEMORIA");

	char* comando;
	char* parametro;
	comando = Recibir(socketCPU);
	parametro = Recibir(socketCPU);
	printf("Recibi el siguiente comando %s %s\n", comando, parametro);

	Enviar(socketSwap, comando);
	Enviar(socketSwap, parametro);


	Desconectar(listenningSocket);
	Desconectar(socketCPU);
	Desconectar(socketSwap);

	return EXIT_SUCCESS;
}

