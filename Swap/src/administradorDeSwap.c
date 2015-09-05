/*
 ============================================================================
 Name        : administradorDeSwap.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <commons/config.h>
#include "swapArranque.h"
#include "/home/utnso/workspace2/commonsPropias/src/sockets.h"

int main(void) {

	leerArchivoConfiguracion("configSwap");
	crearArchivoLog();

	int listenningSocket = Escuchar(PUERTO_ESCUCHA);
	int socketMemoria = Aceptar(listenningSocket);
	Enviar(socketMemoria, "BIENVENIDO A SWAPILANDIA");

	char* comando;
	char* parametro;
	comando = Recibir(socketMemoria);
	parametro = Recibir(socketMemoria);
	printf("Recibi el siguiente comando %s %s\n", comando, parametro);

	Desconectar(listenningSocket);
	Desconectar(socketMemoria);

	return EXIT_SUCCESS;
}
