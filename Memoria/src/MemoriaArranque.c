/*
 * MemoriaArranque.c
 *
 *  Created on: 3/9/2015
 *      Author: utnso
 */
#include "MemoriaArranque.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <commons/config.h>
#include <commons/log.h>

int leerArchivoConfiguracion(char *ruta_archivo) {
	int devolver = 0;

	config = config_create(ruta_archivo);
	printf("Leyendo archivo de configuraciones: %s\n", ruta_archivo);

	PUERTO_ESCUCHA = config_get_int_value(config, "PUERTO_ESCUCHA");
	IP_SWAP = config_get_string_value(config, "IP_SWAP");
	PUERTO_SWAP = config_get_int_value(config, "PUERTO_SWAP");
	MAXIMO_MARCOS_POR_PROCESO=config_get_int_value(config,"MAXIMO_MARCOS_POR_PROCESO");
	CANTIDAD_MARCOS=config_get_int_value(config,"CANTIDAD_MARCOS");
	TAMANIO_MARCO=config_get_int_value(config,"TAMANIO_MARCOS");
	ENTRADAS_TLB=config_get_int_value(config,"ENTRADAS_TLB");
	TLB_HABILITADA=config_get_string_value(config,"TLB_HABILITADA");
	RETARDO=config_get_int_value(config,"RETARDO");

	printf("Puerto de la Memoria que escucha: %d\n", PUERTO_ESCUCHA);
	printf("IP del Swap: %s\n", IP_SWAP);
	printf("Puerto del Swap: %d\n", PUERTO_SWAP);
	printf("Cantidad maxima de marcos por proceso: %d\n", MAXIMO_MARCOS_POR_PROCESO);
	printf("Cantidad de Marcos: %d\n", CANTIDAD_MARCOS);
	printf("Tamanio de cada marco: %d\n", TAMANIO_MARCO);
	printf("Cantidad de entradas TLB: %d\n", ENTRADAS_TLB);
	printf("TLB habilitada: %s\n", TLB_HABILITADA);
	printf("Tiempo de retardo: %d\n", RETARDO);
	puts("Listo.\n");

	return devolver;
}

int crearArchivoLog() {
	int devolver = 0;

	remove("logsAdministradorDeMemoria");

	puts("Creando archivo de logueo...\n");

	logs = log_create("logsAdministradorDeMemoria", "AdministradorDeMemoriaLog", 0, LOG_LEVEL_TRACE);

	if (logs == NULL) {
		puts("No se pudo generar el archivo de logueo\n");
		return -1;
	}

	log_info(logs, "INICIALIZACION DEL ARCHIVO DE LOGUEO");

	puts("Listo.\n");

	return devolver;
}

