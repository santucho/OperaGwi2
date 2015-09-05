#include "CPUArranque.h"
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

	IP_PLANIFICADOR = config_get_string_value(config, "IP_PLANIFICADOR");
	PUERTO_PLANIFICADOR = config_get_int_value(config, "PUERTO_PLANIFICADOR");
	IP_MEMORIA = config_get_string_value(config, "IP_MEMORIA");
	PUERTO_MEMORIA = config_get_int_value(config, "PUERTO_MEMORIA");
	CANTIDAD_HILOS = config_get_int_value(config, "CANTIDAD_HILOS");
	RETARDO = config_get_int_value(config, "RETARDO");

	printf("IP del Planificador: %s\n", IP_PLANIFICADOR);
	printf("Puerto del Planificador: %d\n", PUERTO_PLANIFICADOR);
	printf("IP de la Memoria: %s\n", IP_MEMORIA);
	printf("Puerto de la Memoria: %d\n", PUERTO_MEMORIA);
	printf("Cantidad de Hilos de CPU a utilizar: %d\n", CANTIDAD_HILOS);
	printf("Tiempo de retardo: %d\n", RETARDO);
	puts("Listo.\n");

	return devolver;
}

int crearArchivoLog() {
	int devolver = 0;

	remove("logsPlanificador");

	puts("Creando archivo de logueo...\n");

	logs = log_create("logsCPU", "CPULog", 0, LOG_LEVEL_TRACE);

	if (logs == NULL) {
		puts("No se pudo generar el archivo de logueo\n");
		return -1;
	}

	log_info(logs, "INICIALIZACION DEL ARCHIVO DE LOGUEO");

	puts("Listo.\n");

	return devolver;
}
