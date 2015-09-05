/*
 * PlanificadorArranque.c
 *
 *  Created on: 2/9/2015
 *      Author: utnso
 */

#include "PlanificadorArranque.h"
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

	//printf("Tiene Algoritmo: %d \n", config_has_property(config, "ALGORITMO_PLANIF"));
	PUERTO_ESCUCHA = config_get_int_value(config, "PUERTO_ESCUCHA");
	ALGORITMO_PLANIF = config_get_string_value(config, "ALGORITMO_PLANIFICACION");
	QUANTUM = config_get_int_value(config, "QUANTUM");

	printf("Puerto de escucha de conexiones: %d\n", PUERTO_ESCUCHA);
	printf("Algoritmo de planificacion a utilizar: %s\n", ALGORITMO_PLANIF);
	printf("Quantum máximo a utilizar en los algoritmos: %d\n", QUANTUM);

	puts("Listo.\n");

	return devolver;
}

int crearArchivoLog() {
	int devolver = 0;

	remove("logsPlanificador");

	puts("Creando archivo de logueo...\n");

	logs = log_create("logsPlanificador", "PlanificadorLog", 0, LOG_LEVEL_TRACE);

	if (logs == NULL) {
		puts("No se pudo generar el archivo de logueo\n");
		return -1;
	}

	log_info(logs, "INICIALIZACION DEL ARCHIVO DE LOGUEO");

	puts("Listo.\n");

	return devolver;
}
