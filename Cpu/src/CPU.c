/*
 ============================================================================
 Name        : CPU.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
#include "CPUArranque.h"
#include "/home/utnso/workspace2/commonsPropias/src/sockets.h"


int main(void) {

	leerArchivoConfiguracion("configCPU");
	crearArchivoLog();

	int socketPlanificador = Conectar(IP_PLANIFICADOR, PUERTO_PLANIFICADOR);

	char* mensaje = Recibir(socketPlanificador);
	printf("Recibi un mensaje %s\n", mensaje);

	int socketMemoria = Conectar(IP_MEMORIA, PUERTO_MEMORIA);

	mensaje = Recibir(socketMemoria);
	printf("Recibi un mensaje %s\n", mensaje);

	char* comando;
	char* parametro;
	comando = Recibir(socketPlanificador);
	parametro = Recibir(socketPlanificador);
	printf("Recibi el siguiente comando %s %s\n", comando, parametro);

	Enviar(socketMemoria, comando);
	Enviar(socketMemoria, parametro);

	Desconectar(socketPlanificador);
	//Desconectar(socketMemoria);

	return EXIT_SUCCESS;
}




	//--Proceso CPU:
	//-Interpreta y ejecuta instruccion enviadas por el planificador (algunas con accesoa memoria).
	//-Multiples CPUs (configurables de antemano), necesidad de hilos.
	//-Recibe del planificador un proceso 'mProc' y ejecuta cada linea como una instruccion. Pienso que tambien recibe el Algoritmo a utilizar (hecho por un protocolo con el planificador).
	//-Uso de sleep (para que simule un tiempo de ejecucion)
	//-Relacion con Adm Memoria depende la instruccion, es cliente de adm memoria como de planificador.
	//-Retorno de datos al Planificador






