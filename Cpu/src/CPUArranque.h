#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sockets.h>
#include <commons/config.h>
#include <commons/log.h>


#ifndef CPUARRANQUE_H_
#define CPUARRANQUE_H_

int leerArchivoConfiguracion(char *ruta_archivo);

int crearArchivoLog();

//recursos
t_config* config;
t_log* logs;

//variables config
int PUERTO_PLANIFICADOR, PUERTO_MEMORIA, CANTIDAD_HILOS, RETARDO;
char* IP_PLANIFICADOR;
char* IP_MEMORIA;

#endif /* CPUARRANQUE_H_ */
